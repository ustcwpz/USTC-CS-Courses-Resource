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

#include "QRCodeV21.h"
#include <string.h>
#include <iomanip>

QRCodeV21::QRCodeV21() : QRCode()
{
    Version             = 21;
    Modules             = 101;
    REMINDER_BIT_COUNT  = 4;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV21::~QRCodeV21()
{

}

//----------------------------------------------------------------
void QRCodeV21::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 2232;
    CAP_L_CORRECTION_ALPHANUMERIC       = 1352;
    CAP_L_CORRECTION_BYTE               = 929;
    CAP_L_CORRECTION_KANJI              = 572;

    CAP_M_CORRECTION_NUMERIC            = 1708;
    CAP_M_CORRECTION_ALPHANUMERIC       = 1035;
    CAP_M_CORRECTION_BYTE               = 711;
    CAP_M_CORRECTION_KANJI              = 438;

    CAP_Q_CORRECTION_NUMERIC            = 1224;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 742;
    CAP_Q_CORRECTION_BYTE               = 509;
    CAP_Q_CORRECTION_KANJI              = 314;

    CAP_H_CORRECTION_NUMERIC            = 969;
    CAP_H_CORRECTION_ALPHANUMERIC       = 587;
    CAP_H_CORRECTION_BYTE               = 403;
    CAP_H_CORRECTION_KANJI              = 248;
}
//----------------------------------------------------------------

void QRCodeV21::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 932;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 28;
    ECL_LOW_EC_INFO.BlocksGroup1        = 4;
    ECL_LOW_EC_INFO.BlocksGroup2        = 4;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 116;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 117;

    ECL_MEDIUM_EC_INFO.TotalCW          = 714;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 26;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 17;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 0;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 42;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 0;

    ECL_QUALITY_EC_INFO.TotalCW         = 512;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 28;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 17;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 6;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 22;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 23;

    ECL_HIGH_EC_INFO.TotalCW            = 406;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 19;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 6;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 16;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 17;
}
//----------------------------------------------------------------

void QRCodeV21::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(28,6));
    AlignementPatterns.push_back(Point(50,6));
    AlignementPatterns.push_back(Point(72,6));

    AlignementPatterns.push_back(Point(6,28));
    AlignementPatterns.push_back(Point(28,28));
    AlignementPatterns.push_back(Point(50,28));
    AlignementPatterns.push_back(Point(72,28));
    AlignementPatterns.push_back(Point(94,28));

    AlignementPatterns.push_back(Point(6,50));
    AlignementPatterns.push_back(Point(28,50));
    AlignementPatterns.push_back(Point(50,50));
    AlignementPatterns.push_back(Point(72,50));
    AlignementPatterns.push_back(Point(94,50));

    AlignementPatterns.push_back(Point(6,72));
    AlignementPatterns.push_back(Point(28,72));
    AlignementPatterns.push_back(Point(50,72));
    AlignementPatterns.push_back(Point(72,72));
    AlignementPatterns.push_back(Point(94,72));

    AlignementPatterns.push_back(Point(28,94));
    AlignementPatterns.push_back(Point(50,94));
    AlignementPatterns.push_back(Point(72,94));
    AlignementPatterns.push_back(Point(94,94));
}
//----------------------------------------------------------------


