#ifndef QRCODEV4_H
#define QRCODEV4_H

#include <QRCode.h>
#include <string.h>


class QRCodeV4 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV4();
        ~QRCodeV4();
};

#endif // QRCODEV4_H
