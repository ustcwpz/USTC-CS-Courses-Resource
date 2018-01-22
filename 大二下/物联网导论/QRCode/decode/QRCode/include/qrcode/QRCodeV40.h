#ifndef QRCODEV40_H
#define QRCODEV40_H

#include <QRCode.h>
#include <string.h>


class QRCodeV40 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV40();
        ~QRCodeV40();
};

#endif // QRCODEV40_H
