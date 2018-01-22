
INCLUDEPATH += QRCode/include
INCLUDEPATH += QRCode/include/bitmap
INCLUDEPATH += QRCode/include/drawable
INCLUDEPATH += QRCode/include/enums
INCLUDEPATH += QRCode/include/exceptions
INCLUDEPATH += QRCode/include/masks
INCLUDEPATH += QRCode/include/polynomial_generator
INCLUDEPATH += QRCode/include/qrcode
INCLUDEPATH += QRCode/include/struct
INCLUDEPATH += QRCode/include/test

HEADERS += \
    QRCode/include/bitmap/Bitmap.h \
    QRCode/include/bitmap/Colors.h \
    QRCode/include/drawable/QRBitmapDraw.h \
    QRCode/include/drawable/QRDrawable.h \
    QRCode/include/enums/enumCorrectionLevel.h \
    QRCode/include/enums/enumMode.h \
    QRCode/include/enums/enumVersions.h \
    QRCode/include/exceptions/EQRCapabilities.h \
    QRCode/include/exceptions/EQRDimension.h \
    QRCode/include/exceptions/EQRErrorCorrection.h \
    QRCode/include/exceptions/EQRGeneric.h \
    QRCode/include/masks/QRMask.h \
    QRCode/include/masks/QRMask1.h \
    QRCode/include/masks/QRMask2.h \
    QRCode/include/masks/QRMask3.h \
    QRCode/include/masks/QRMask4.h \
    QRCode/include/masks/QRMask5.h \
    QRCode/include/masks/QRMask6.h \
    QRCode/include/masks/QRMask7.h \
    QRCode/include/masks/QRMask8.h \
    QRCode/include/polynomial_generator/LogAntilog.h \
    QRCode/include/polynomial_generator/Monomial.h \
    QRCode/include/polynomial_generator/PolynomialGenerator.h \
    QRCode/include/qrcode/QRCode.h \
    QRCode/include/qrcode/QRCodeV1.h \
    QRCode/include/qrcode/QRCodeV10.h \
    QRCode/include/qrcode/QRCodeV11.h \
    QRCode/include/qrcode/QRCodeV12.h \
    QRCode/include/qrcode/QRCodeV13.h \
    QRCode/include/qrcode/QRCodeV14.h \
    QRCode/include/qrcode/QRCodeV15.h \
    QRCode/include/qrcode/QRCodeV16.h \
    QRCode/include/qrcode/QRCodeV17.h \
    QRCode/include/qrcode/QRCodeV18.h \
    QRCode/include/qrcode/QRCodeV19.h \
    QRCode/include/qrcode/QRCodeV2.h \
    QRCode/include/qrcode/QRCodeV20.h \
    QRCode/include/qrcode/QRCodeV21.h \
    QRCode/include/qrcode/QRCodeV22.h \
    QRCode/include/qrcode/QRCodeV23.h \
    QRCode/include/qrcode/QRCodeV24.h \
    QRCode/include/qrcode/QRCodeV25.h \
    QRCode/include/qrcode/QRCodeV26.h \
    QRCode/include/qrcode/QRCodeV27.h \
    QRCode/include/qrcode/QRCodeV28.h \
    QRCode/include/qrcode/QRCodeV29.h \
    QRCode/include/qrcode/QRCodeV3.h \
    QRCode/include/qrcode/QRCodeV30.h \
    QRCode/include/qrcode/QRCodeV31.h \
    QRCode/include/qrcode/QRCodeV32.h \
    QRCode/include/qrcode/QRCodeV33.h \
    QRCode/include/qrcode/QRCodeV34.h \
    QRCode/include/qrcode/QRCodeV35.h \
    QRCode/include/qrcode/QRCodeV36.h \
    QRCode/include/qrcode/QRCodeV37.h \
    QRCode/include/qrcode/QRCodeV38.h \
    QRCode/include/qrcode/QRCodeV39.h \
    QRCode/include/qrcode/QRCodeV4.h \
    QRCode/include/qrcode/QRCodeV40.h \
    QRCode/include/qrcode/QRCodeV5.h \
    QRCode/include/qrcode/QRCodeV6.h \
    QRCode/include/qrcode/QRCodeV7.h \
    QRCode/include/qrcode/QRCodeV8.h \
    QRCode/include/qrcode/QRCodeV9.h \
    QRCode/include/struct/StructECInfo.h \
    QRCode/include/struct/StructPoint.h \
    QRCode/include/test/output_test.h \
    QRCode/include/QRController.h

SOURCES += \
    QRCode/src/bitmap/Bitmap.cpp \
    QRCode/src/drawable/QRBitmapDraw.cpp \
    QRCode/src/drawable/QRDrawable.cpp \
    QRCode/src/exceptions/EQRCapabilities.cpp \
    QRCode/src/exceptions/EQRDimension.cpp \
    QRCode/src/exceptions/EQRErrorCorrection.cpp \
    QRCode/src/exceptions/EQRGeneric.cpp \
    QRCode/src/masks/QRMask.cpp \
    QRCode/src/masks/QRMask1.cpp \
    QRCode/src/masks/QRMask2.cpp \
    QRCode/src/masks/QRMask3.cpp \
    QRCode/src/masks/QRMask4.cpp \
    QRCode/src/masks/QRMask5.cpp \
    QRCode/src/masks/QRMask6.cpp \
    QRCode/src/masks/QRMask7.cpp \
    QRCode/src/masks/QRMask8.cpp \
    QRCode/src/polynomial_generator/Monomial.cpp \
    QRCode/src/polynomial_generator/PolynomialGenerator.cpp \
    QRCode/src/qrcode/QRCode.cpp \
    QRCode/src/qrcode/QRCodeV1.cpp \
    QRCode/src/qrcode/QRCodeV10.cpp \
    QRCode/src/qrcode/QRCodeV11.cpp \
    QRCode/src/qrcode/QRCodeV12.cpp \
    QRCode/src/qrcode/QRCodeV13.cpp \
    QRCode/src/qrcode/QRCodeV14.cpp \
    QRCode/src/qrcode/QRCodeV15.cpp \
    QRCode/src/qrcode/QRCodeV16.cpp \
    QRCode/src/qrcode/QRCodeV17.cpp \
    QRCode/src/qrcode/QRCodeV18.cpp \
    QRCode/src/qrcode/QRCodeV19.cpp \
    QRCode/src/qrcode/QRCodeV2.cpp \
    QRCode/src/qrcode/QRCodeV20.cpp \
    QRCode/src/qrcode/QRCodeV21.cpp \
    QRCode/src/qrcode/QRCodeV22.cpp \
    QRCode/src/qrcode/QRCodeV23.cpp \
    QRCode/src/qrcode/QRCodeV24.cpp \
    QRCode/src/qrcode/QRCodeV25.cpp \
    QRCode/src/qrcode/QRCodeV26.cpp \
    QRCode/src/qrcode/QRCodeV27.cpp \
    QRCode/src/qrcode/QRCodeV28.cpp \
    QRCode/src/qrcode/QRCodeV29.cpp \
    QRCode/src/qrcode/QRCodeV3.cpp \
    QRCode/src/qrcode/QRCodeV30.cpp \
    QRCode/src/qrcode/QRCodeV31.cpp \
    QRCode/src/qrcode/QRCodeV32.cpp \
    QRCode/src/qrcode/QRCodeV33.cpp \
    QRCode/src/qrcode/QRCodeV34.cpp \
    QRCode/src/qrcode/QRCodeV35.cpp \
    QRCode/src/qrcode/QRCodeV36.cpp \
    QRCode/src/qrcode/QRCodeV37.cpp \
    QRCode/src/qrcode/QRCodeV38.cpp \
    QRCode/src/qrcode/QRCodeV39.cpp \
    QRCode/src/qrcode/QRCodeV4.cpp \
    QRCode/src/qrcode/QRCodeV40.cpp \
    QRCode/src/qrcode/QRCodeV5.cpp \
    QRCode/src/qrcode/QRCodeV6.cpp \
    QRCode/src/qrcode/QRCodeV7.cpp \
    QRCode/src/qrcode/QRCodeV8.cpp \
    QRCode/src/qrcode/QRCodeV9.cpp \
    QRCode/src/test/output_test.cpp \
    QRCode/src/QRController.cpp \
    QRCode/test_main.cpp

