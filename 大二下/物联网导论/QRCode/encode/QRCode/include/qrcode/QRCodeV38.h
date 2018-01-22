#ifndef QRCODEV38_H
#define QRCODEV38_H

#include <QRCode.h>
#include <string.h>


class QRCodeV38 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV38();
        ~QRCodeV38();
};

#endif // QRCODEV38_H
