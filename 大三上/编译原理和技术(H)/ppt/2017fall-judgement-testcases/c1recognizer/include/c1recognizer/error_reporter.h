
#ifndef _C1_ERROR_REPORTER_H_
#define _C1_ERROR_REPORTER_H_

#include <iostream>

namespace c1_recognizer
{

class error_reporter
{
  public:
    error_reporter(std::ostream &error_stream);

    void error(size_t line, size_t charPositionInLine, const std::string &msg);
    void warn(size_t line, size_t charPositionInLine, const std::string &msg);

  protected:
    virtual void report(size_t line, size_t charPositionInLine, const std::string &msg, const std::string &prefix);

  private:
    std::ostream &err;
};
}

#endif
