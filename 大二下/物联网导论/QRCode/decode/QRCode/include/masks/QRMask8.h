#ifndef QRMASK8_H
#define QRMASK8_H

#include <QRMask.h>


class QRMask8 : public QRMask
{
    public:
        QRMask8(int module_count, int module_width, Bitmap* bmp_mask);
        bool IsMaskCondition(int x, int y);
    protected:
    private:
};

#endif // QRMASK8_H
