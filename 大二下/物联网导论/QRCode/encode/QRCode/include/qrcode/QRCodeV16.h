#ifndef QRCODEV16_H
#define QRCODEV16_H

#include <QRCode.h>
#include <string.h>


class QRCodeV16 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV16();
        ~QRCodeV16();
};

#endif // QRCODEV16_H
