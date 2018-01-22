#ifndef QRCODEV7_H
#define QRCODEV7_H

#include <QRCode.h>
#include <string.h>


class QRCodeV7 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV7();
        ~QRCodeV7();
};

#endif // QRCODEV7_H
