#ifndef QRCODEV17_H
#define QRCODEV17_H

#include <QRCode.h>
#include <string.h>


class QRCodeV17 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV17();
        ~QRCodeV17();
};

#endif // QRCODEV17_H
