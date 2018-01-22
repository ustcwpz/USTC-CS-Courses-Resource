
#include "assembly_builder.h"

#include <vector>
#define ConstNum(n) ConstantInt::get(context, APInt(32, n))
using namespace llvm;
using namespace c1_recognizer::syntax_tree;

// finish.
void assembly_builder::visit(assembly &node)
{
	ptr_list<global_def_syntax> children = node.global_defs;
	for (auto &child : children) {
		value_result = ConstNum(0);
		lval_as_rval = true;
		constexpr_expected = false;
		in_global = true;
		child->accept(*this);
	}
}

// finish.
void assembly_builder::visit(func_def_syntax &node)
{
	in_global = false;
	
	// check if multiple definition.
	if (functions.count(node.name)) {
		err.error(node.line, node.pos, "Function '" + node.name + "' multiply defined. Skipping.");
		error_flag = true;
		return;
	}
	
	FunctionType *FT = FunctionType::get(Type::getVoidTy(context), {}, false);
	current_function = Function::Create(FT, GlobalValue::LinkageTypes::ExternalLinkage, node.name, module.get());
	functions.emplace(node.name, current_function);

	auto enterB = BasicBlock::Create(context, "Enter", current_function);

	builder.SetInsertPoint(enterB);
	node.body->accept(*this);

	builder.CreateRetVoid();
}

// finish.
void assembly_builder::visit(cond_syntax &node)
{
	Value *tmp_lhs, *tmp_rhs;
	node.lhs->accept(*this);
	tmp_lhs = value_result;
	node.rhs->accept(*this);
	tmp_rhs = value_result;

	if (tmp_lhs->getType() != tmp_rhs->getType()) {
		std::cout << __LINE__ << ": type not equal!" << "\n";
	}
	if (node.op == relop::equal) {
		value_result = builder.CreateICmpEQ(tmp_lhs, tmp_rhs);
	}
	else if (node.op == relop::greater) {
		value_result = builder.CreateICmpSGT(tmp_lhs, tmp_rhs);
	}
	else if (node.op == relop::greater_equal) {
		value_result = builder.CreateICmpSGE(tmp_lhs, tmp_rhs);
	}
	else if(node.op == relop::less) {
		value_result = builder.CreateICmpSLT(tmp_lhs, tmp_rhs);
	}
	else if(node.op == relop::less_equal) {
		value_result = builder.CreateICmpSLE(tmp_lhs, tmp_rhs);
	}
	else if(node.op == relop::non_equal) {
		value_result = builder.CreateICmpNE(tmp_lhs, tmp_rhs);
	}
}

// finish.
void assembly_builder::visit(binop_expr_syntax &node)
{
	if (constexpr_expected == false) {
		// value_result;
		Value *tmp_lhs, *tmp_rhs;
		node.lhs->accept(*this);
		if (value_result == nullptr) {
			return;
		}
		tmp_lhs = value_result;
		node.rhs->accept(*this);
		if (value_result == nullptr) {
			return;
		}
		tmp_rhs = value_result;

		if (node.op == binop::plus) {
			value_result = builder.CreateAdd(tmp_lhs, tmp_rhs);
		}
		else if (node.op == binop::minus) {
			value_result = builder.CreateSub(tmp_lhs, tmp_rhs);
		}
		else if (node.op == binop::multiply) {
			value_result = builder.CreateMul(tmp_lhs, tmp_rhs);
		}
		else if (node.op == binop::divide) {
			value_result = builder.CreateSDiv(tmp_lhs, tmp_rhs);
		}
		else if (node.op == binop::modulo) {
			value_result = builder.CreateSRem(tmp_lhs, tmp_rhs);
		}
	}
	else {
		// contexpr
		int tmp_lhs, tmp_rhs;
		node.lhs->accept(*this);
		if (value_result == nullptr) {
			return;
		}
		tmp_lhs = const_result;
		node.rhs->accept(*this);
		if (value_result == nullptr) {
			return;
		}
		tmp_rhs = const_result;

		if (node.op == binop::plus) {
			const_result = tmp_lhs + tmp_rhs;
		}
		else if (node.op == binop::minus) {
			const_result = tmp_lhs - tmp_rhs;
		}
		else if (node.op == binop::multiply) {
			const_result = tmp_lhs * tmp_rhs;
		}
		else if (node.op == binop::divide) {
			// check if divided by 0.
			//std::cout << __LINE__ << "\n";
			if (tmp_rhs == 0) {
				err.error(node.rhs->line, node.rhs->pos, "Divided by zero!");
				error_flag = true;
				value_result = nullptr;
				return;
			}
			const_result = tmp_lhs / tmp_rhs;
		}
		else if (node.op == binop::modulo) {
			// check if divided by 0.
			//std::cout << __LINE__ << "\n";
			//std::cout << tmp_rhs << "\n";
			if (tmp_rhs == 0) {
				err.error(node.rhs->line, node.rhs->pos, "Divided by zero!");
				error_flag = true;
				value_result = nullptr;
				return;
			}
			const_result = tmp_lhs % tmp_rhs;
		}
	}
}

// finish.
void assembly_builder::visit(unaryop_expr_syntax &node)
{
	if (constexpr_expected == false) {
		// value_result
		node.rhs->accept(*this);
		if (value_result == nullptr) {
			return;
		}
		if (node.op == unaryop::minus) {
			value_result = builder.CreateNeg(value_result);
		}
	}
	else {
		// constexpr
		node.rhs->accept(*this);
		if (value_result == nullptr) {
			return;
		}
		if (node.op == unaryop::minus) {
			const_result = -const_result;
		}
	}

}

// finish.
void assembly_builder::visit(lval_syntax &node)
{
	// check if not declared before.
	if (std::get<0>(lookup_variable(node.name)) == nullptr) {
		err.error(node.line, node.pos, "Use of undeclared variable '" + node.name + "'.");
		if (constexpr_expected == true) {
			const_result = 0;
		}
		error_flag = true;
		value_result = nullptr;
		return;
	}
	if (lval_as_rval == false) {
		// lval
		if (node.array_index == nullptr) {
			// no array index
			value_result = std::get<0>(lookup_variable(node.name));
		}
		else {
			// array idnex
			auto tmp_const_exp = constexpr_expected;
			constexpr_expected = false;
			auto tmp_lval = lval_as_rval;
			lval_as_rval = true;
			node.array_index->accept(*this);
			if (value_result == nullptr) {
				return;
			}
			lval_as_rval = tmp_lval;
			constexpr_expected = tmp_const_exp;
			Value* indexList[] = { ConstNum(0), value_result };
			auto id_ptr = std::get<0>(lookup_variable(node.name));
			value_result = builder.CreateGEP(id_ptr, indexList);
		}
	}
	else if(constexpr_expected == false){
		// rval - value_result
		if (node.array_index == nullptr) {
			// no array index
			// check if is_array
			if (std::get<2>(lookup_variable(node.name)) == true) {
				// is_array
				err.error(node.line, node.pos, "Array used as integer variable: '" + node.name + "'.");
				error_flag = true;
				value_result = nullptr;
				return;
			}

			auto id_ptr = std::get<0>(lookup_variable(node.name));
			value_result = builder.CreateLoad(Type::getInt32Ty(context), id_ptr);
		}
		else {
			// array index
			// check if is_array
			if (std::get<2>(lookup_variable(node.name)) == false) {
				// not array.
				err.error(node.line, node.pos, "Subscripted value is not an array: '" + node.name + "'.");
				error_flag = true;
				value_result = nullptr;
				return;
			}

			node.array_index->accept(*this);
			Value* indexList[] = {ConstNum(0),  value_result};
			auto id_ptr = std::get<0>(lookup_variable(node.name));
			value_result = builder.CreateGEP(id_ptr, indexList);
			value_result = builder.CreateLoad(Type::getInt32Ty(context), value_result);
		}
	}
	else {
		err.error(node.line, node.pos, "Constant expression expected: '" + node.name + "'.");
		value_result = nullptr;
		const_result = 0;
		error_flag = true;
	}

}

// finish.
void assembly_builder::visit(literal_syntax &node)
{
	if (constexpr_expected == false) {
		// value_result
		value_result = ConstantInt::get(Type::getInt32Ty(context), APInt(32, node.number));
	}
	else {
		// constexpr
		const_result = node.number;
	}

}

// finish.
void assembly_builder::visit(var_def_stmt_syntax &node)
{
	// check if multiple name.
	if (variables[0].count(node.name)) {
		err.error(node.line, node.pos, "Multiple declaration of variable '" + node.name + "' in current scope.");
		error_flag = true;
		return;
	}

	Value *ca, *index;
	if (in_global == false) {
		// local
		if (node.array_length == nullptr) { 
			// non-array
			constexpr_expected = false;
			ca = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, node.name);
			if (node.initializers.size() != 0) {
				node.initializers[0]->accept(*this);
				if (value_result == nullptr) {
					return;
				}
				builder.CreateStore(value_result, ca);
			}
		}
		else {
			// array
			constexpr_expected = true;
			auto tmp_err = error_flag;
			error_flag = false;
			auto check_but_dump = false;
			node.array_length->accept(*this);
			value_result = ConstNum(const_result);
			constexpr_expected = false;
			// check if too much init.
			if (const_result < node.initializers.size()) {
				err.error(node.line, node.pos, "Too much initializer expressions.");
				error_flag = true;
			}
			// check if negative length.
			if (const_result <= 0) {
				err.error(node.line, node.pos, "Not const positive integer array length.");
				error_flag = true;
			}
			if (error_flag) {
				check_but_dump = true;
			}
			else {
				error_flag = tmp_err;
			}
			if (check_but_dump)
				return;
			ca = builder.CreateAlloca(ArrayType::get(Type::getInt32Ty(context), const_result), ConstNum(1), node.name);
			int i = 0;
			for (auto &init : node.initializers) {
				Value* indexList[] = {ConstNum(0), ConstNum(i++) };
				index = builder.CreateGEP(ca, indexList);
				init->accept(*this);
				builder.CreateStore(value_result, index);
			}
		}
	}
	else {
		// global
		constexpr_expected = true;
		if (node.array_length == nullptr) {
			// non-array
			ConstantInt *init;
			if (node.initializers.size() == 0) {
				init = ConstNum(0);
			}
			else {
				node.initializers[0]->accept(*this);
				if (value_result == nullptr) {
					return;
				}
				init = ConstNum(const_result);
			}
			ca = new GlobalVariable(*module.get(), Type::getInt32Ty(context), node.is_constant, GlobalValue::LinkageTypes::ExternalLinkage, init, node.name);
		}
		else {
			// array
			auto tmp_err = error_flag;
			auto check_but_dump = false;
			lval_as_rval = true;
			error_flag = false;
			node.array_length->accept(*this);
			int len = const_result;
			
			// check if too much init.
			if (len < node.initializers.size()) {
				err.error(node.line, node.pos, "Too much initializer expressions.");
				error_flag = true;
			}
			// check if negative length.
			if (len <= 0) {
				err.error(node.line, node.pos, "Not positive array length.");
				error_flag = true;
			}

			// no matter init or not, init to 0!
			std::vector<Constant*> values;
			int i = 0;
			for (auto &init : node.initializers) {
				lval_as_rval = true;
				constexpr_expected = true;
				value_result = ConstNum(0);
				init->accept(*this);
				values.push_back(ConstNum(const_result));
			}
			for (int i = values.size(); i < len; i++) {
				values.push_back(ConstNum(0));
			}
			if (error_flag) {
				check_but_dump = true;
			}
			else {
				error_flag = tmp_err;
			}
			if (check_but_dump)
				return;
			auto init = ConstantArray::get(ArrayType::get(Type::getInt32Ty(context), len), values);

			ca = new GlobalVariable(*module.get(), ArrayType::get(Type::getInt32Ty(context), len), node.is_constant, GlobalValue::LinkageTypes::ExternalLinkage, init, node.name);
		}
	}
	declare_variable(node.name, ca, node.is_constant, node.array_length != nullptr);
}

// finish.
void assembly_builder::visit(assign_stmt_syntax &node)
{
	// check if target exists.
	if (std::get<0>(lookup_variable(node.target->name)) == nullptr) {
		// not exists.
		err.error(node.target->line, node.target->pos, "Use of undeclared variable '" + node.target->name + "'.");
		error_flag = true;
		return;
	}
	// check if target is const.
	if (std::get<1>(lookup_variable(node.target->name)) == true) {
		// const
		err.error(node.target->line, node.target->pos, "Assigning to constant:'" + node.target->name + "'.");
		error_flag = true;
		return;
	}
	// check if target is array or not.
	if (std::get<2>(lookup_variable(node.target->name)) == false && node.target->array_index ) {
		// int as array.
		err.error(node.target->line, node.target->pos, "Subscripted value is not an array: '" + node.target->name +"'.");
		error_flag = true;
		return;
	}
	if (std::get<2>(lookup_variable(node.target->name)) == true && node.target->array_index == nullptr) {
		// array as int.
		err.error(node.target->line, node.target->pos, "Array used as integer variable: '" + node.target->name + "'.");
		error_flag = true;
		return;
	}
	lval_as_rval = false;
	node.target->accept(*this);

	lval_as_rval = true;
	Value *target = value_result;
	value_result = ConstNum(0);
	node.value->accept(*this);

	Value *value = value_result;
	
	if (target == nullptr || value == nullptr) {
		return;
	}
	builder.CreateStore(value, target);
}

// finish.
void assembly_builder::visit(func_call_stmt_syntax &node)
{
	auto callee = functions[node.name];
	if (callee == nullptr) {
		err.error(node.line, node.pos, "Called function not defined: '" + node.name + "'.");
		error_flag = true;
		return;
	}
	builder.CreateCall(callee, {});
}

// finish.
void assembly_builder::visit(block_syntax &node)
{
	enter_scope();
	ptr_list<stmt_syntax> body = node.body;
	for (auto &b : body) {
		value_result = ConstNum(0);
		lval_as_rval = true;
		constexpr_expected = false;
		b.get()->accept(*this);
	}
	exit_scope();
}

// finish.
void assembly_builder::visit(if_stmt_syntax &node)
{

	auto ifB = BasicBlock::Create(context, "IfB", current_function);
	auto thenB = BasicBlock::Create(context, "ThenB", current_function);
	auto elseB = BasicBlock::Create(context, "ElseB", current_function);
	auto afterIfB = BasicBlock::Create(context, "AfterIf", current_function);
	
	builder.CreateBr(ifB);
	builder.SetInsertPoint(ifB);
	node.pred->accept(*this);
	builder.CreateCondBr(value_result, thenB, elseB);
	builder.SetInsertPoint(thenB);
	node.then_body->accept(*this);
	builder.CreateBr(afterIfB);

	builder.SetInsertPoint(elseB);
	if (node.else_body) {
		// might be no else body.
		node.else_body->accept(*this);
	}
	builder.CreateBr(afterIfB);
	builder.SetInsertPoint(afterIfB);
}

// finish.
void assembly_builder::visit(while_stmt_syntax &node)
{
	auto whileB = BasicBlock::Create(context, "WhileB", current_function);
	auto blockB = BasicBlock::Create(context, "BlockB", current_function);
	auto afterB = BasicBlock::Create(context, "AfterB", current_function);

	builder.CreateBr(whileB);
	builder.SetInsertPoint(whileB);
	//visit(*node.pred);
	node.pred->accept(*this);
	builder.CreateCondBr(value_result, blockB, afterB);
	builder.SetInsertPoint(blockB);
	//visit(*node.body);
	node.body->accept(*this);
	builder.CreateBr(whileB);
	builder.SetInsertPoint(afterB);

}

// finish.
void assembly_builder::visit(empty_stmt_syntax &node)
{
	// nothing.
}
