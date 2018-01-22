#ifndef WRITEREXCEPTION_H
#define WRITEREXCEPTION_H

#include <zxing/Exception.h>

namespace zxing {

class WriterException : public Exception {
 public:
  WriterException() throw() {}
  WriterException(char const* msg) throw() : Exception(msg) {}
  ~WriterException() throw() {}
};

}

#endif // WRITEREXCEPTION_H
