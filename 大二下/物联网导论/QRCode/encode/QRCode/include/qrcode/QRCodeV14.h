#ifndef QRCODEV14_H
#define QRCODEV14_H

#include <QRCode.h>
#include <string.h>


class QRCodeV14 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV14();
        ~QRCodeV14();
};

#endif // QRCODEV14_H
