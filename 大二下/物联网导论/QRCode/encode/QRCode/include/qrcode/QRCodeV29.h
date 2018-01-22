#ifndef QRCODEV29_H
#define QRCODEV29_H

#include <QRCode.h>
#include <string.h>


class QRCodeV29 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV29();
        ~QRCodeV29();
};

#endif // QRCODEV29_H
