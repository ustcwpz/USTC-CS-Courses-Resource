
#include <iostream>
#include "runtime.h"
#include "runtime/io.h"

#include <llvm/IR/Type.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/IRBuilder.h>

using namespace std;
using namespace llvm;

runtime_info::runtime_info(Module *module)
{
    input_var = new GlobalVariable(*module,
                                   Type::getInt32Ty(module->getContext()),
                                   false,
                                   GlobalValue::ExternalLinkage,
                                   ConstantInt::get(Type::getInt32Ty(module->getContext()), 0),
                                   "input_var");
    output_var = new GlobalVariable(*module,
                                    Type::getInt32Ty(module->getContext()),
                                    false,
                                    GlobalValue::ExternalLinkage,
                                    ConstantInt::get(Type::getInt32Ty(module->getContext()), 0),
                                    "output_var");
    auto input_impl = Function::Create(FunctionType::get(Type::getVoidTy(module->getContext()),
                                                         {Type::getInt32PtrTy(module->getContext())},
                                                         false),
                                       GlobalValue::LinkageTypes::ExternalLinkage,
                                       "input_impl",
                                       module);
    auto output_impl = Function::Create(FunctionType::get(Type::getVoidTy(module->getContext()),
                                                          {Type::getInt32PtrTy(module->getContext())},
                                                          false),
                                        GlobalValue::LinkageTypes::ExternalLinkage,
                                        "output_impl",
                                        module);

    IRBuilder<> builder(module->getContext());

    input_func = Function::Create(FunctionType::get(Type::getVoidTy(module->getContext()), {}, false),
                                  GlobalValue::LinkageTypes::ExternalLinkage,
                                  "input",
                                  module);
    builder.SetInsertPoint(BasicBlock::Create(module->getContext(), "entry", input_func));
    builder.CreateCall(input_impl, {input_var});
    builder.CreateRetVoid();

    output_func = Function::Create(FunctionType::get(Type::getVoidTy(module->getContext()), {}, false),
                                   GlobalValue::LinkageTypes::ExternalLinkage,
                                   "output",
                                   module);
    builder.SetInsertPoint(BasicBlock::Create(module->getContext(), "entry", output_func));
    builder.CreateCall(output_impl, {output_var});
    builder.CreateRetVoid();
}

using namespace string_literals;

vector<tuple<string, llvm::GlobalValue *, bool, bool, bool>> runtime_info::get_language_symbols()
{
    return {
        make_tuple("input_var"s, input_var, false, false, false),
        make_tuple("output_var"s, output_var, false, false, false),
        make_tuple("input"s, input_func, true, false, false),
        make_tuple("output"s, output_func, true, false, false)};
}

vector<tuple<string, void *>> runtime_info::get_runtime_symbols()
{
    return {
        make_tuple("input_impl"s, (void *)&::input),
        make_tuple("output_impl"s, (void *)&::output)};
}
