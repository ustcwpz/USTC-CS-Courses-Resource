#ifndef QRCODEV25_H
#define QRCODEV25_H

#include <QRCode.h>
#include <string.h>


class QRCodeV25 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV25();
        ~QRCodeV25();
};

#endif // QRCODEV25_H
