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
#include "QRCodeV35.h"
#include <string.h>
#include <iomanip>

QRCodeV35::QRCodeV35() : QRCode()
{
    Version             = 35;
    Modules             = 157;
    REMINDER_BIT_COUNT  = 0;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV35::~QRCodeV35()
{

}

//----------------------------------------------------------------
void QRCodeV35::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 5529;
    CAP_L_CORRECTION_ALPHANUMERIC       = 3351;
    CAP_L_CORRECTION_BYTE               = 2303;
    CAP_L_CORRECTION_KANJI              = 1417;

    CAP_M_CORRECTION_NUMERIC            = 4343;
    CAP_M_CORRECTION_ALPHANUMERIC       = 2632;
    CAP_M_CORRECTION_BYTE               = 1809;
    CAP_M_CORRECTION_KANJI              = 1113;

    CAP_Q_CORRECTION_NUMERIC            = 3081;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 1867;
    CAP_Q_CORRECTION_BYTE               = 1283;
    CAP_Q_CORRECTION_KANJI              = 790;

    CAP_H_CORRECTION_NUMERIC            = 2361;
    CAP_H_CORRECTION_ALPHANUMERIC       = 1431;
    CAP_H_CORRECTION_BYTE               = 983;
    CAP_H_CORRECTION_KANJI              = 605;
}
//----------------------------------------------------------------

void QRCodeV35::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 2306;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 12;
    ECL_LOW_EC_INFO.BlocksGroup2        = 7;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 121;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 122;

    ECL_MEDIUM_EC_INFO.TotalCW          = 1812;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 12;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 26;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 47;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 48;

    ECL_QUALITY_EC_INFO.TotalCW         = 1286;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 39;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 14;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 986;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 22;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 41;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV35::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(30,6));
    AlignementPatterns.push_back(Point(54,6));
    AlignementPatterns.push_back(Point(78,6));
    AlignementPatterns.push_back(Point(102,6));
    AlignementPatterns.push_back(Point(126,6));

    AlignementPatterns.push_back(Point(6,30));
    AlignementPatterns.push_back(Point(30,30));
    AlignementPatterns.push_back(Point(54,30));
    AlignementPatterns.push_back(Point(78,30));
    AlignementPatterns.push_back(Point(102,30));
    AlignementPatterns.push_back(Point(126,30));
    AlignementPatterns.push_back(Point(150,30));

    AlignementPatterns.push_back(Point(6,54));
    AlignementPatterns.push_back(Point(30,54));
    AlignementPatterns.push_back(Point(54,54));
    AlignementPatterns.push_back(Point(78,54));
    AlignementPatterns.push_back(Point(102,54));
    AlignementPatterns.push_back(Point(126,54));
    AlignementPatterns.push_back(Point(150,54));

    AlignementPatterns.push_back(Point(6,78));
    AlignementPatterns.push_back(Point(30,78));
    AlignementPatterns.push_back(Point(54,78));
    AlignementPatterns.push_back(Point(78,78));
    AlignementPatterns.push_back(Point(102,78));
    AlignementPatterns.push_back(Point(126,78));
    AlignementPatterns.push_back(Point(150,78));

    AlignementPatterns.push_back(Point(6,102));
    AlignementPatterns.push_back(Point(30,102));
    AlignementPatterns.push_back(Point(54,102));
    AlignementPatterns.push_back(Point(78,102));
    AlignementPatterns.push_back(Point(102,102));
    AlignementPatterns.push_back(Point(126,102));
    AlignementPatterns.push_back(Point(150,102));

    AlignementPatterns.push_back(Point(6,126));
    AlignementPatterns.push_back(Point(30,126));
    AlignementPatterns.push_back(Point(54,126));
    AlignementPatterns.push_back(Point(78,126));
    AlignementPatterns.push_back(Point(102,126));
    AlignementPatterns.push_back(Point(126,126));
    AlignementPatterns.push_back(Point(150,126));

    AlignementPatterns.push_back(Point(30,150));
    AlignementPatterns.push_back(Point(54,150));
    AlignementPatterns.push_back(Point(78,150));
    AlignementPatterns.push_back(Point(102,150));
    AlignementPatterns.push_back(Point(126,150));
    AlignementPatterns.push_back(Point(150,150));
}
//----------------------------------------------------------------


