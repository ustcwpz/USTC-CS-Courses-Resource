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


#include "QRBitmapDraw.h"
#include "EQRDimension.h"
#include <math.h>
#include <string.h>
#include <iostream>
#include "QRMask1.h"
#include "QRMask2.h"
#include "QRMask3.h"
#include "QRMask4.h"
#include "QRMask5.h"
#include "QRMask6.h"
#include "QRMask7.h"
#include "QRMask8.h"

QRBitmapDraw::QRBitmapDraw(QRCode *qr_code, int width, int height)
{
    int min_size = qr_code->getModules();

    if (width < min_size || height < min_size)
        throw EQRDimension("Image size is too small to contain the qr code");

    this->QrCode    = qr_code;
    bitmap          = new Bitmap(width, height);


    ReservedModules.clear();
}
//-------------------------------------------------------------------

QRBitmapDraw::~QRBitmapDraw()
{
    if (bitmap)
        delete bitmap;

    ReservedModules.clear();
}
//-------------------------------------------------------------------

void QRBitmapDraw::DrawModule(int x, int y, int color, Bitmap* bmp)
{
    int module_width = getModuleWidth();

    if (bmp == NULL)
    {
        if (bitmap != NULL)
            bitmap->FillArea(module_width*x, module_width*y, module_width, module_width, color);
    }
    else
    {
        bmp->FillArea(module_width*x, module_width*y, module_width, module_width, color);
    }

}
//-------------------------------------------------------------------

int QRBitmapDraw::getModuleWidth(void)
{
    int res = 0;
    int modules = this->QrCode->getModules();
    if (modules > 0)
        res = floor(bitmap->getWidth() / modules);

    return res;
}
//-------------------------------------------------------------------

void QRBitmapDraw::DrawPositionDetectionPattern(void)
{
    int modules         = this->QrCode->getModules();
    int module_width    = getModuleWidth();

    if (bitmap && module_width > 0)
    {
        for (int i = 0; i < 7; i++)
        {
            DrawModule(i, 0); DrawModule(0, i);
            DrawModule(i, 6); DrawModule(6, i);

            DrawModule(modules-i-1, 0); DrawModule(0, modules-i-1);
            DrawModule(modules-i-1, 6); DrawModule(6, modules-i-1);

            DrawModule(i, modules-1); DrawModule(modules-1, i);
            DrawModule(i, modules-7); DrawModule(modules-7, i);
        }

        for (int i = 0; i < 3; i++)
        {
            DrawModule(i+2, 2); DrawModule(i+2, 3); DrawModule(i+2, 4);

            DrawModule(modules-i-3, 2); DrawModule(modules-i-3, 3); DrawModule(modules-i-3, 4);

            DrawModule(i+2, modules-3); DrawModule(i+2, modules-4); DrawModule(i+2, modules-5);
        }
    }
}
//-------------------------------------------------------------------
void QRBitmapDraw::DrawTimingPattern(void)
{
    int modules         = this->QrCode->getModules();
    int module_width    = getModuleWidth();

    for (int i = 0; i < modules-16; i=i+2)
    {
        AddReservedModule(8+i, 6);
        AddReservedModule(6, 8+i);

        if (i < modules-16-1)
        {
            AddReservedModule(8+i+1, 6);
            AddReservedModule(6, 8+i+1);
        }

        DrawModule(8+i, 6);
        DrawModule(6, 8+i);
    }
}
//-------------------------------------------------------------------
void QRBitmapDraw::DrawDarkModulePattern(void)
{
    int y = (QrCode->getVersion() * 4) + 9;
    int x = 8;

    DrawModule(x, y);

    //The reservation for this module will be done by the creation of
    //reservations for format information
}
//-------------------------------------------------------------------
void QRBitmapDraw::DrawFormatInformation(string data)
{
    int x = 0;
    int y = 8;

    for(int i = 0; i < strlen(data.c_str()); i++)
    {
        if (x == 6)
            x++;

        if (x > 7 && x < 13)
            x = 13;

        if (data[i] == '1')
            DrawModule(x,y);

        x++;
    }

    x = 8;
    y = 0;

    for(int i = strlen(data.c_str()) - 1; i >= 0 ; i--)
    {
        if (y == 6)
            y++;

        if (y > 8 && y < (QrCode->getVersion() * 4) + 9 + 1)
            y = (QrCode->getVersion() * 4) + 9 + 1;

        if (data[i] == '1')
            DrawModule(x,y);

        y++;
    }
}
//-------------------------------------------------------------------


void QRBitmapDraw::CreateFormatReservation(void)
{
    int module_count = QrCode->getModules();
    for (int i = 0; i < 9; i++)
    {
        AddReservedModule(i, 8);
        AddReservedModule(8, i);

        if (i < 8)
        {
            AddReservedModule(i + (module_count - 7 -1), 8);
            AddReservedModule(8, i + (module_count - 7 -1));
        }
    }
}
//-------------------------------------------------------------------
void QRBitmapDraw::DrawAlignmentPattern(void)
{
    vector<Point> alignement_patterns = QrCode->getAlignementPatterns();

    for (int j = 0; j < alignement_patterns.size(); j++)
    {
        Point p = alignement_patterns.at(j);

        DrawModule(p.X, p.Y);
        AddReservedModule(p.X, p.Y);

        AddReservedModule(p.X-1, p.Y);
        AddReservedModule(p.X+1, p.Y);

        for (int i = p.X-1; i <= p.X+1; i++)
        {
            AddReservedModule(i, p.Y-1);
            AddReservedModule(i, p.Y+1);
        }

        for (int i = p.X-2; i <= p.X+2; i++)
        {
            DrawModule(i, p.Y-2);
            AddReservedModule(i, p.Y-2);

            DrawModule(i, p.Y+2);
            AddReservedModule(i, p.Y+2);
        }

        for (int i = p.Y-1; i <= p.Y+1; i++)
        {
            DrawModule(p.X-2, i);
            AddReservedModule(p.X-2, i);

            DrawModule(p.X+2, i);
            AddReservedModule(p.X+2, i);
        }
    }
}
//-------------------------------------------------------------------
void QRBitmapDraw::DrawVersionInformation(void)
{
    if (QrCode->IsVersionInfoRequired())
    {
        string version_info = QrCode->CreateVersionInformation();

        if (version_info != "")
        {
            int start   = QrCode->getModules() - 11;
            int cnt     = 1;

            int x0      = start;
            int y0      = 0;

            int x1      = 0;
            int y1      = start;

            for (int i = strlen(version_info.c_str()) - 1; i >= 0; i--)
            {
                if (cnt > 3)
                {
                    cnt = 1;

                    x0  = start;
                    y0++;

                    x1++;
                    y1  = start;
                }

                if (version_info[i] == '1')
                {
                    DrawModule(x0, y0);
                    DrawModule(x1, y1);
                }

                x0++;
                y1++;
                cnt++;
            }
        }
    }
}
//-------------------------------------------------------------------
void QRBitmapDraw::CreateVersionReservation(void)
{
    if (QrCode->IsVersionInfoRequired())
    {
            int start   = QrCode->getModules() - 11;
            int cnt     = 1;

            int x0      = start;
            int y0      = 0;

            int x1      = 0;
            int y1      = start;

            for (int i = 17; i >= 0; i--)
            {
                if (cnt > 3)
                {
                    cnt = 1;

                    x0  = start;
                    y0++;

                    x1++;
                    y1  = start;
                }

                AddReservedModule(x0, y0);
                AddReservedModule(x1, y1);

                x0++;
                y1++;
                cnt++;
            }

    }
}
//-------------------------------------------------------------------


Point QRBitmapDraw::getNextPoint(int x, int y)
{
    int temp = floor((QrCode->getModules() - x -1)/2);

    bool up = ((x > 6 && temp%2 == 0) || (x < 6 && temp%2 == 1))?true:false;

    int x0 = x;
    int y0 = y;

    Point res;

    if (x0 == 1 && y0 == 8)
    {
        int t=0;
    }
    if ((x0 > 6 && x0 % 2 == 0) || (x0 < 6 && x0 % 2 == 1))
    {
        x0--;
    }
    else
    {
        if (up)
        {
            y0--;
            x0++;
        }
        else
        {
            y0++;
            x0++;
        }
    }

    if (y0 < 0 || (x0 > QrCode->getModules() - 8 && y0 < 8) || (x0 < 9 && y0 < 8))
    {
        x0 -= 2;
        y0++;
    }
    else if (y0 > QrCode->getModules()-1 || (x0 < 6 && y0 > QrCode->getModules() - 8 - 1) || (x0 < 9 && y0 < 8))
    {
        x0 -= 2;
        y0--;
    }

    if (x0 == 6)
    {
        x0--;
        y0++;
    }


    if (ModuleReserved(x0, y0) || (x0 < 9 && y0 > QrCode->getModules() - 8 - 1))
        res = getNextPoint(x0,y0);
    else
    {
        res.X = x0;
        res.Y = y0;
    }

    return res;
}
//-------------------------------------------------------------------
void QRBitmapDraw::DrawData(string data)
{
    int module_count = QrCode->getModules();
    int data_length  = strlen(data.c_str());

    //Set the start point. Bottom Right
    Point p = Point(module_count - 1, module_count - 1);

    for (int i = 0; i < data_length; i++)
    {
        if (data[i] == '1')
            DrawModule(p.X, p.Y);

        //For debug
        //cout << data[i] << ": " <<  p.X << " - " << p.Y << endl;
        p = getNextPoint(p.X, p.Y);
    }

}
//-------------------------------------------------------------------

vector<QRMask*> QRBitmapDraw::CreateMasks(string data)
{
    vector<QRMask*> res;

    int module_count    = QrCode->getModules();
    int module_width    = getModuleWidth();
    int data_length     = strlen(data.c_str());

    QRMask1* mask1      = new QRMask1(module_count, module_width, bitmap->Clone());
    QRMask2* mask2      = new QRMask2(module_count, module_width, bitmap->Clone());
    QRMask3* mask3      = new QRMask3(module_count, module_width, bitmap->Clone());
    QRMask4* mask4      = new QRMask4(module_count, module_width, bitmap->Clone());
    QRMask5* mask5      = new QRMask5(module_count, module_width, bitmap->Clone());
    QRMask6* mask6      = new QRMask6(module_count, module_width, bitmap->Clone());
    QRMask7* mask7      = new QRMask7(module_count, module_width, bitmap->Clone());
    QRMask8* mask8      = new QRMask8(module_count, module_width, bitmap->Clone());

    //Set the start point. Bottom Right
    Point p = Point(module_count - 1, module_count - 1);

    for (int i = 0; i < data_length; i++)
    {
        uint32_t color = (data[i] == '1')?white:black;

        if (mask1->IsMaskCondition(p.X, p.Y))
            DrawModule(p.X, p.Y, color, mask1->getMask());

        if (mask2->IsMaskCondition(p.X, p.Y))
            DrawModule(p.X, p.Y, color, mask2->getMask());

        if (mask3->IsMaskCondition(p.X, p.Y))
            DrawModule(p.X, p.Y, color, mask3->getMask());

        if (mask4->IsMaskCondition(p.X, p.Y))
            DrawModule(p.X, p.Y, color, mask4->getMask());

        if (mask5->IsMaskCondition(p.X, p.Y))
            DrawModule(p.X, p.Y, color, mask5->getMask());

        if (mask6->IsMaskCondition(p.X, p.Y))
            DrawModule(p.X, p.Y, color, mask6->getMask());

        if (mask7->IsMaskCondition(p.X, p.Y))
            DrawModule(p.X, p.Y, color, mask7->getMask());

        if (mask8->IsMaskCondition(p.X, p.Y))
            DrawModule(p.X, p.Y, color, mask8->getMask());

        p = getNextPoint(p.X, p.Y);
    }

    res.push_back(mask1);
    res.push_back(mask2);
    res.push_back(mask3);
    res.push_back(mask4);
    res.push_back(mask5);
    res.push_back(mask6);
    res.push_back(mask7);
    res.push_back(mask8);

    return res;
}
//-------------------------------------------------------------------

string QRBitmapDraw::ApplyMask(string data)
{
    string res              = "";
    int penalty             = -1;
    int temp                = 0;

    vector<QRMask*> masks   = CreateMasks(data);

    for (int i = 0; i < masks.size(); i++)
    {
        QRMask* mask = masks.at(i);

        temp = mask->getMaskPenalty();
        if (temp < penalty || penalty == -1)
        {
            delete bitmap;

            res     = mask->getID();
            penalty = temp;
            bitmap  = mask->getMask()->Clone();
        }

        delete mask;
    }

    masks.clear();

    return res;
}
//-------------------------------------------------------------------

void QRBitmapDraw::AddReservedModule(int x, int y)
{
    int modules_count = QrCode->getModules();

    if (x >= 0 && x < modules_count && y >= 0 && y < modules_count)
    {
        Point p = Point(x, y);
        ReservedModules.push_back(p);
    }
}
//-------------------------------------------------------------------

bool QRBitmapDraw::ModuleReserved(int x, int y)
{
    bool res = false;

    for (int i = 0; i < ReservedModules.size(); i++)
    {
        if (ReservedModules.at(i).X == x && ReservedModules.at(i).Y == y)
        {
            res = true;
            break;
        }
    }

    return res;
}

//-------------------------------------------------------------------
bool QRBitmapDraw::SaveToFile(string file_name)
{
    bool res = false;

    if (this->bitmap)
    {
        bitmap->Clear();
        ReservedModules.clear();

        DrawPositionDetectionPattern();
        DrawTimingPattern();
        DrawAlignmentPattern();
        DrawDarkModulePattern();

        CreateFormatReservation();
        CreateVersionReservation();

        string data = QrCode->CreateQRData();

        DrawData(data);

        string mask_id      = ApplyMask(data);
        string format_info  = QrCode->CreateFormatInformation(mask_id);

        DrawFormatInformation(format_info);

        DrawVersionInformation();

        res = this->bitmap->SaveToFile(file_name);
    }

    return res;
}

bool QRBitmapDraw::SaveToByteArray(vector<char> &bitmap_array)
{
    bool res = false;

    if (this->bitmap)
    {
        bitmap->Clear();
        ReservedModules.clear();

        DrawPositionDetectionPattern();
        DrawTimingPattern();
        DrawAlignmentPattern();
        DrawDarkModulePattern();

        CreateFormatReservation();
        CreateVersionReservation();

        string data = QrCode->CreateQRData();

        DrawData(data);

        string mask_id      = ApplyMask(data);
        string format_info  = QrCode->CreateFormatInformation(mask_id);

        DrawFormatInformation(format_info);

        DrawVersionInformation();

        res = this->bitmap->SaveToByteArray(bitmap_array);
    }

    return res;
}
//-------------------------------------------------------------------
