# C1 Language Interpreter (Reference Version)

## Introduction

Two parts are included:

1. `assembly_builder`: Build assembly from AST, with LLVM `IRBuilder`.
1. `jit_driver`: Execute assembly with the help of Just-In-Time compiling. Currently all in `main.cpp`.

As a CLI tool, `c1i` is capable of compiling C1 code into LLVM IR, print it and execute it.

## Build

Use CMake for building this project. `c1recognizer` and LLVM installations are required. 
