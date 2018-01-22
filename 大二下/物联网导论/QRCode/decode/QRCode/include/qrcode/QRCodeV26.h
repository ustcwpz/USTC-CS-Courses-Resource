#ifndef QRCODEV26_H
#define QRCODEV26_H

#include <QRCode.h>
#include <string.h>


class QRCodeV26 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV26();
        ~QRCodeV26();
};

#endif // QRCODEV26_H
