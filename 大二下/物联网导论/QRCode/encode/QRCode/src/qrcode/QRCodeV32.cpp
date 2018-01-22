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

#include "QRCodeV32.h"
#include <string.h>
#include <iomanip>

QRCodeV32::QRCodeV32() : QRCode()
{
    Version             = 32;
    Modules             = 145;
    REMINDER_BIT_COUNT  = 3;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV32::~QRCodeV32()
{

}

//----------------------------------------------------------------
void QRCodeV32::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 4686;
    CAP_L_CORRECTION_ALPHANUMERIC       = 2840;
    CAP_L_CORRECTION_BYTE               = 1952;
    CAP_L_CORRECTION_KANJI              = 1201;

    CAP_M_CORRECTION_NUMERIC            = 3693;
    CAP_M_CORRECTION_ALPHANUMERIC       = 2238;
    CAP_M_CORRECTION_BYTE               = 1538;
    CAP_M_CORRECTION_KANJI              = 947;

    CAP_Q_CORRECTION_NUMERIC            = 2670;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 1618;
    CAP_Q_CORRECTION_BYTE               = 1112;
    CAP_Q_CORRECTION_KANJI              = 684;

    CAP_H_CORRECTION_NUMERIC            = 2022;
    CAP_H_CORRECTION_ALPHANUMERIC       = 1226;
    CAP_H_CORRECTION_BYTE               = 842;
    CAP_H_CORRECTION_KANJI              = 518;
}
//----------------------------------------------------------------

void QRCodeV32::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 1955;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 17;
    ECL_LOW_EC_INFO.BlocksGroup2        = 0;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 115;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 0;

    ECL_MEDIUM_EC_INFO.TotalCW          = 1541;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 10;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 23;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 46;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 47;

    ECL_QUALITY_EC_INFO.TotalCW         = 1115;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 10;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 35;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 845;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 19;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 35;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV32::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(34,6));
    AlignementPatterns.push_back(Point(60,6));
    AlignementPatterns.push_back(Point(86,6));
    AlignementPatterns.push_back(Point(112,6));

    AlignementPatterns.push_back(Point(6,34));
    AlignementPatterns.push_back(Point(34,34));
    AlignementPatterns.push_back(Point(60,34));
    AlignementPatterns.push_back(Point(86,34));
    AlignementPatterns.push_back(Point(112,34));
    AlignementPatterns.push_back(Point(138,34));

    AlignementPatterns.push_back(Point(6,60));
    AlignementPatterns.push_back(Point(34,60));
    AlignementPatterns.push_back(Point(60,60));
    AlignementPatterns.push_back(Point(86,60));
    AlignementPatterns.push_back(Point(112,60));
    AlignementPatterns.push_back(Point(138,60));

    AlignementPatterns.push_back(Point(6,86));
    AlignementPatterns.push_back(Point(34,86));
    AlignementPatterns.push_back(Point(60,86));
    AlignementPatterns.push_back(Point(86,86));
    AlignementPatterns.push_back(Point(112,86));
    AlignementPatterns.push_back(Point(138,86));

    AlignementPatterns.push_back(Point(6,112));
    AlignementPatterns.push_back(Point(34,112));
    AlignementPatterns.push_back(Point(60,112));
    AlignementPatterns.push_back(Point(86,112));
    AlignementPatterns.push_back(Point(112,112));
    AlignementPatterns.push_back(Point(138,112));

    AlignementPatterns.push_back(Point(34,138));
    AlignementPatterns.push_back(Point(60,138));
    AlignementPatterns.push_back(Point(86,138));
    AlignementPatterns.push_back(Point(112,138));
    AlignementPatterns.push_back(Point(138,138));
}
//----------------------------------------------------------------


