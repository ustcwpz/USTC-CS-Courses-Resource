#ifndef QRMASK4_H
#define QRMASK4_H

#include <QRMask.h>


class QRMask4 : public QRMask
{
    public:
        QRMask4(int module_count, int module_width, Bitmap* bmp_mask);
        bool IsMaskCondition(int x, int y);
    protected:
    private:
};

#endif // QRMASK4_H
