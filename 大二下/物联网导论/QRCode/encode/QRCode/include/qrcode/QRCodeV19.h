#ifndef QRCODEV19_H
#define QRCODEV19_H

#include <QRCode.h>
#include <string.h>


class QRCodeV19 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV19();
        ~QRCodeV19();
};

#endif // QRCODEV19_H
