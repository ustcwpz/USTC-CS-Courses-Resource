#ifndef QRCODEV9_H
#define QRCODEV9_H

#include <QRCode.h>
#include <string.h>


class QRCodeV9 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);

    public:
        QRCodeV9();
        ~QRCodeV9();
};

#endif // QRCODEV9_H
