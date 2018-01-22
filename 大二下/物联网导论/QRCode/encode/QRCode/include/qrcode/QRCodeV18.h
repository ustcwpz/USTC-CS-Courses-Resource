#ifndef QRCODEV18_H
#define QRCODEV18_H

#include <QRCode.h>
#include <string.h>


class QRCodeV18 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV18();
        ~QRCodeV18();
};

#endif // QRCODEV18_H
