#ifndef QRMASK6_H
#define QRMASK6_H

#include <QRMask.h>


class QRMask6 : public QRMask
{
    public:
        QRMask6(int module_count, int module_width, Bitmap* bmp_mask);
        bool IsMaskCondition(int x, int y);
    protected:
    private:
};

#endif // QRMASK6_H
