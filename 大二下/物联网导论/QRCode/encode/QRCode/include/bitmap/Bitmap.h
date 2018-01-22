#ifndef BITMAP_H
#define BITMAP_H

#include <stdint.h>
#include <Colors.h>
#include <string>
#include <vector>

typedef enum {BI_RGB = 0, BI_RLE8 = 1, BI_RLE = 2, BI_BITFIELDS = 3, BI_JPEG = 4, BI_PNG= 5} BMP_COMPRSSION;

#pragma pack(1)

struct BITMAP_DIB_HEADER
{
    uint32_t   Size;
    uint32_t   Width;
    uint32_t   Height;
    uint16_t   NumberColorPlanes;
    uint16_t   BPP;
    uint32_t   Compression;
    uint32_t   ImageSize;
    uint32_t   HRes;
    uint32_t   VRes;
    uint32_t   Palette;
    uint32_t   ImportantColor;

    BITMAP_DIB_HEADER()
    {
        Size                = sizeof(BITMAP_DIB_HEADER);
        NumberColorPlanes   = 1;
        BPP                 = 24;
        Compression         = BI_RGB;
        HRes                = 2835;
        VRes                = 2835;
        Palette             = 0;
        ImportantColor      = 0;
    }
};

struct BITMAP_FILE_HEADER
{
    uint16_t    Type;
    uint32_t    FileSize;
    uint16_t    Reserverd0;
    uint16_t    Reserverd1;
    uint32_t    Offset;

    BITMAP_FILE_HEADER()
    {
        Type        = 0x4d42;
        Reserverd0  = 0;
        Reserverd1  = 0;
        Offset      = sizeof(BITMAP_FILE_HEADER) + sizeof(BITMAP_DIB_HEADER);
    }
};
#pragma pack()

using namespace std;
class Bitmap
{
    private:
        unsigned char *Canvas;

    protected:
        BITMAP_FILE_HEADER* BMP_Header;
        BITMAP_DIB_HEADER*  DIB_Header;

        void SetPixelColor(int x, int y, int R, int G, int B);
        uint32_t getPixelColor(int x, int y);

    public:
        Bitmap(int width, int height);
        virtual ~Bitmap();

        void Clear(void);

        void DrawPoint (int x, int y, uint32_t color);
        void DrawPoint (int x, int y, int R, int G, int B);
        void DrawRectangle(int x, int y, int width, int height, uint32_t color);
        void DrawRectangle(int x, int y, int width, int height, int R, int G, int B);
        void FillArea(int x, int y, int width, int height, uint32_t color);
        uint32_t getPoint(int x, int y);

        Bitmap* Clone(void);
        unsigned char* getCanvas(void);
        const uint32_t getWidth(void);
        const uint32_t getHeight(void);

        bool SaveToFile(string file_name);
        bool SaveToByteArray(vector<char> & bitmap_array);
};

#endif // BITMAP_H
