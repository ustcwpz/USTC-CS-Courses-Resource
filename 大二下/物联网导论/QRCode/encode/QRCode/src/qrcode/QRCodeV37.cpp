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

#include "QRCodeV37.h"
#include <string.h>
#include <iomanip>

QRCodeV37::QRCodeV37() : QRCode()
{
    Version             = 37;
    Modules             = 165;
    REMINDER_BIT_COUNT  = 0;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV37::~QRCodeV37()
{

}

//----------------------------------------------------------------
void QRCodeV37::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 6153;
    CAP_L_CORRECTION_ALPHANUMERIC       = 3729;
    CAP_L_CORRECTION_BYTE               = 2563;
    CAP_L_CORRECTION_KANJI              = 1577;

    CAP_M_CORRECTION_NUMERIC            = 4775;
    CAP_M_CORRECTION_ALPHANUMERIC       = 2894;
    CAP_M_CORRECTION_BYTE               = 1989;
    CAP_M_CORRECTION_KANJI              = 1224;

    CAP_Q_CORRECTION_NUMERIC            = 3417;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 2071;
    CAP_Q_CORRECTION_BYTE               = 1423;
    CAP_Q_CORRECTION_KANJI              = 876;

    CAP_H_CORRECTION_NUMERIC            = 2625;
    CAP_H_CORRECTION_ALPHANUMERIC       = 1591;
    CAP_H_CORRECTION_BYTE               = 1093;
    CAP_H_CORRECTION_KANJI              = 673;
}
//----------------------------------------------------------------

void QRCodeV37::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 2566;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 17;
    ECL_LOW_EC_INFO.BlocksGroup2        = 4;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 122;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 123;

    ECL_MEDIUM_EC_INFO.TotalCW          = 1992;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 29;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 14;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 46;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 47;

    ECL_QUALITY_EC_INFO.TotalCW         = 1426;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 49;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 10;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 1096;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 24;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 46;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV37::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(28,6));
    AlignementPatterns.push_back(Point(54,6));
    AlignementPatterns.push_back(Point(80,6));
    AlignementPatterns.push_back(Point(106,6));
    AlignementPatterns.push_back(Point(132,6));

    AlignementPatterns.push_back(Point(6,28));
    AlignementPatterns.push_back(Point(28,28));
    AlignementPatterns.push_back(Point(54,28));
    AlignementPatterns.push_back(Point(80,28));
    AlignementPatterns.push_back(Point(106,28));
    AlignementPatterns.push_back(Point(132,28));
    AlignementPatterns.push_back(Point(158,28));

    AlignementPatterns.push_back(Point(6,54));
    AlignementPatterns.push_back(Point(28,54));
    AlignementPatterns.push_back(Point(54,54));
    AlignementPatterns.push_back(Point(80,54));
    AlignementPatterns.push_back(Point(106,54));
    AlignementPatterns.push_back(Point(132,54));
    AlignementPatterns.push_back(Point(158,54));

    AlignementPatterns.push_back(Point(6,80));
    AlignementPatterns.push_back(Point(28,80));
    AlignementPatterns.push_back(Point(54,80));
    AlignementPatterns.push_back(Point(80,80));
    AlignementPatterns.push_back(Point(106,80));
    AlignementPatterns.push_back(Point(132,80));
    AlignementPatterns.push_back(Point(158,80));

    AlignementPatterns.push_back(Point(6,106));
    AlignementPatterns.push_back(Point(28,106));
    AlignementPatterns.push_back(Point(54,106));
    AlignementPatterns.push_back(Point(80,106));
    AlignementPatterns.push_back(Point(106,106));
    AlignementPatterns.push_back(Point(132,106));
    AlignementPatterns.push_back(Point(158,106));

    AlignementPatterns.push_back(Point(6,132));
    AlignementPatterns.push_back(Point(28,132));
    AlignementPatterns.push_back(Point(54,132));
    AlignementPatterns.push_back(Point(80,132));
    AlignementPatterns.push_back(Point(106,132));
    AlignementPatterns.push_back(Point(132,132));
    AlignementPatterns.push_back(Point(158,132));

    AlignementPatterns.push_back(Point(28,158));
    AlignementPatterns.push_back(Point(54,158));
    AlignementPatterns.push_back(Point(80,158));
    AlignementPatterns.push_back(Point(106,158));
    AlignementPatterns.push_back(Point(132,158));
    AlignementPatterns.push_back(Point(158,158));
}
//----------------------------------------------------------------


