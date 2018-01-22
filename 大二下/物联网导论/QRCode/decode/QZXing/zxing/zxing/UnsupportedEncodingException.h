#ifndef UNSUPPORTEDENCODINGEXCEPTION_H
#define UNSUPPORTEDENCODINGEXCEPTION_H

#include <zxing/Exception.h>

namespace zxing {

class UnsupportedEncodingException : public Exception {
 public:
  UnsupportedEncodingException() throw() {}
  UnsupportedEncodingException(char const* msg) throw() : Exception(msg) {}
  ~UnsupportedEncodingException() throw() {}
};

}

#endif // UNSUPPORTEDENCODINGEXCEPTION_H
