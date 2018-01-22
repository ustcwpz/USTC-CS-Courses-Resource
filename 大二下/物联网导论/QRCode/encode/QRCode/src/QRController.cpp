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

#include <iostream>

#include "QRController.h"
#include "EQRGeneric.h"
#include "QRBitmapDraw.h"

#include "QRCodeV1.h"
#include "QRCodeV2.h"
#include "QRCodeV3.h"
#include "QRCodeV4.h"
#include "QRCodeV5.h"
#include "QRCodeV6.h"
#include "QRCodeV7.h"
#include "QRCodeV8.h"
#include "QRCodeV9.h"
#include "QRCodeV10.h"
#include "QRCodeV11.h"
#include "QRCodeV12.h"
#include "QRCodeV13.h"
#include "QRCodeV14.h"
#include "QRCodeV15.h"
#include "QRCodeV16.h"
#include "QRCodeV17.h"
#include "QRCodeV18.h"
#include "QRCodeV19.h"
#include "QRCodeV20.h"
#include "QRCodeV21.h"
#include "QRCodeV22.h"
#include "QRCodeV23.h"
#include "QRCodeV24.h"
#include "QRCodeV25.h"
#include "QRCodeV26.h"
#include "QRCodeV27.h"
#include "QRCodeV28.h"
#include "QRCodeV29.h"
#include "QRCodeV30.h"
#include "QRCodeV31.h"
#include "QRCodeV32.h"
#include "QRCodeV33.h"
#include "QRCodeV34.h"
#include "QRCodeV35.h"
#include "QRCodeV36.h"
#include "QRCodeV37.h"
#include "QRCodeV38.h"
#include "QRCodeV39.h"
#include "QRCodeV40.h"

QRController::QRController(string data, eCorrectionLevel correction_level, int width, int height, int version)
{
    Data            = data;
    CorrectionLevel = correction_level;
    Version         = version;

    Width           = width;
    Height          = height;
}
//-------------------------------------------------------------------

QRController::~QRController()
{

}
//-------------------------------------------------------------------

string QRController::getData(void)
{
    return Data;
}
//-------------------------------------------------------------------

void QRController::setData(string data)
{
    Data = data;
}
//-------------------------------------------------------------------

eCorrectionLevel QRController::getCorrectionLevel(void)
{
    return CorrectionLevel;
}
//-------------------------------------------------------------------

void QRController::setCorrectionLevel(eCorrectionLevel correction_level)
{
    CorrectionLevel = correction_level;
}
//-------------------------------------------------------------------

int QRController::getVersion(void)
{
    return Version;
}
//-------------------------------------------------------------------

void QRController::setVersion(int version)
{
    Version = version;
}
//-------------------------------------------------------------------

void QRController::SaveToFile(string file_name)
{
    QRCode* qr_code     = NULL;
    QRBitmapDraw* bmp   = NULL;

    try
    {
        if (Version == evAuto)
        {
            //Data and Error Correction Level are set inside the method SelectQRCode
            qr_code = SelectQRCode();
        }
        else
        {
            qr_code = getQRCode();

            qr_code->setData(Data);
            qr_code->setErrorCorrectionLevel(CorrectionLevel);
        }

        if (qr_code != NULL)
        {
            bmp = new QRBitmapDraw(qr_code, Width, Height);
            bmp->SaveToFile(file_name);
        }
        else
        {
            throw EQRGeneric("Invalid QR Code");
        }

    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }

    if (bmp != NULL)
        delete bmp;

    if (qr_code != NULL)
        delete qr_code;

}

void QRController::SaveToByteArray(vector<char> &bitmap_array)
{
    QRCode* qr_code     = NULL;
    QRBitmapDraw* bmp   = NULL;

    try
    {
        if (Version == evAuto)
        {
            //Data and Error Correction Level are set inside the method SelectQRCode
            qr_code = SelectQRCode();
        }
        else
        {
            qr_code = getQRCode();

            qr_code->setData(Data);
            qr_code->setErrorCorrectionLevel(CorrectionLevel);
        }

        if (qr_code != NULL)
        {
            bmp = new QRBitmapDraw(qr_code, Width, Height);
            bmp->SaveToByteArray(bitmap_array);
        }
        else
        {
            throw EQRGeneric("Invalid QR Code");
        }

    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }

    if (bmp != NULL)
        delete bmp;

    if (qr_code != NULL)
        delete qr_code;
}
//-------------------------------------------------------------------
QRCode* QRController::SelectQRCode(void)
{
    QRCode* res = NULL;

    for (int version = evVersion1; version <= evVersion40; version++)
    {
        Version = version;
        res     = getQRCode();

        if (res != NULL)
        {
            res->setData(Data);
            res->setErrorCorrectionLevel(CorrectionLevel);

            if (res->CanContainData())
            {
                break;
            }
            else
            {
                delete res;
                res = NULL;
            }
        }

    }

    return res;
}

//-------------------------------------------------------------------
QRCode* QRController::getQRCode(void)
{
    QRCode* res = NULL;

    switch (Version)
    {
        case evVersion1:
            res = new QRCodeV1();
            break;

        case evVersion2:
            res = new QRCodeV2();
            break;

        case evVersion3:
            res = new QRCodeV3();
            break;

        case evVersion4:
            res = new QRCodeV4();
            break;

        case evVersion5:
            res = new QRCodeV5();
            break;

        case evVersion6:
            res = new QRCodeV6();
            break;

        case evVersion7:
            res = new QRCodeV7();
            break;

        case evVersion8:
            res = new QRCodeV8();
            break;

        case evVersion9:
            res = new QRCodeV9();
            break;

        case evVersion10:
            res = new QRCodeV10();
            break;

        case evVersion11:
            res = new QRCodeV11();
            break;

        case evVersion12:
            res = new QRCodeV12();
            break;

        case evVersion13:
            res = new QRCodeV13();
            break;

        case evVersion14:
            res = new QRCodeV14();
            break;

        case evVersion15:
            res = new QRCodeV15();
            break;

        case evVersion16:
            res = new QRCodeV16();
            break;

        case evVersion17:
            res = new QRCodeV17();
            break;

        case evVersion18:
            res = new QRCodeV18();
            break;

        case evVersion19:
            res = new QRCodeV19();
            break;

        case evVersion20:
            res = new QRCodeV20();
            break;

        case evVersion21:
            res = new QRCodeV21();
            break;

        case evVersion22:
            res = new QRCodeV22();
            break;

        case evVersion23:
            res = new QRCodeV23();
            break;

        case evVersion24:
            res = new QRCodeV24();
            break;

        case evVersion25:
            res = new QRCodeV25();
            break;

        case evVersion26:
            res = new QRCodeV26();
            break;

        case evVersion27:
            res = new QRCodeV27();
            break;

        case evVersion28:
            res = new QRCodeV28();
            break;

        case evVersion29:
            res = new QRCodeV29();
            break;

        case evVersion30:
            res = new QRCodeV30();
            break;

        case evVersion31:
            res = new QRCodeV31();
            break;

        case evVersion32:
            res = new QRCodeV32();
            break;

        case evVersion33:
            res = new QRCodeV33();
            break;

        case evVersion34:
            res = new QRCodeV34();
            break;

        case evVersion35:
            res = new QRCodeV35();
            break;

        case evVersion36:
            res = new QRCodeV36();
            break;

        case evVersion37:
            res = new QRCodeV37();
            break;

        case evVersion38:
            res = new QRCodeV38();
            break;

        case evVersion39:
            res = new QRCodeV39();
            break;

        case evVersion40:
            res = new QRCodeV40();
            break;
    }

    return res;
}
//-------------------------------------------------------------------
