#ifndef QRCODEV5_H
#define QRCODEV5_H

#include <QRCode.h>
#include <string.h>


class QRCodeV5 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV5();
        ~QRCodeV5();
};

#endif // QRCODEV5_H
