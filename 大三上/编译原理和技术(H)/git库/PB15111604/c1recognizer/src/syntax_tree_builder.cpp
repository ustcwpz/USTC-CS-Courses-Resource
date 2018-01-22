 
#include "syntax_tree_builder.h"
#include <memory>

using namespace c1_recognizer;
using namespace c1_recognizer::syntax_tree;

syntax_tree_builder::syntax_tree_builder(error_reporter &_err) : err(_err) {}
 
antlrcpp::Any syntax_tree_builder::visitCompilationUnit(C1Parser::CompilationUnitContext *ctx)
{
    auto result = new assembly;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    auto children = ctx->children;
    for (auto &child : children) {
    // std::cout<<__LINE__<<std::endl;
        if (antlrcpp::is<C1Parser::DeclContext *>(child)){
    // std::cout<<__LINE__<<std::endl;
            auto tmp = visit(child).as<std::vector<var_def_stmt_syntax *> >();
            for(int i = 0; i < tmp.size(); i++){
                result->global_defs.emplace_back(tmp[i]);
            }
        }
        else if(antlrcpp::is<C1Parser::FuncdefContext *>(child)){
    // std::cout<<__LINE__<<std::endl;
            result->global_defs.emplace_back(visit(child).as<func_def_syntax *>());
        }
    }
    return result;
}

antlrcpp::Any syntax_tree_builder::visitDecl(C1Parser::DeclContext *ctx)
{
    if(auto c = ctx->constdecl()){
        return visit(c);
    }
    if(auto v = ctx->vardecl()){
        return visit(v);
    }
}

antlrcpp::Any syntax_tree_builder::visitConstdecl(C1Parser::ConstdeclContext *ctx)
{
    auto children = ctx->constdef();
    std::vector<var_def_stmt_syntax *> result;
    for(auto &child:children){
        result.emplace_back(visit(child).as<var_def_stmt_syntax *>());
    }
    // warning - if loss of 'int'
    if(not ctx->Int()){
        auto c = ctx->Const();
        err.warn(c->getSymbol()->getLine(), c->getSymbol()->getCharPositionInLine()+5, "Missing type:int -- implicit type declaration");
    }
    return result;
}

antlrcpp::Any syntax_tree_builder::visitConstdef(C1Parser::ConstdefContext *ctx)
{
    auto expressions = ctx->exp();
    auto result = new var_def_stmt_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->is_constant = true;
    result->name = ctx->Identifier()->getSymbol()->getText();

    //[]
    if(ctx->LeftBracket()){
        auto num_comma = ctx->Comma().size();
        auto num_exp = expressions.size();
        if(num_comma + 1 == num_exp){
            //Id[]={1,2}
            auto len = new literal_syntax;
            len->line = ctx->getStart()->getLine();
            len->pos = ctx->RightBracket()->getSymbol()->getCharPositionInLine();
            len->number = num_exp;
            result->array_length.reset(static_cast<expr_syntax *>(len));
            for(int i = 0; i < num_exp; i++){
                result->initializers.emplace_back(visit(expressions[i]).as<expr_syntax *>());
            }
        }
        else{
            //Id[2]={1,2}
            result->array_length.reset(visit(expressions[0]).as<expr_syntax *>());
            for(int i = 1; i < num_exp; i++){
                result->initializers.emplace_back(visit(expressions[i]).as<expr_syntax *>());
            }
        }
        return result;
    }

    //no []
    result->array_length.reset();
    result->initializers.emplace_back(visit(expressions[0]).as<expr_syntax *>());
    return result;
}

antlrcpp::Any syntax_tree_builder::visitVardecl(C1Parser::VardeclContext *ctx)
{
    auto children = ctx->vardef();
    std::vector<var_def_stmt_syntax *> result;
    for(auto &child:children){
        result.push_back(visit(child).as<var_def_stmt_syntax *>());
    }
    return result;
}

antlrcpp::Any syntax_tree_builder::visitVardef(C1Parser::VardefContext *ctx)
{
    auto expressions = ctx->exp();
    auto result = new var_def_stmt_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->is_constant = false;
    result->name = ctx->Identifier()->getSymbol()->getText();
        
    //Id
    if(expressions.size() == 0){
        result->array_length.reset();
        return result;
    }

    //Id=1
    if(not ctx->LeftBracket() && ctx->Assign()){
        result->array_length.reset();
        result->initializers.emplace_back(visit(expressions[0]).as<expr_syntax *>());
        return result;
    }

    //Id[1]
    if(ctx->LeftBracket() && not ctx->Assign()){
        result->array_length.reset(visit(expressions[0]).as<expr_syntax *>());
        return result;
    }

    //Id[2] = {1,2}, Id[] = {1,2}
    auto len_exp = expressions.size();
    auto len_comma = ctx->Comma().size();

    //Id[] = {1,2}
    if(len_comma + 1 == len_exp){
        auto len = new literal_syntax;
        len->line = ctx->Identifier()->getSymbol()->getLine();
        len->pos = ctx->RightBracket()->getSymbol()->getCharPositionInLine();
        len->number = len_exp;
        result->array_length.reset(static_cast<expr_syntax *>(len));
        for(int i = 0; i < len_exp; i++){
            result->initializers.emplace_back(visit(expressions[i]).as<expr_syntax *>());
        }
        return result;
    }
    //Id[2] = {1,2}
    result->array_length.reset(visit(expressions[0]).as<expr_syntax *>());
    for(int i = 1; i < len_exp; i++){
        result->initializers.emplace_back(visit(expressions[i]).as<expr_syntax *>());
    }
    return result;
}

antlrcpp::Any syntax_tree_builder::visitFuncdef(C1Parser::FuncdefContext *ctx)
{
    auto result = new func_def_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine(); 
    result->name = ctx->Identifier()->getSymbol()->getText();
    result->body.reset(visit(ctx->block()).as<block_syntax *>());
    return result;
}

antlrcpp::Any syntax_tree_builder::visitBlock(C1Parser::BlockContext *ctx)
{
    auto result = new block_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    auto children = ctx->children;

    for (auto &child : children) {
            // std::cout<<"1!"<<std::endl;
        if (antlrcpp::is<C1Parser::DeclContext *>(child)){
            auto tmp = visit(child).as<std::vector<var_def_stmt_syntax *> >();
            for(int i = 0; i < tmp.size(); i++){
                result->body.emplace_back(tmp[i]);

            }
        }
        else if(antlrcpp::is<C1Parser::StmtContext *>(child)){
            // std::cout<<"here!!!!"<<std::endl;
            result->body.emplace_back(visit(child).as<stmt_syntax *>());
        }
    }

    return static_cast<block_syntax *>(result);
}

antlrcpp::Any syntax_tree_builder::visitStmt(C1Parser::StmtContext *ctx)
{
    if(ctx->Assign()){
        auto result = new assign_stmt_syntax;
        result->line = ctx->getStart()->getLine();

        result->pos = ctx->getStart()->getCharPositionInLine();
        result->target.reset(visit(ctx->lval()).as<lval_syntax *>());
        result->value.reset(visit(ctx->exp()).as<lval_syntax *>());

        return static_cast<stmt_syntax *>(result);
    }
    if(ctx->If()){
        auto result = new if_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        
        result->pred.reset(visit(ctx->cond()).as<cond_syntax *>());
        result->then_body.reset(visit(ctx->stmt()[0]).as<stmt_syntax *>());

        if(ctx->Else()){
            result->else_body.reset(visit(ctx->stmt()[1]).as<stmt_syntax *>());
        }
        else{
            result->else_body.reset(static_cast<stmt_syntax *>(nullptr));
        }

        return static_cast<stmt_syntax *>(result);
    }
    if(ctx->While()){
        auto result = new while_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->pred.reset(visit(ctx->cond()).as<cond_syntax *>());
        result->body.reset(visit(ctx->stmt()[0]).as<stmt_syntax *>());
        return static_cast<stmt_syntax *>(result);
    }
    if(ctx->Identifier()){
        // function_call
        auto result = new func_call_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        
        result->name = ctx->Identifier()->getSymbol()->getText();
        return static_cast<stmt_syntax *>(result);

    }
    if(ctx->block()){
        return visit(ctx->block()).as<stmt_syntax *>();
        // might be wrong.
    }
    if(ctx->SemiColon()){
        auto result = new empty_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        return static_cast<stmt_syntax *>(result);
    }
}

antlrcpp::Any syntax_tree_builder::visitLval(C1Parser::LvalContext *ctx)
{
    
    auto result = new lval_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->name = ctx->Identifier()->getSymbol()->getText();
    // std::cout << "here!" <<std::endl;
    // std::cout << result->name <<std::endl;

    if(ctx->LeftBracket()){
        auto expressions = ctx->exp();
        result->array_index.reset(visit(expressions).as<expr_syntax *>());
        // result->lhs.reset(visit(expressions[0]).as<expr_syntax *>());
    }
    else{
        result->array_index.reset(static_cast<expr_syntax *>(nullptr));
    }
    return static_cast<expr_syntax *>(result);
}

antlrcpp::Any syntax_tree_builder::visitCond(C1Parser::CondContext *ctx)
{
    auto expressions = ctx->exp();

    auto result = new cond_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    if(ctx->Equal())
        result->op = relop::equal;
    if(ctx->NonEqual())
        result->op = relop::non_equal;
    if(ctx->Less())
        result->op = relop::less;
    if(ctx->LessEqual())
        result->op = relop::less_equal;
    if(ctx->Greater())
        result->op = relop::greater;
    if(ctx->GreaterEqual())
        result->op = relop::greater_equal;
    // std::cout << expressions.size() <<std::endl << std::endl << std::endl;
 
    result->lhs.reset(visit(expressions[0]).as<expr_syntax *>());
    result->rhs.reset(visit(expressions[1]).as<expr_syntax *>());
    
    return result;

}

// Returns antlrcpp::Any, which is constructable from any type.
// However, you should be sure you use the same type for packing and depacking the `Any` object.
// Or a std::bad_cast exception will rise.
// This function always returns an `Any` object containing a `expr_syntax *`.
antlrcpp::Any syntax_tree_builder::visitExp(C1Parser::ExpContext *ctx)
{
    // Get all sub-contexts of type `exp`.
    auto expressions = ctx->exp();
    // Two sub-expressions presented: this indicates it's a expression of binary operator, aka `binop`.
    if (expressions.size() == 2)
    {
        auto result = new binop_expr_syntax;
        // Set line and pos.
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        // visit(some context) is equivalent to calling corresponding visit method; dispatching is done automatically
        // by ANTLR4 runtime. For this case, it's equivalent to visitExp(expressions[0]).
        // Use reset to set a new pointer to a std::shared_ptr object. DO NOT use assignment; it won't work.
        // Use `.as<Type>()' to get value from antlrcpp::Any object; notice that this Type must match the type used in
        // constructing the Any object, which is constructed from (usually pointer to some derived class of
        // syntax_node, in this case) returning value of the visit call.
        result->lhs.reset(visit(expressions[0]).as<expr_syntax *>());
        // Check if each token exists.
        // Returnd value of the calling will be nullptr (aka NULL in C) if it isn't there; otherwise non-null pointer.
        if (ctx->Plus())
            result->op = binop::plus;
        if (ctx->Minus())
            result->op = binop::minus;
        if (ctx->Multiply())
            result->op = binop::multiply;
        if (ctx->Divide())
            result->op = binop::divide;
        if (ctx->Modulo())
            result->op = binop::modulo;
        result->rhs.reset(visit(expressions[1]).as<expr_syntax *>());
        return static_cast<expr_syntax *>(result);
    }
    // Otherwise, if `+` or `-` presented, it'll be a `unaryop_expr_syntax`.
    if (ctx->Plus() || ctx->Minus())
    {
        auto result = new unaryop_expr_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        if (ctx->Plus())
            result->op = unaryop::plus;
        if (ctx->Minus())
            result->op = unaryop::minus;
        result->rhs.reset(visit(expressions[0]).as<expr_syntax *>());
        return static_cast<expr_syntax *>(result);
    }
    // In the case that `(` exists as a child, this is an expression like `'(' expressions[0] ')'`.
    if (ctx->LeftParen())
        return visit(expressions[0]); // Any already holds expr_syntax* here, no need for dispatch and re-patch with casting.
    // If `Number` exists as a child, we can say it's a literal integer expression.
    if (auto number = ctx->Number())
    {
        auto result = new literal_syntax;
        result->line = number->getSymbol()->getLine();
        result->pos = number->getSymbol()->getCharPositionInLine();
        auto text = number->getSymbol()->getText();
        if (text[0] == '0' && text[1] == 'x')              // Hexadecimal
            result->number = std::stoi(text, nullptr, 16); // std::stoi will eat '0x'
        else                                               // Decimal
            result->number = std::stoi(text, nullptr, 10);
        return static_cast<expr_syntax *>(result);
    }
    if(auto lval = ctx->lval()){
        return visit(lval);
    }
}

ptr<syntax_tree_node> syntax_tree_builder::operator()(antlr4::tree::ParseTree *ctx)
{
    auto result = visit(ctx);
    if (result.is<syntax_tree_node *>())
        return ptr<syntax_tree_node>(result.as<syntax_tree_node *>());
    if (result.is<assembly *>())
        return ptr<syntax_tree_node>(result.as<assembly *>());
    if (result.is<global_def_syntax *>())
        return ptr<syntax_tree_node>(result.as<global_def_syntax *>());
    if (result.is<func_def_syntax *>())
        return ptr<syntax_tree_node>(result.as<func_def_syntax *>());
    if (result.is<cond_syntax *>())
        return ptr<syntax_tree_node>(result.as<cond_syntax *>());
    if (result.is<expr_syntax *>())
        return ptr<syntax_tree_node>(result.as<expr_syntax *>());
    if (result.is<binop_expr_syntax *>())
        return ptr<syntax_tree_node>(result.as<binop_expr_syntax *>());
    if (result.is<unaryop_expr_syntax *>())
        return ptr<syntax_tree_node>(result.as<unaryop_expr_syntax *>());
    if (result.is<lval_syntax *>())
        return ptr<syntax_tree_node>(result.as<lval_syntax *>());
    if (result.is<literal_syntax *>())
        return ptr<syntax_tree_node>(result.as<literal_syntax *>());
    if (result.is<stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<stmt_syntax *>());
    if (result.is<var_def_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<var_def_stmt_syntax *>());
    if (result.is<assign_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<assign_stmt_syntax *>());
    if (result.is<func_call_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<func_call_stmt_syntax *>());
    if (result.is<block_syntax *>())
        return ptr<syntax_tree_node>(result.as<block_syntax *>());
    if (result.is<if_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<if_stmt_syntax *>());
    if (result.is<while_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<while_stmt_syntax *>());
    return nullptr;
}

