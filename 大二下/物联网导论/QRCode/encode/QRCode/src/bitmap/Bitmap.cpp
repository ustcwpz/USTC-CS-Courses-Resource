/*
 * QR Code Generator
 * Copyright (C) 2014 Stefano BARILETTI <hackaroth@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "Bitmap.h"
#include <string.h>
#include <fstream>

Bitmap::Bitmap(int width, int height)
{
    BMP_Header              = new BITMAP_FILE_HEADER;
    DIB_Header              = new BITMAP_DIB_HEADER;

    uint16_t row_bytes      = width*DIB_Header->BPP/8;
    uint16_t padding        = (4 - (width*3) % 4) % 4;

    DIB_Header->Width       = width;
    DIB_Header->Height      = height;
    DIB_Header->ImageSize   = (row_bytes + padding) * height;

    BMP_Header->FileSize    = sizeof(BITMAP_FILE_HEADER) + sizeof(BITMAP_DIB_HEADER) + DIB_Header->ImageSize;

    Canvas = new unsigned char[DIB_Header->ImageSize];

    Clear();
}

//-------------------------------------------------------------------
void Bitmap::Clear(void)
{
    uint16_t row_bytes      = DIB_Header->Width*DIB_Header->BPP/8;
    uint16_t padding        = (4 - (DIB_Header->Width*3) % 4) % 4;

    //Initialize canvas setting white background color
    unsigned long pos = 0;
    for (int i = 0; i < DIB_Header->Height; i++)
    {
        memset(Canvas+pos, 0xff, row_bytes); //Color
        memset(Canvas+pos+row_bytes, 0x00, padding); //Padding
        pos += row_bytes+padding;
    }
}
//-------------------------------------------------------------------
Bitmap::~Bitmap()
{
    if (Canvas != NULL)
        delete Canvas;

    if (BMP_Header)
        delete BMP_Header;

    if (DIB_Header)
        delete DIB_Header;
}
//-------------------------------------------------------------------
bool Bitmap::SaveToFile(string file_name)
{
    ofstream fp (file_name.c_str(), ofstream::binary);
    bool res = false;

    if (fp)
    {
        try
        {
            fp.write((char*)BMP_Header, sizeof(BITMAP_FILE_HEADER));
            fp.write((char*)DIB_Header, sizeof(BITMAP_DIB_HEADER));
            fp.write((char*)Canvas, DIB_Header->ImageSize);
            fp.close();

            res = true;
        }
        catch(...)
        {

        }
    }

    return res;
}

bool Bitmap::SaveToByteArray(vector<char> &bitmap_array)
{
    bool res = false;

    try
    {
        for(int loop = 0; loop < sizeof(BITMAP_FILE_HEADER); loop++){
            bitmap_array.push_back(((char*)BMP_Header)[loop]);
        }
        for(int loop = 0; loop < sizeof(BITMAP_DIB_HEADER); loop++){
            bitmap_array.push_back(((char*)DIB_Header)[loop]);
        }
        for(int loop = 0; loop < DIB_Header->ImageSize; loop++){
            bitmap_array.push_back(((char*)Canvas)[loop]);
        }

        res = true;
    }
    catch(...)
    {

    }

    return res;
}
//-------------------------------------------------------------------
const uint32_t Bitmap::getWidth(void)
{
    return DIB_Header->Width;
}
//-------------------------------------------------------------------
const uint32_t Bitmap::getHeight(void)
{
    return DIB_Header->Height;
}
//-------------------------------------------------------------------
void Bitmap::DrawPoint (int x, int y, uint32_t color)
{
    int R = (color & 0xff0000)>>16;
    int G = (color & 0x00ff00)>>8;
    int B = (color & 0x0000ff);

    SetPixelColor(x, getHeight() - y - 1, R, G, B);
}
//-------------------------------------------------------------------

void Bitmap::DrawPoint (int x, int y, int R, int G, int B)
{
    SetPixelColor(x, getHeight() - y - 1, R, G, B);
}
//-------------------------------------------------------------------
uint32_t Bitmap::getPoint(int x, int y)
{
    return getPixelColor(x, getHeight() - y - 1);
}
//-------------------------------------------------------------------

uint32_t Bitmap::getPixelColor(int x, int y)
{
    uint32_t res = 0;

    if (x >= 0 && y >= 0 && x < getWidth() && y < getHeight())
    {
        int padding     = (4 - (getWidth()*3) % 4) % 4;
        int pos         = (x + getWidth()*y)*3 + (padding * y);

        int R = Canvas[pos];
        int G = Canvas[pos+1];
        int B = Canvas[pos+2];

        res = ((R & 0xff) << 16) + ((G & 0xff) << 8) + (B & 0xff);
    }

    return res;
}
//-------------------------------------------------------------------

void Bitmap::SetPixelColor(int x, int y, int R, int G, int B)
{
    if (x >= 0 && y >= 0 && x < getWidth() && y < getHeight())
    {
        int padding     = (4 - (getWidth()*3) % 4) % 4;
        int pos         = (x + getWidth()*y)*3 + (padding * y);

        Canvas[pos]     = R;
        Canvas[pos+1]   = G;
        Canvas[pos+2]   = B;
    }
}
//-------------------------------------------------------------------

void Bitmap::DrawRectangle(int x, int y, int width, int height, uint32_t color)
{
    int R = (color & 0xff0000)>>16;
    int G = (color & 0x00ff00)>>8;
    int B = (color & 0x0000ff);

    DrawRectangle(x, y, width, height, R, G, B);
}

//-------------------------------------------------------------------
void Bitmap::DrawRectangle(int x, int y, int width, int height, int R, int G, int B)
{
    if (x + width <= getWidth() && y + height <= getHeight())
    {
        for (int i = 0; i < width; i++)
        {
            DrawPoint(x+i, y, R, G, B);
            DrawPoint(x+i, y+height-1, R, G, B);
        }

        for (int i = 0; i < height; i++)
        {
            DrawPoint(x, y+i, R, G, B);
            DrawPoint(x+width-1, y+i, R, G, B);
        }
    }
}
//-------------------------------------------------------------------
void Bitmap::FillArea(int x, int y, int width, int height, uint32_t color)
{
    int R = (color & 0xff0000)>>16;
    int G = (color & 0x00ff00)>>8;
    int B = (color & 0x0000ff);

    if (x + width <= getWidth() && y + height <= getHeight())
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                DrawPoint(x+j, y+i, R, G, B);
            }
        }
    }
}
//-------------------------------------------------------------------
Bitmap* Bitmap::Clone(void)
{
    Bitmap* res = new Bitmap(DIB_Header->Width, DIB_Header->Height);

    memcpy(res->getCanvas(), this->Canvas, DIB_Header->ImageSize);

    return res;
}
//-------------------------------------------------------------------

unsigned char* Bitmap::getCanvas(void)
{
    return Canvas;
}

//-------------------------------------------------------------------
