
#ifndef _C1_TEST_SYNTAX_TREE_SERIALIZER_
#define _C1_TEST_SYNTAX_TREE_SERIALIZER_

#include <c1recognizer/syntax_tree.h>

namespace c1_recognizer
{
namespace syntax_tree
{

std::string relop_name_map[] = {"equal", "non_equal", "less", "less_equal", "greater", "greater_equal"};
std::string binop_name_map[] = {"plus", "minus", "multiply", "divide", "modulo"};
std::string unaryop_name_map[] = {"plus", "minus"};

template <typename Writer>
class syntax_tree_serializer : public syntax_tree_visitor
{
  public:
    syntax_tree_serializer(Writer &w) : writer(w) {}

    void serialize(syntax_tree_node &tree)
    {
        tree.accept(*this);
    }

    virtual void visit(assembly &tree) override
    {
        writer.StartObject();
        writer.Key("type");
        writer.String("assembly");
        writer.Key("line");
        writer.Int(tree.line);
        writer.Key("pos");
        writer.Int(tree.pos);
        writer.Key("global_defs");
        writer.StartArray();
        for (auto def : tree.global_defs)
            def->accept(*this);
        writer.EndArray();
        writer.EndObject();
    }

    virtual void visit(func_def_syntax &tree) override
    {
        writer.StartObject();
        writer.Key("type");
        writer.String("func_def_syntax");
        writer.Key("line");
        writer.Int(tree.line);
        writer.Key("pos");
        writer.Int(tree.pos);
        writer.Key("name");
        writer.String(tree.name.c_str());
        writer.Key("body");
        tree.body->accept(*this);
        writer.EndObject();
    }

    virtual void visit(cond_syntax &tree) override
    {
        writer.StartObject();
        writer.Key("type");
        writer.String("cond_syntax");
        writer.Key("line");
        writer.Int(tree.line);
        writer.Key("pos");
        writer.Int(tree.pos);
        writer.Key("op");
        writer.String(relop_name_map[int(tree.op)].c_str());
        writer.Key("lhs");
        tree.lhs->accept(*this);
        writer.Key("rhs");
        tree.rhs->accept(*this);
        writer.EndObject();
    }

    virtual void visit(binop_expr_syntax &tree) override
    {
        writer.StartObject();
        writer.Key("type");
        writer.String("binop_expr_syntax");
        writer.Key("line");
        writer.Int(tree.line);
        writer.Key("pos");
        writer.Int(tree.pos);
        writer.Key("op");
        writer.String(binop_name_map[int(tree.op)].c_str());
        writer.Key("lhs");
        tree.lhs->accept(*this);
        writer.Key("rhs");
        tree.rhs->accept(*this);
        writer.EndObject();
    }

    virtual void visit(unaryop_expr_syntax &tree) override
    {
        writer.StartObject();
        writer.Key("type");
        writer.String("unaryop_expr_syntax");
        writer.Key("line");
        writer.Int(tree.line);
        writer.Key("pos");
        writer.Int(tree.pos);
        writer.Key("op");
        writer.String(unaryop_name_map[int(tree.op)].c_str());
        writer.Key("rhs");
        tree.rhs->accept(*this);
        writer.EndObject();
    }

    virtual void visit(lval_syntax &tree) override
    {
        writer.StartObject();
        writer.Key("type");
        writer.String("lval_syntax");
        writer.Key("line");
        writer.Int(tree.line);
        writer.Key("pos");
        writer.Int(tree.pos);
        writer.Key("name");
        writer.String(tree.name.c_str());
        if (tree.array_index)
        {
            writer.Key("array_index");
            tree.array_index->accept(*this);
        }
        writer.EndObject();
    }

    virtual void visit(literal_syntax &tree) override
    {
        writer.StartObject();
        writer.Key("type");
        writer.String("literal_syntax");
        writer.Key("line");
        writer.Int(tree.line);
        writer.Key("pos");
        writer.Int(tree.pos);
        writer.Key("value");
        writer.Int(tree.number);
        writer.EndObject();
    }

    virtual void visit(var_def_stmt_syntax &tree) override
    {
        writer.StartObject();
        writer.Key("type");
        writer.String("var_def_stmt_syntax");
        writer.Key("line");
        writer.Int(tree.line);
        writer.Key("pos");
        writer.Int(tree.pos);
        writer.Key("is_const");
        writer.Bool(tree.is_constant);
        writer.Key("name");
        writer.String(tree.name.c_str());
        if (tree.array_length)
        {
            writer.Key("array_length");
            tree.array_length->accept(*this);
            writer.Key("array_initializers");
            writer.StartArray();
            for (auto init : tree.initializers)
                init->accept(*this);
            writer.EndArray();
        }
        else if (tree.initializers.size() > 0)
        {
            writer.Key("vardef_initializer");
            tree.initializers[0]->accept(*this);
        }
        writer.EndObject();
    }

    virtual void visit(assign_stmt_syntax &tree) override
    {
        writer.StartObject();
        writer.Key("type");
        writer.String("assign_stmt_syntax");
        writer.Key("line");
        writer.Int(tree.line);
        writer.Key("pos");
        writer.Int(tree.pos);
        writer.Key("target");
        tree.target->accept(*this);
        writer.Key("value");
        tree.value->accept(*this);
        writer.EndObject();
    }

    virtual void visit(func_call_stmt_syntax &tree) override
    {
        writer.StartObject();
        writer.Key("type");
        writer.String("func_call_stmt_syntax");
        writer.Key("line");
        writer.Int(tree.line);
        writer.Key("pos");
        writer.Int(tree.pos);
        writer.Key("name");
        writer.String(tree.name.c_str());
        writer.EndObject();
    }

    virtual void visit(block_syntax &tree) override
    {
        writer.StartObject();
        writer.Key("type");
        writer.String("block_syntax");
        writer.Key("line");
        writer.Int(tree.line);
        writer.Key("pos");
        writer.Int(tree.pos);
        writer.Key("body");
        writer.StartArray();
        for (auto stmt : tree.body)
            stmt->accept(*this);
        writer.EndArray();
        writer.EndObject();
    }

    virtual void visit(if_stmt_syntax &tree) override
    {
        writer.StartObject();
        writer.Key("type");
        writer.String("if_stmt_syntax");
        writer.Key("line");
        writer.Int(tree.line);
        writer.Key("pos");
        writer.Int(tree.pos);
        writer.Key("pred");
        tree.pred->accept(*this);
        writer.Key("thenbody");
        tree.then_body->accept(*this);
        if (tree.else_body)
        {
            writer.Key("elsebody");
            tree.else_body->accept(*this);
        }
        writer.EndObject();
    }

    virtual void visit(while_stmt_syntax &tree) override
    {
        writer.StartObject();
        writer.Key("type");
        writer.String("while_stmt_syntax");
        writer.Key("line");
        writer.Int(tree.line);
        writer.Key("pos");
        writer.Int(tree.pos);
        writer.Key("pred");
        tree.pred->accept(*this);
        writer.Key("body");
        tree.body->accept(*this);
        writer.EndObject();
    }

    virtual void visit(empty_stmt_syntax &tree) override
    {
        writer.StartObject();
        writer.Key("type");
        writer.String("empty_stmt_syntax");
        writer.Key("line");
        writer.Int(tree.line);
        writer.Key("pos");
        writer.Int(tree.pos);
        writer.EndObject();
    }

  private:
    Writer &writer;
};
}
}

#endif
