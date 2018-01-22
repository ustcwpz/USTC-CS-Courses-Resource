#ifndef QRCODEV20_H
#define QRCODEV20_H

#include <QRCode.h>
#include <string.h>


class QRCodeV20 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV20();
        ~QRCodeV20();
};

#endif // QRCODEV20_H
