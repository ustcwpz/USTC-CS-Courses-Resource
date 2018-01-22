
#ifndef _C1_RECOGNIZER_H_
#define _C1_RECOGNIZER_H_

#include <c1recognizer/syntax_tree.h>
#include <c1recognizer/error_reporter.h>
#include <string>
#include <iostream>

namespace antlr4
{
class ANTLRInputStream;
}

namespace c1_recognizer
{

class recognizer
{
  public:
    recognizer() = delete;
    recognizer(const std::string &input_string);
    recognizer(std::istream &input_stream);

    bool execute(error_reporter &_err);
    std::shared_ptr<syntax_tree::syntax_tree_node> get_syntax_tree();

    ~recognizer();

  private:
    std::shared_ptr<syntax_tree::syntax_tree_node> ast;
    antlr4::ANTLRInputStream *input;
    std::string source;
};
}

#endif
