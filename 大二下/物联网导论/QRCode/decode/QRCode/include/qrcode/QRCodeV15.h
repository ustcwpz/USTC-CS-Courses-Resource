#ifndef QRCODEV15_H
#define QRCODEV15_H

#include <QRCode.h>
#include <string.h>


class QRCodeV15 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV15();
        ~QRCodeV15();
};

#endif // QRCODEV15_H
