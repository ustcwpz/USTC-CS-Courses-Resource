#ifndef QRCODEV21_H
#define QRCODEV21_H

#include <QRCode.h>
#include <string.h>


class QRCodeV21 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV21();
        ~QRCodeV21();
};

#endif // QRCODEV21_H
