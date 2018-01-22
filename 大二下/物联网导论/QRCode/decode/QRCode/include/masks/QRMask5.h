#ifndef QRMASK5_H
#define QRMASK5_H

#include <QRMask.h>


class QRMask5 : public QRMask
{
    public:
        QRMask5(int module_count, int module_width, Bitmap* bmp_mask);
        bool IsMaskCondition(int x, int y);
    protected:
    private:
};

#endif // QRMASK5_H
