#include "QRCode.h"

#include <sstream>

namespace zxing {
namespace qrcode {

QRCode::QRCode() :
    mode_(),
    ecLevel_ptr_(NULL),
    version_ptr_(NULL),
    maskPattern_(-1),
    matrix_ptr_(NULL) {}

QRCode::~QRCode()
{
}

Mode QRCode::getMode() const
{
    return mode_;
}

Ref<ErrorCorrectionLevel> QRCode::getECLevel() const
{
    return ecLevel_ptr_;
}

Ref<Version> QRCode::getVersion() const
{
    return version_ptr_;
}

int QRCode::getMaskPattern() const
{
    return maskPattern_;
}

Ref<ByteMatrix> QRCode::getMatrix() const
{
    return matrix_ptr_;
}

const std::string QRCode::toString()
{
    std::stringstream result;
    result << "<<";
//    result << "\n mode: {unimpl}";
//    result << mode_;
    result << "\n ecLevel: {unimpl}";
    //result << ecLevel_;
    result << "\n version: {unimpl}";
    //result << version_;
    result << "\n maskPattern: ";
    result << maskPattern_;
    //  if (matrix_ == null) {
    //    result.append("\n matrix: null\n");
    //  } else {
    if (matrix_ptr_)
        result << "\n matrix:\n" << matrix_ptr_->toString();
    else
        result << "\n matrix: null\n";
    //  }
    result << "\n>>";
    return result.str();
}

void QRCode::setMode(const Mode& value)
{
    mode_ = value;
}

void QRCode::setECLevel(Ref<ErrorCorrectionLevel> value)
{
    ecLevel_ptr_ = value;
}

void QRCode::setVersion(Ref<Version> version)
{
    version_ptr_ = version;
}

void QRCode::setMaskPattern(int value)
{
    maskPattern_ = value;
}

void QRCode::setMatrix(Ref<ByteMatrix> value)
{
    matrix_ptr_ = value;
}

}
}
