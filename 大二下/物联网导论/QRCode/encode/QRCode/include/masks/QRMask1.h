#ifndef QRMASK1_H
#define QRMASK1_H

#include <QRMask.h>

class QRMask1 : public QRMask
{
    public:
        QRMask1(int module_count, int module_width, Bitmap* bmp_mask);
        bool IsMaskCondition(int x, int y);
    protected:
    private:

};

#endif // QRMASK1_H
