#ifndef QRCODEV2_H
#define QRCODEV2_H

#include <QRCode.h>
#include <string.h>


class QRCodeV2 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV2();
        ~QRCodeV2();
};

#endif // QRCODEV2_H
