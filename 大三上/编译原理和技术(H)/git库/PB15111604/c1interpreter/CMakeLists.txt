CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

add_definitions(-DFULL_IMPL)

SET (CMAKE_CXX_STANDARD 14)

find_package(c1recognizer)
include_directories(${C1RECOGNIZER_INCLUDE_DIRS})
link_directories(${C1RECOGNIZER_LIBRARY_DIRS})

# Import LLVM
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
llvm_map_components_to_libnames(llvm_libs core mcjit native)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

include_directories(dependency/c1recognizer/include)
add_executable(c1i
  src/main.cpp
  src/assembly_builder.cpp
  src/runtime.cpp
  src/runtime/io.c
  src/assembly_builder.h
  src/runtime.h
  src/runtime/io.h)
target_link_libraries(c1i ${C1RECOGNIZER_LIBS} ${llvm_libs})
