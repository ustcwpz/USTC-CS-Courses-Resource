#ifndef QRCODEV22_H
#define QRCODEV22_H

#include <QRCode.h>
#include <string.h>


class QRCodeV22 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV22();
        ~QRCodeV22();
};

#endif // QRCODEV22_H
