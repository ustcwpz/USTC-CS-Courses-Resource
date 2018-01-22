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

#include "QRCodeV31.h"
#include <string.h>
#include <iomanip>

QRCodeV31::QRCodeV31() : QRCode()
{
    Version             = 31;
    Modules             = 141;
    REMINDER_BIT_COUNT  = 3;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV31::~QRCodeV31()
{

}

//----------------------------------------------------------------
void QRCodeV31::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 4417;
    CAP_L_CORRECTION_ALPHANUMERIC       = 2677;
    CAP_L_CORRECTION_BYTE               = 1840;
    CAP_L_CORRECTION_KANJI              = 1132;

    CAP_M_CORRECTION_NUMERIC            = 3486;
    CAP_M_CORRECTION_ALPHANUMERIC       = 2113;
    CAP_M_CORRECTION_BYTE               = 1452;
    CAP_M_CORRECTION_KANJI              = 894;

    CAP_Q_CORRECTION_NUMERIC            = 2473;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 1499;
    CAP_Q_CORRECTION_BYTE               = 1030;
    CAP_Q_CORRECTION_KANJI              = 634;

    CAP_H_CORRECTION_NUMERIC            = 1897;
    CAP_H_CORRECTION_ALPHANUMERIC       = 1150;
    CAP_H_CORRECTION_BYTE               = 790;
    CAP_H_CORRECTION_KANJI              = 486;
}
//----------------------------------------------------------------

void QRCodeV31::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 1843;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 13;
    ECL_LOW_EC_INFO.BlocksGroup2        = 3;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 115;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 116;

    ECL_MEDIUM_EC_INFO.TotalCW          = 1455;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 2;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 29;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 46;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 47;

    ECL_QUALITY_EC_INFO.TotalCW         = 1033;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 42;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 1;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 793;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 23;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 28;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV31::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(30,6));
    AlignementPatterns.push_back(Point(56,6));
    AlignementPatterns.push_back(Point(82,6));
    AlignementPatterns.push_back(Point(108,6));

    AlignementPatterns.push_back(Point(6,30));
    AlignementPatterns.push_back(Point(30,30));
    AlignementPatterns.push_back(Point(56,30));
    AlignementPatterns.push_back(Point(82,30));
    AlignementPatterns.push_back(Point(108,30));
    AlignementPatterns.push_back(Point(134,30));

    AlignementPatterns.push_back(Point(6,56));
    AlignementPatterns.push_back(Point(30,56));
    AlignementPatterns.push_back(Point(56,56));
    AlignementPatterns.push_back(Point(82,56));
    AlignementPatterns.push_back(Point(108,56));
    AlignementPatterns.push_back(Point(134,56));

    AlignementPatterns.push_back(Point(6,82));
    AlignementPatterns.push_back(Point(30,82));
    AlignementPatterns.push_back(Point(56,82));
    AlignementPatterns.push_back(Point(82,82));
    AlignementPatterns.push_back(Point(108,82));
    AlignementPatterns.push_back(Point(134,82));

    AlignementPatterns.push_back(Point(6,108));
    AlignementPatterns.push_back(Point(30,108));
    AlignementPatterns.push_back(Point(56,108));
    AlignementPatterns.push_back(Point(82,108));
    AlignementPatterns.push_back(Point(108,108));
    AlignementPatterns.push_back(Point(134,108));

    AlignementPatterns.push_back(Point(30,134));
    AlignementPatterns.push_back(Point(56,134));
    AlignementPatterns.push_back(Point(82,134));
    AlignementPatterns.push_back(Point(108,134));
    AlignementPatterns.push_back(Point(134,134));
}
//----------------------------------------------------------------


