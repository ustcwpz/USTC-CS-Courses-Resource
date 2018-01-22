#ifndef QRCODEV24_H
#define QRCODEV24_H

#include <QRCode.h>
#include <string.h>


class QRCodeV24 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV24();
        ~QRCodeV24();
};

#endif // QRCODEV24_H
