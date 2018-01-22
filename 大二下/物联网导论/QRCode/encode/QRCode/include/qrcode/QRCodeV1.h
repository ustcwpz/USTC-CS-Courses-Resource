#ifndef QRCODEV1_H
#define QRCODEV1_H

#include <QRCode.h>
#include <string.h>

class QRCodeV1 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV1();
        ~QRCodeV1();
};

#endif // QRCODEV1_H
