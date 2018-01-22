#ifndef QRBITMAPDRAW_H
#define QRBITMAPDRAW_H

#include <QRDrawable.h>
#include "Bitmap.h"
#include "QRCode.h"
#include <QRMask.h>

class QRBitmapDraw : public QRDrawable
{
    public:
        QRBitmapDraw(QRCode *qr_code, int width, int height);
        virtual ~QRBitmapDraw();

        bool SaveToFile(string file_name);
        bool SaveToByteArray(vector<char> & bitmap_array);

    protected:

    private:
        QRCode* QrCode;
        Bitmap* bitmap;
        vector<Point> ReservedModules;

        //Inherited from IQRDrawable
        void DrawPositionDetectionPattern(void);
        void DrawTimingPattern(void);
        void DrawAlignmentPattern(void);
        void DrawDarkModulePattern(void);
        void DrawData(string data);
        string ApplyMask(const string data);
        void DrawFormatInformation(string mask_id);
        void DrawVersionInformation(void);

        //Private methods
        void CreateFormatReservation(void);
        void CreateVersionReservation(void);
        void DrawModule(int x, int y, int color=black, Bitmap* bmp=NULL);

        vector<QRMask*> CreateMasks(string data);

        int getModuleWidth(void);
        Point getNextPoint(int x, int y);

        void AddReservedModule(int x, int y);
        bool ModuleReserved(int x, int y);
};

#endif // QRBITMAPDRAW_H
