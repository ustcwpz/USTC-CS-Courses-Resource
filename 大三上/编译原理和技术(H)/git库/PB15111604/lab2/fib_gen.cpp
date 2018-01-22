#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalValue.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/Constant.h>
//#include <llvm/IR/ValueSymbolTable.h>
#include <llvm/ADT/APInt.h>


#include <memory>
using namespace llvm;
LLVMContext theContext;

Value * ConstNum(int n) {
	return ConstantInt::get(theContext, APInt(32, n));
}

int main() {
	IRBuilder<> builder(theContext);
	auto theModule = new Module("fib_gen", theContext);
	std::vector<Type*> args(1, Type::getInt32Ty(theContext));
	FunctionType *FT = FunctionType::get(Type::getInt32Ty(theContext), args, false);
	
	/**
		fib
	**/
	Function *F = Function::Create(FT, GlobalValue::LinkageTypes::ExternalLinkage, "fib", theModule);
	Value *arg = &(*(F->arg_begin()));
	arg->setName("n");
	auto enterB = BasicBlock::Create(theContext, "", F);
	builder.SetInsertPoint(enterB);
	auto argValue = arg;
	//auto argValue = F->getValueSymbolTable()->lookup(arg->getName());
	auto ret = builder.CreateAlloca(Type::getInt32Ty(theContext));
	auto retB = BasicBlock::Create(theContext, "", F);
	
	// if
	auto cond = builder.CreateICmpEQ(argValue, ConstNum(0));
	auto thenB = BasicBlock::Create(theContext, "", F);
	auto elseB = BasicBlock::Create(theContext, "", F);
	builder.CreateCondBr(cond, thenB, elseB);

	// then
	builder.SetInsertPoint(thenB);
	builder.CreateAlignedStore(ConstNum(0), ret, 4);
	builder.CreateBr(retB);

	// else
	builder.SetInsertPoint(elseB);
	cond = builder.CreateICmpEQ(argValue, ConstNum(1));
	thenB = BasicBlock::Create(theContext, "", F);
	elseB = BasicBlock::Create(theContext, "", F);
	builder.CreateCondBr(cond, thenB, elseB);
	
	// then
	builder.SetInsertPoint(thenB);
	builder.CreateAlignedStore(ConstNum(1), ret, 4);
	builder.CreateBr(retB);

	// else
	builder.SetInsertPoint(elseB);
	auto sub = builder.CreateNSWSub(argValue, ConstNum(1));
	auto call = builder.CreateCall(F, { sub });
	auto sub1 = builder.CreateNSWSub(argValue, ConstNum(2));
	auto call1 = builder.CreateCall(F, { sub1 });
	auto add = builder.CreateNSWAdd(call, call1);
	builder.CreateAlignedStore(add, ret, 4);
	builder.CreateBr(retB);

	// ret
	builder.SetInsertPoint(retB);
	auto result = builder.CreateAlignedLoad(ret, 4);
	builder.CreateRet(result);

	/**
		main
	**/
	FT = FunctionType::get(Type::getInt32Ty(theContext), false);
	auto M = Function::Create(FT, GlobalValue::LinkageTypes::ExternalLinkage, "main", theModule);
	enterB = BasicBlock::Create(theContext, "", M);
	builder.SetInsertPoint(enterB);
	ret = builder.CreateAlloca(Type::getInt32Ty(theContext));
	retB = BasicBlock::Create(theContext, "", M);
	
	// int x = 0;
	auto xp = builder.CreateAlloca(Type::getInt32Ty(theContext));
	builder.CreateAlignedStore(ConstNum(0), xp, 4);

	// for init
	auto ip = builder.CreateAlloca(Type::getInt32Ty(theContext));
	builder.CreateAlignedStore(ConstNum(0), ip, 4);
	auto forCondB = BasicBlock::Create(theContext, "", M);
	auto forLoopB = BasicBlock::Create(theContext, "", M);
	builder.CreateBr(forCondB);

	// for cond
	builder.SetInsertPoint(forCondB);
	auto i = builder.CreateAlignedLoad(ip, 4);
	cond = builder.CreateICmpSLT(i, ConstNum(10));
	builder.CreateCondBr(cond, forLoopB, retB);

	// for loop
	builder.SetInsertPoint(forLoopB);
	auto x = builder.CreateAlignedLoad(xp, 4);
	auto i1 = builder.CreateAlignedLoad(ip, 4);
	auto c = builder.CreateCall(F, { i1 });
	auto x1 = builder.CreateNSWAdd(x, c);
	builder.CreateAlignedStore(x1, xp, 4);

	// i++
	auto i2 = builder.CreateAlignedLoad(ip, 4);
	auto i3 = builder.CreateNSWAdd(i2, ConstNum(1));
	builder.CreateAlignedStore(i3, ip, 4);
	builder.CreateBr(forCondB);

	// ret
	builder.SetInsertPoint(retB);
	auto x2 = builder.CreateAlignedLoad(xp, 4);
	builder.CreateRet(x2);

	theModule->print(outs(), nullptr);
	delete theModule;
	return 0;
}

