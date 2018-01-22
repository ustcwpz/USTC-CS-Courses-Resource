#ifndef QRMASK3_H
#define QRMASK3_H

#include <QRMask.h>


class QRMask3 : public QRMask
{
    public:
        QRMask3(int module_count, int module_width, Bitmap* bmp_mask);
        bool IsMaskCondition(int x, int y);
    protected:
    private:
};

#endif // QRMASK3_H
