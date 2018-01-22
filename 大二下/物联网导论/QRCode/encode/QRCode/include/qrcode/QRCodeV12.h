#ifndef QRCODEV12_H
#define QRCODEV12_H

#include <QRCode.h>
#include <string.h>


class QRCodeV12 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV12();
        ~QRCodeV12();
};

#endif // QRCODEV12_H
