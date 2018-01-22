#ifndef QRCODEV10_H
#define QRCODEV10_H

#include <QRCode.h>
#include <string.h>


class QRCodeV10 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV10();
        ~QRCodeV10();
};

#endif // QRCODEV10_H
