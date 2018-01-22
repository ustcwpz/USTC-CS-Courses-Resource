#ifndef QRCODEV27_H
#define QRCODEV27_H

#include <QRCode.h>
#include <string.h>


class QRCodeV27 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV27();
        ~QRCodeV27();
};

#endif // QRCODEV27_H
