#ifndef QRCODEV32_H
#define QRCODEV32_H

#include <QRCode.h>
#include <string.h>


class QRCodeV32 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV32();
        ~QRCodeV32();
};

#endif // QRCODEV32_H
