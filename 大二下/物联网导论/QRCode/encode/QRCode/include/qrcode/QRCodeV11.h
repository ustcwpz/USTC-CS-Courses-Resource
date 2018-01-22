#ifndef QRCODEV11_H
#define QRCODEV11_H

#include <QRCode.h>
#include <string.h>


class QRCodeV11 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV11();
        ~QRCodeV11();
};

#endif // QRCODEV11_H
