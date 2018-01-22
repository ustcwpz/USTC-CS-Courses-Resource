#ifndef QRCODEV13_H
#define QRCODEV13_H

#include <QRCode.h>
#include <string.h>


class QRCodeV13 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV13();
        ~QRCodeV13();
};

#endif // QRCODEV13_H
