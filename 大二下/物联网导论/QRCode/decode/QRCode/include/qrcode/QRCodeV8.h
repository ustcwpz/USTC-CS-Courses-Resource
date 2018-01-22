#ifndef QRCODEV8_H
#define QRCODEV8_H

#include <QRCode.h>
#include <string.h>


class QRCodeV8 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);

    public:
        QRCodeV8();
        ~QRCodeV8();
};

#endif // QRCODEV8_H
