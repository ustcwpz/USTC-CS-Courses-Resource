#ifndef QRCODEV35_H
#define QRCODEV35_H

#include <QRCode.h>
#include <string.h>


class QRCodeV35 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV35();
        ~QRCodeV35();
};

#endif // QRCODEV35_H
