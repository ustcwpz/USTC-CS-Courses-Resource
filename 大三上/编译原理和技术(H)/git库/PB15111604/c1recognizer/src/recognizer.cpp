#include <antlr4-runtime.h>
#include <C1Lexer.h>
#include <C1Parser.h>
#include <c1recognizer/recognizer.h>

#include "syntax_tree_builder.h"
#include "error_listener.h"

using namespace c1_recognizer;
using namespace syntax_tree;

using namespace antlr4;
using namespace antlrcpp;

recognizer::recognizer(const std::string &input_string) : ast(nullptr)
{
    input = new ANTLRInputStream(input_string);
}

recognizer::recognizer(std::istream &input_stream) : ast(nullptr)
{
    input = new ANTLRInputStream(input_stream);
}

std::shared_ptr<syntax_tree::syntax_tree_node> recognizer::get_syntax_tree() { return ast; }

recognizer::~recognizer()
{
    delete input;
}

bool recognizer::execute(error_reporter &_err)
{
    C1Lexer lexer(input);
    CommonTokenStream tokens(&lexer);
    C1Parser parser(&tokens);

    error_listener listener(_err);
    parser.removeErrorListeners();
    parser.addErrorListener(&listener);

    // Change the `exp` to the non-terminal name you want to examine as the top level symbol.
    // It should be `compilationUnit` for final submission.
    auto tree = parser.compilationUnit();

    if (listener.get_errors_count() > 0)
        return false;

    syntax_tree_builder ast_builder(_err);
    ast = ast_builder(tree);
    return true;
}
