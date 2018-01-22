
#ifndef _C1_SYNTAX_TREE_BUILDER_H_
#define _C1_SYNTAX_TREE_BUILDER_H_

#include "c1recognizer/syntax_tree.h"
#include "C1ParserBaseVisitor.h"
#include <c1recognizer/error_reporter.h>

namespace c1_recognizer
{
namespace syntax_tree
{
class syntax_tree_builder : public C1ParserBaseVisitor
{
  public:
    syntax_tree_builder(error_reporter &_err);

    virtual antlrcpp::Any visitCompilationUnit(C1Parser::CompilationUnitContext *ctx) override;
    virtual antlrcpp::Any visitDecl(C1Parser::DeclContext *ctx) override;
    virtual antlrcpp::Any visitConstdecl(C1Parser::ConstdeclContext *ctx) override;
    virtual antlrcpp::Any visitConstdef(C1Parser::ConstdefContext *ctx) override;
    virtual antlrcpp::Any visitVardecl(C1Parser::VardeclContext *ctx) override;
    virtual antlrcpp::Any visitVardef(C1Parser::VardefContext *ctx) override;
    virtual antlrcpp::Any visitFuncdef(C1Parser::FuncdefContext *ctx) override;
    virtual antlrcpp::Any visitBlock(C1Parser::BlockContext *ctx) override;
    virtual antlrcpp::Any visitStmt(C1Parser::StmtContext *ctx) override;
    virtual antlrcpp::Any visitLval(C1Parser::LvalContext *ctx) override;
    virtual antlrcpp::Any visitCond(C1Parser::CondContext *ctx) override;
    virtual antlrcpp::Any visitExp(C1Parser::ExpContext *ctx) override;

    ptr<syntax_tree_node> operator()(antlr4::tree::ParseTree *ctx);

  private:
    error_reporter &err;
};
}
}

#endif
