#ifndef QRDRAWABLE_H
#define QRDRAWABLE_H

#include <string>
#include <vector>

using namespace std;

class QRDrawable
{
    public:
        QRDrawable();

        virtual bool SaveToFile(string file_name)           = 0;
    protected:
        virtual void DrawPositionDetectionPattern(void)     = 0;
        virtual void DrawTimingPattern(void)                = 0;
        virtual void DrawAlignmentPattern(void)             = 0;
        virtual void DrawDarkModulePattern(void)            = 0;
        virtual void DrawData(string data)                  = 0;
        virtual string ApplyMask(const string data)         = 0;
        virtual void DrawFormatInformation(string mask_id)  = 0;
        virtual void DrawVersionInformation(void)           = 0;
    private:

};

#endif // QRDRAWABLE_H
