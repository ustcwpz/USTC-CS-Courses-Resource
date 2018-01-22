
#ifndef _C1_ASSEMBLY_BUILDER_H_
#define _C1_ASSEMBLY_BUILDER_H_

#include <deque>
#include <unordered_map>
#include <string>
#include <tuple>

#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>

#include <c1recognizer/error_reporter.h>
#include <c1recognizer/syntax_tree.h>

#include "runtime.h"

class assembly_builder : public c1_recognizer::syntax_tree::syntax_tree_visitor
{
    virtual void visit(c1_recognizer::syntax_tree::assembly &node) override;
    virtual void visit(c1_recognizer::syntax_tree::func_def_syntax &node) override;
    virtual void visit(c1_recognizer::syntax_tree::cond_syntax &node) override;
    virtual void visit(c1_recognizer::syntax_tree::binop_expr_syntax &node) override;
    virtual void visit(c1_recognizer::syntax_tree::unaryop_expr_syntax &node) override;
    virtual void visit(c1_recognizer::syntax_tree::lval_syntax &node) override;
    virtual void visit(c1_recognizer::syntax_tree::literal_syntax &node) override;
    virtual void visit(c1_recognizer::syntax_tree::var_def_stmt_syntax &node) override;
    virtual void visit(c1_recognizer::syntax_tree::assign_stmt_syntax &node) override;
    virtual void visit(c1_recognizer::syntax_tree::func_call_stmt_syntax &node) override;
    virtual void visit(c1_recognizer::syntax_tree::block_syntax &node) override;
    virtual void visit(c1_recognizer::syntax_tree::if_stmt_syntax &node) override;
    virtual void visit(c1_recognizer::syntax_tree::while_stmt_syntax &node) override;
    virtual void visit(c1_recognizer::syntax_tree::empty_stmt_syntax &node) override;

    llvm::LLVMContext &context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<runtime_info> runtime;

    llvm::Value *value_result;
    int const_result;

    llvm::Function *current_function;
    int bb_count;

    bool lval_as_rval;
    bool in_global;
    bool constexpr_expected;

    c1_recognizer::error_reporter &err;
    bool error_flag;

  public:
    assembly_builder(llvm::LLVMContext &ctx, c1_recognizer::error_reporter &error_stream)
        : context(ctx), builder(ctx), err(error_stream) {}

    void build(std::string name, std::shared_ptr<c1_recognizer::syntax_tree::syntax_tree_node> tree)
    {
        // Initialize environment.
        module = std::make_unique<llvm::Module>(name, context);
        runtime = std::make_unique<runtime_info>(module.get());

        enter_scope();
        for (auto t : runtime->get_language_symbols())
        {
            llvm::GlobalValue *val;
            std::string name;
            bool is_function;
            bool is_const;
            bool is_array;
            std::tie(name, val, is_function, is_const, is_array) = t;
            if (is_function)
                functions[name] = static_cast<llvm::Function *>(val);
            else
                declare_variable(name, val, is_const, is_array);
        }

        lval_as_rval = true;
        in_global = true;
        constexpr_expected = false;
        error_flag = false;
        // Start building by starting iterate over the syntax tree.
        tree->accept(*this);
        // Finish by clear IRBuilder's insertion point and moving away built module.
        builder.ClearInsertionPoint();
        exit_scope();
        if (error_flag)
        {
            module.release();
            runtime.release();
        }
    }

    std::unique_ptr<llvm::Module> get_module() { return std::move(module); }
    std::unique_ptr<runtime_info> get_runtime_info() { return std::move(runtime); }

  private:
    void enter_scope() { variables.emplace_front(); }

    void exit_scope() { variables.pop_front(); }

    std::tuple<llvm::Value *, bool, bool> lookup_variable(std::string name)
    {
        for (auto m : variables)
            if (m.count(name))
                return m[name];
        return std::make_tuple((llvm::Value *)nullptr, false, false);
    }

    bool declare_variable(std::string name, llvm::Value *var_ptr, bool is_const, bool is_array)
    {
        if (variables.front().count(name))
            return false;
        variables.front()[name] = std::make_tuple(var_ptr, is_const, is_array);
        return true;
    }

    std::deque<std::unordered_map<std::string, std::tuple<llvm::Value *, bool, bool>>> variables;

    std::unordered_map<std::string, llvm::Function *> functions;
};

#endif
