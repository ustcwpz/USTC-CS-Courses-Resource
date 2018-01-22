#ifndef QRMASK2_H
#define QRMASK2_H

#include <QRMask.h>


class QRMask2 : public QRMask
{
    public:
        QRMask2(int module_count, int module_width, Bitmap* bmp_mask);
        bool IsMaskCondition(int x, int y);
    protected:
    private:
};

#endif // QRMASK2_H
