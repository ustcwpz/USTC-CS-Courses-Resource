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

#include "QRMask.h"
#include "math.h"
#include <stdlib.h>

QRMask::QRMask(int qr_module_count, int qr_module_width, Bitmap* bmp_mask)
{
	ID 				= "";
	bmpMask 		= bmp_mask;
	QRModuleCount 	= qr_module_count;
	QRModuleWidth	= qr_module_width;
}
//-------------------------------------------------------------------
QRMask::~QRMask()
{
	if (bmpMask != NULL)
		delete bmpMask;
}
//-------------------------------------------------------------------
string QRMask::getID(void)
{
    return ID;
}
//-------------------------------------------------------------------
uint32_t QRMask::getModuleColor(int x, int y)
{
    uint32_t res = 0;

    if (bmpMask != NULL && QRModuleWidth > 0)
    	res = bmpMask->getPoint(QRModuleWidth*x, QRModuleWidth*y);

    return res;
}
//-------------------------------------------------------------------
Bitmap* QRMask::getMask(void)
{
	return bmpMask;
}

//-------------------------------------------------------------------
void QRMask::setMask(Bitmap* bmp_mask)
{
	if (bmpMask != NULL)
		delete bmpMask;

	bmpMask = bmp_mask;
}
//-------------------------------------------------------------------
int QRMask::getModuleWidth(void)
{
	return QRModuleWidth;
}
//-------------------------------------------------------------------
int QRMask::getModuleCount(void)
{
	return QRModuleCount;
}
//-------------------------------------------------------------------
void QRMask::setModuleWidth(int value)
{
	QRModuleWidth = value;
}
//-------------------------------------------------------------------
void QRMask::setModuleCount(int value)
{
	QRModuleCount = value;
}
//-------------------------------------------------------------------
int QRMask::EvaluationCondition1(void)
{
    int res                 = 0;

    if (bmpMask != NULL)
    {
	    int color_count         = 0;
	    int current_color       = -1;
	    int previous_color      = -1;

	    for (int y = 0; y < QRModuleCount; y++)
	    {
	        color_count     = 0;
	        previous_color  = -1;

	        for (int x = 0; x < QRModuleCount; x++)
	        {
	            current_color = getModuleColor(x, y);

	            if ((current_color == previous_color) || (previous_color == -1))
	            {
	                previous_color = current_color;
	                color_count++;

	                if (color_count == 5)
                        res += 3;
	                else if (color_count > 5)
	                    res++;
	            }
	            else
	            {
	                previous_color  = current_color;
	                color_count     = 1;
	            }
	        }
	    }

	    for (int x = 0; x < QRModuleCount; x++)
	    {
	        color_count     = 0;
	        previous_color  = -1;

	        for (int y = 0; y < QRModuleCount; y++)
	        {
	            current_color = getModuleColor(x, y);

	            if ((current_color == previous_color) || (previous_color == -1))
	            {
	                previous_color = current_color;
	                color_count++;

	                if (color_count == 5)
                        res += 3;
	                else if (color_count > 5)
	                    res++;
	            }
	            else
	            {
	                previous_color  = current_color;
	                color_count     = 1;
	            }
	        }
	    }
	}

    return res;
}
//-------------------------------------------------------------------
int QRMask::EvaluationCondition2(void)
{
    int res  = 0;

    if (bmpMask != NULL)
    {
	    int group_count         = 0;
	    int color_xy            = -1;
	    int color_x1y           = -1;
	    int color_xy1           = -1;
	    int color_x1y1          = -1;

	    for (int y = 0; y < QRModuleCount - 1; y++)
	    {
	        for (int x = 0; x < QRModuleCount - 1; x++)
	        {
	            color_xy    = getModuleColor(x, y);
	            color_x1y   = getModuleColor(x+1, y);
	            color_xy1   = getModuleColor(x, y+1);
	            color_x1y1  = getModuleColor(x+1, y+1);

	            if ((color_xy == color_x1y) &&
	                (color_xy  == color_xy1) &&
	                (color_xy1 == color_x1y1))
	                {
	                    //bmpMask->DrawRectangle(QRModuleWidth*x+1, QRModuleWidth*y+1, QRModuleWidth*2-2, QRModuleWidth*2-2, red);
	                    group_count++;
	                }
	        }
	    }

	    res = group_count * 3;
	}

    return res;
}
//-------------------------------------------------------------------
int QRMask::EvaluationCondition3(void)
{
    int res             = 0;

    if (bmpMask != NULL)
    {
	    for (int y = 0; y < QRModuleCount; y++)
	    {
	        for (int x = 0; x < QRModuleCount-10; x++)
	        {
	           if ((getModuleColor(x, y) == white) &&
	               (getModuleColor(x+1, y) == white) &&
	               (getModuleColor(x+2, y) == white) &&
	               (getModuleColor(x+3, y) == white) &&
	               (getModuleColor(x+4, y) == black) &&
	               (getModuleColor(x+5, y) == white) &&
	               (getModuleColor(x+6, y) == black) &&
	               (getModuleColor(x+7, y) == black) &&
	               (getModuleColor(x+8, y) == black) &&
	               (getModuleColor(x+9, y) == white) &&
	               (getModuleColor(x+10, y) == black))
	           {
	               res += 40;
	           }
	           else if ((getModuleColor(x, y) == black) &&
	               (getModuleColor(x+1, y) == white) &&
	               (getModuleColor(x+2, y) == black) &&
	               (getModuleColor(x+3, y) == black) &&
	               (getModuleColor(x+4, y) == black) &&
	               (getModuleColor(x+5, y) == white) &&
	               (getModuleColor(x+6, y) == black) &&
	               (getModuleColor(x+7, y) == white) &&
	               (getModuleColor(x+8, y) == white) &&
	               (getModuleColor(x+9, y) == white) &&
	               (getModuleColor(x+10, y) == white))
	           {
	               res += 40;
	           }
	        }
	    }

	    for (int x = 0; x < QRModuleCount; x++)
	    {
	        for (int y = 0; y < QRModuleCount-10; y++)
	        {
	           if ((getModuleColor(x, y) == white) &&
	               (getModuleColor(x, y+1) == white) &&
	               (getModuleColor(x, y+2) == white) &&
	               (getModuleColor(x, y+3) == white) &&
	               (getModuleColor(x, y+4) == black) &&
	               (getModuleColor(x, y+5) == white) &&
	               (getModuleColor(x, y+6) == black) &&
	               (getModuleColor(x, y+7) == black) &&
	               (getModuleColor(x, y+8) == black) &&
	               (getModuleColor(x, y+9) == white) &&
	               (getModuleColor(x, y+10) == black))
	           {
	               res += 40;
	           }
	           else if ((getModuleColor(x, y) == black) &&
	               (getModuleColor(x, y+1) == white) &&
	               (getModuleColor(x, y+2) == black) &&
	               (getModuleColor(x, y+3) == black) &&
	               (getModuleColor(x, y+4) == black) &&
	               (getModuleColor(x, y+5) == white) &&
	               (getModuleColor(x, y+6) == black) &&
	               (getModuleColor(x, y+7) == white) &&
	               (getModuleColor(x, y+8) == white) &&
	               (getModuleColor(x, y+9) == white) &&
	               (getModuleColor(x, y+10) == white))
	           {
	               res += 40;
	           }
	        }
	    }
	}

    return res;
}
//-------------------------------------------------------------------
int QRMask::EvaluationCondition4(void)
{
    int res = 0;

    if (bmpMask != NULL)
    {
	    double dark_module_count    = 0;
	    double total_modules        = QRModuleCount * QRModuleCount;

	    for (int y = 0; y < QRModuleCount; y++)
	    {
	        for (int x = 0; x < QRModuleCount; x++)
	        {
	            if (getModuleColor(x, y) == black)
	                dark_module_count++;
	        }
	    }

	    double percent_dark     = (dark_module_count / total_modules) * 100;
	    int previous_multiple   = percent_dark;
	    int next_multiple       = percent_dark;

	    while (previous_multiple%5 != 0)
	        previous_multiple--;

	    while (next_multiple%5 != 0)
	        next_multiple++;

	    previous_multiple   = abs(previous_multiple-50)/5;
	    next_multiple       = abs(next_multiple-50)/5;

	    res = (previous_multiple < next_multiple)?previous_multiple:next_multiple;
	    res *= 10;
	}

    return res;
}
//-------------------------------------------------------------------

int QRMask::getMaskPenalty(void)
{
    int res = 0;

    if (bmpMask != NULL)
    {
	    res = EvaluationCondition1();
	    res += EvaluationCondition2();
	    res += EvaluationCondition3();
	    res += EvaluationCondition4();
	}

    return res;
}
//-------------------------------------------------------------------
