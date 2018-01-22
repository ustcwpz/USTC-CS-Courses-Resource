#ifndef QRCODEV31_H
#define QRCODEV31_H

#include <QRCode.h>
#include <string.h>


class QRCodeV31 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV31();
        ~QRCodeV31();
};

#endif // QRCODEV31_H
