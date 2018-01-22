#ifndef QRCODEV3_H
#define QRCODEV3_H

#include <QRCode.h>
#include <string.h>


class QRCodeV3 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV3();
        ~QRCodeV3();
};

#endif // QRCODEV3_H
