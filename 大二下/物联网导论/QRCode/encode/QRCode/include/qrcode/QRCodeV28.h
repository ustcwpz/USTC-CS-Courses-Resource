#ifndef QRCODEV28_H
#define QRCODEV28_H

#include <QRCode.h>
#include <string.h>


class QRCodeV28 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV28();
        ~QRCodeV28();
};

#endif // QRCODEV28_H
