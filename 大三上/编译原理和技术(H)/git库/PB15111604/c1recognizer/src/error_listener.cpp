
#include "error_listener.h"

using namespace antlr4;
using namespace c1_recognizer;

error_listener::error_listener(error_reporter &_err) : err(_err), count(0) {}

void error_listener::syntaxError(Recognizer *, Token *, size_t line, size_t charPositionInLine, const std::string &msg,
                                 std::exception_ptr)
{
    err.error(line, charPositionInLine, msg);
    count++;
}

int error_listener::get_errors_count() { return count; }
