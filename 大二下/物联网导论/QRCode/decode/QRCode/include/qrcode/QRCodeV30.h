#ifndef QRCODEV30_H
#define QRCODEV30_H

#include <QRCode.h>
#include <string.h>


class QRCodeV30 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV30();
        ~QRCodeV30();
};

#endif // QRCODEV30_H
