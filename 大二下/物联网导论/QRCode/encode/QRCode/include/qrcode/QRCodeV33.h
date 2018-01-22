#ifndef QRCODEV33_H
#define QRCODEV33_H

#include <QRCode.h>
#include <string.h>


class QRCodeV33 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV33();
        ~QRCodeV33();
};

#endif // QRCODEV33_H
