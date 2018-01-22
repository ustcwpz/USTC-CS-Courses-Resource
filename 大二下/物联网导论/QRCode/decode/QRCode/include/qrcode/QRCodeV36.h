#ifndef QRCODEV36_H
#define QRCODEV36_H

#include <QRCode.h>
#include <string.h>


class QRCodeV36 : public QRCode
{
    protected:

    private:
        void InitCapabilities(void);
        void InitECInfo(void);
        void InitAlignementPatterns(void);
    public:
        QRCodeV36();
        ~QRCodeV36();
};

#endif // QRCODEV36_H
