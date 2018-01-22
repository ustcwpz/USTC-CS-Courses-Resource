#ifndef QRCONTROLLER_H
#define QRCONTROLLER_H

#include "QRCode.h"
#include <string>
#include "enumCorrectionLevel.h"
#include "enumVersions.h"

using namespace std;
class QRController
{
    public:
        QRController(string data, eCorrectionLevel correction_level, int width, int height, int version);
        ~QRController();

        string getData(void);
        void setData(string data);

        eCorrectionLevel getCorrectionLevel(void);
        void setCorrectionLevel(eCorrectionLevel correction_level);

        int getVersion(void);
        void setVersion(int version);

        void SaveToFile(string file_name);
        void SaveToByteArray(vector<char> & bitmap_array);
    protected:
    private:
        int Width;
        int Height;

        int Version;
        eCorrectionLevel CorrectionLevel;
        string Data;

        QRCode* SelectQRCode(void);
        QRCode* getQRCode(void);
};

#endif // QRCONTROLLER_H
