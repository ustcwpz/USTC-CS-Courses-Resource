cmake_minimum_required(VERSION 3.5)

add_definitions(-DFULL_IMPL)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# compiler must be 11 or 14
set(CMAKE_CXX_STANDARD 14)

# set variable pointing to the antlr tool that supports C++
set(ANTLR4CPP_JAR_LOCATION "NOT-FOUND" CACHE STRING "ANTLR v4 JAR file location. Used by antlr4cpp.")

# add external build for antlrcpp
include(ExternalAntlr4Cpp)

# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4CPP_INCLUDE_DIRS})
link_directories(${ANTLR4CPP_LIBS})
message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS} ")

# Call macro to add lexer and grammar to your build dependencies.
antlr4cpp_process_grammar(c1_recognizer c1_recognizer
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/C1Lexer.g4
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/C1Parser.g4)

include(ExternalProject)
ExternalProject_Add(rapidjson
  PREFIX ${CMAKE_BINARY_DIR}/externals/rapidjson
  GIT_REPOSITORY https://github.com/Tencent/rapidjson.git
  GIT_TAG v1.1.0
  GIT_SUBMODULES ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  UPDATE_COMMAND ""
  INSTALL_COMMAND "")
ExternalProject_Get_Property(rapidjson DOWNLOAD_DIR)
set(rapidjson_include_dirs ${DOWNLOAD_DIR}/rapidjson/include)

# include generated files in project environment
include_directories(${antlr4cpp_include_dirs_c1_recognizer})
include_directories(include)

# add generated grammar to c1_recognizer binary target
add_library(c1recognizer
  src/error_listener.cpp
  src/error_reporter.cpp
  src/syntax_tree.cpp
  src/syntax_tree_builder.cpp
  src/recognizer.cpp
  ${antlr4cpp_src_files_c1_recognizer})
add_dependencies(c1recognizer antlr4cpp antlr4cpp_generation_c1_recognizer)
target_link_libraries(c1recognizer antlr4-runtime)

include_directories(${rapidjson_include_dirs})
add_executable(c1r_test test/main.cpp)
add_dependencies(c1r_test c1recognizer rapidjson)
target_link_libraries(c1r_test c1recognizer)

install(
  TARGETS c1recognizer
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install(DIRECTORY include/c1recognizer DESTINATION include)

install(DIRECTORY ${ANTLR4CPP_LIBS}/ DESTINATION lib)

configure_file(c1recognizer-config.cmake.in c1recognizer-config.cmake @ONLY)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/c1recognizer-config.cmake DESTINATION cmake)
