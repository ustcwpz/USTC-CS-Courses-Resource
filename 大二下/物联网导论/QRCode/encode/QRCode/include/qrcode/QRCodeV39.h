#ifndef QRCODEV39_H
#define QRCODEV39_H

#include <QRCode.h>
#include <string.h>


class QRCodeV39 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV39();
        ~QRCodeV39();
};

#endif // QRCODEV39_H
