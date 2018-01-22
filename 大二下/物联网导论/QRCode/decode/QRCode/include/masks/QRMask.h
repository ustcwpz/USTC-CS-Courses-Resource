#ifndef QRMASK_H
#define QRMASK_H

#include <string>
#include "Bitmap.h"
#include <stdint.h>

using namespace std;

class QRMask
{
    public:
        QRMask(int module_count, int module_width, Bitmap* bmp_mask);
		~QRMask();

        string getID(void);

        Bitmap* getMask(void);
        void setMask(Bitmap* bmp_mask);

        int getModuleWidth(void);
        void setModuleWidth(int value);

        int getModuleCount(void);
        void setModuleCount(int value);

        int getMaskPenalty(void);

		virtual bool IsMaskCondition(int x, int y)  = 0;

    protected:
		string ID;

    private:
    	int QRModuleCount;
    	int QRModuleWidth;
    	Bitmap* bmpMask;

		uint32_t getModuleColor(int x, int y);

        int EvaluationCondition1(void);
        int EvaluationCondition2(void);
        int EvaluationCondition3(void);
        int EvaluationCondition4(void);
};

#endif // QRMASK_H
