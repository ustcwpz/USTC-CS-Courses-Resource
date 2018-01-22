#ifndef QRCODEV37_H
#define QRCODEV37_H

#include <QRCode.h>
#include <string.h>


class QRCodeV37 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV37();
        ~QRCodeV37();
};

#endif // QRCODEV37_H
