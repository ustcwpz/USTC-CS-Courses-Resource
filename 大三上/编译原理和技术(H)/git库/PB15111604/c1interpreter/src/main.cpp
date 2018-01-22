#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Support/DynamicLibrary.h>
#include <llvm/Support/TargetSelect.h>

#include <c1recognizer/recognizer.h>

#include "assembly_builder.h"

using namespace llvm;
using namespace std;
using namespace c1_recognizer;
using namespace syntax_tree;
using namespace std::literals::string_literals;

int main(int argc, char **argv)
{
    char *in_file = nullptr;
    bool emit_llvm = false;
    for (int i = 1; i < argc; ++i)
        if ("-emit-llvm"s == argv[i])
            emit_llvm = true;
        else if ("-h"s == argv[i] || "--help"s == argv[i])
        {
            cout << "Usage: c1i [-emit-llvm] <input-c1-source>." << endl;
            return 0;
        }
        else if (argv[i][0] == '-')
        {
            cerr << "Unknown option '" << argv[i] << "'." << endl;
            return 1;
        }
        else
        {
            if (!in_file)
                in_file = argv[i];
            else
            {
                cerr << "Multiple input file specified. Compiling multiple sources is not supported in C1." << endl;
                return 1;
            }
        }

    if (!in_file)
    {
        cerr << "Input file expected." << endl;
        return 1;
    }

    ifstream in_stream(in_file);
    recognizer c1r(in_stream);

    error_reporter err(cerr);
    if (!c1r.execute(err))
    {
        cerr << "Parsing failed. Exiting." << endl;
        return 2;
    }

    auto ast = c1r.get_syntax_tree();

    string name = in_file;
    name = name.substr(name.find_last_of("/\\") + 1);

    LLVMContext llvm_ctx;
    assembly_builder builder(llvm_ctx, err);
    builder.build(name, ast);
    auto module = builder.get_module();
    auto runtime = builder.get_runtime_info();

    if (!module)
    {
        cerr << "Semantic failed. Exiting." << endl;
        return 3;
    }

    if (emit_llvm)
        module->print(outs(), nullptr);
    else
    {
        auto entry_func = module->getFunction("main");
        if (!entry_func)
        {
            cerr << "No 'main' function presented. Exiting." << endl;
            return 4;
        }

        InitializeNativeTarget();
        InitializeNativeTargetAsmPrinter();
        InitializeNativeTargetAsmParser();
        
        for (auto t : runtime->get_runtime_symbols())
            sys::DynamicLibrary::AddSymbol(get<0>(t), get<1>(t));

        string error_info;
        unique_ptr<ExecutionEngine> engine(EngineBuilder(move(module))
                                               .setEngineKind(EngineKind::JIT)
                                               .setErrorStr(&error_info)
                                               .create());
        if (!engine)
        {
            cerr << "EngineBuilder failed: " << error_info << endl;
            return 4;
        }
        engine->runFunction(entry_func, {});
    }

    return 0;
}
