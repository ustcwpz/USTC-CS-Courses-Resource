#ifndef QRCODEV6_H
#define QRCODEV6_H

#include <QRCode.h>
#include <string.h>


class QRCodeV6 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV6();
        ~QRCodeV6();
};

#endif // QRCODEV6_H
