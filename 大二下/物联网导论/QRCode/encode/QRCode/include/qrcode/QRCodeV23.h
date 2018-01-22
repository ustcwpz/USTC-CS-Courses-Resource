#ifndef QRCODEV23_H
#define QRCODEV23_H

#include <QRCode.h>
#include <string.h>


class QRCodeV23 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV23();
        ~QRCodeV23();
};

#endif // QRCODEV23_H
