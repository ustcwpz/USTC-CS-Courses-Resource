
#include "c1recognizer/syntax_tree.h"

using namespace c1_recognizer::syntax_tree;

void assembly::accept(syntax_tree_visitor &visitor) { visitor.visit(*this); }
void func_def_syntax::accept(syntax_tree_visitor &visitor) { visitor.visit(*this); }
void cond_syntax::accept(syntax_tree_visitor &visitor) { visitor.visit(*this); }
void binop_expr_syntax::accept(syntax_tree_visitor &visitor) { visitor.visit(*this); }
void unaryop_expr_syntax::accept(syntax_tree_visitor &visitor) { visitor.visit(*this); }
void lval_syntax::accept(syntax_tree_visitor &visitor) { visitor.visit(*this); }
void literal_syntax::accept(syntax_tree_visitor &visitor) { visitor.visit(*this); }
void var_def_stmt_syntax::accept(syntax_tree_visitor &visitor) { visitor.visit(*this); }
void assign_stmt_syntax::accept(syntax_tree_visitor &visitor) { visitor.visit(*this); }
void func_call_stmt_syntax::accept(syntax_tree_visitor &visitor) { visitor.visit(*this); }
void block_syntax::accept(syntax_tree_visitor &visitor) { visitor.visit(*this); }
void if_stmt_syntax::accept(syntax_tree_visitor &visitor) { visitor.visit(*this); }
void while_stmt_syntax::accept(syntax_tree_visitor &visitor) { visitor.visit(*this); }
void empty_stmt_syntax::accept(syntax_tree_visitor &visitor) { visitor.visit(*this); }
