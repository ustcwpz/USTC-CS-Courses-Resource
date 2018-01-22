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

#include "QRCodeV39.h"
#include <string.h>
#include <iomanip>

QRCodeV39::QRCodeV39() : QRCode()
{
    Version             = 39;
    Modules             = 173;
    REMINDER_BIT_COUNT  = 0;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV39::~QRCodeV39()
{

}

//----------------------------------------------------------------
void QRCodeV39::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 6743;
    CAP_L_CORRECTION_ALPHANUMERIC       = 4087;
    CAP_L_CORRECTION_BYTE               = 2809;
    CAP_L_CORRECTION_KANJI              = 1729;

    CAP_M_CORRECTION_NUMERIC            = 5313;
    CAP_M_CORRECTION_ALPHANUMERIC       = 3220;
    CAP_M_CORRECTION_BYTE               = 2213;
    CAP_M_CORRECTION_KANJI              = 1362;

    CAP_Q_CORRECTION_NUMERIC            = 3791;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 2298;
    CAP_Q_CORRECTION_BYTE               = 1579;
    CAP_Q_CORRECTION_KANJI              = 972;

    CAP_H_CORRECTION_NUMERIC            = 2927;
    CAP_H_CORRECTION_ALPHANUMERIC       = 1774;
    CAP_H_CORRECTION_BYTE               = 1219;
    CAP_H_CORRECTION_KANJI              = 750;
}
//----------------------------------------------------------------

void QRCodeV39::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 2812;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 20;
    ECL_LOW_EC_INFO.BlocksGroup2        = 4;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 117;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 118;

    ECL_MEDIUM_EC_INFO.TotalCW          = 2216;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 40;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 7;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 47;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 48;

    ECL_QUALITY_EC_INFO.TotalCW         = 1582;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 43;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 22;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 1222;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 10;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 67;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV39::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(26,6));
    AlignementPatterns.push_back(Point(54,6));
    AlignementPatterns.push_back(Point(82,6));
    AlignementPatterns.push_back(Point(110,6));
    AlignementPatterns.push_back(Point(138,6));

    AlignementPatterns.push_back(Point(6,26));
    AlignementPatterns.push_back(Point(26,26));
    AlignementPatterns.push_back(Point(54,26));
    AlignementPatterns.push_back(Point(82,26));
    AlignementPatterns.push_back(Point(110,26));
    AlignementPatterns.push_back(Point(138,26));
    AlignementPatterns.push_back(Point(166,26));

    AlignementPatterns.push_back(Point(6,54));
    AlignementPatterns.push_back(Point(26,54));
    AlignementPatterns.push_back(Point(54,54));
    AlignementPatterns.push_back(Point(82,54));
    AlignementPatterns.push_back(Point(110,54));
    AlignementPatterns.push_back(Point(138,54));
    AlignementPatterns.push_back(Point(166,54));

    AlignementPatterns.push_back(Point(6,82));
    AlignementPatterns.push_back(Point(26,82));
    AlignementPatterns.push_back(Point(54,82));
    AlignementPatterns.push_back(Point(82,82));
    AlignementPatterns.push_back(Point(110,82));
    AlignementPatterns.push_back(Point(138,82));
    AlignementPatterns.push_back(Point(166,82));

    AlignementPatterns.push_back(Point(6,110));
    AlignementPatterns.push_back(Point(26,110));
    AlignementPatterns.push_back(Point(54,110));
    AlignementPatterns.push_back(Point(82,110));
    AlignementPatterns.push_back(Point(110,110));
    AlignementPatterns.push_back(Point(138,110));
    AlignementPatterns.push_back(Point(166,110));

    AlignementPatterns.push_back(Point(6,138));
    AlignementPatterns.push_back(Point(26,138));
    AlignementPatterns.push_back(Point(54,138));
    AlignementPatterns.push_back(Point(82,138));
    AlignementPatterns.push_back(Point(110,138));
    AlignementPatterns.push_back(Point(138,138));
    AlignementPatterns.push_back(Point(166,138));

    AlignementPatterns.push_back(Point(26,166));
    AlignementPatterns.push_back(Point(54,166));
    AlignementPatterns.push_back(Point(82,166));
    AlignementPatterns.push_back(Point(110,166));
    AlignementPatterns.push_back(Point(138,166));
    AlignementPatterns.push_back(Point(166,166));
}
//----------------------------------------------------------------


