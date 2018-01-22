#ifndef QRCODEV34_H
#define QRCODEV34_H

#include <QRCode.h>
#include <string.h>


class QRCodeV34 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV34();
        ~QRCodeV34();
};

#endif // QRCODEV34_H
