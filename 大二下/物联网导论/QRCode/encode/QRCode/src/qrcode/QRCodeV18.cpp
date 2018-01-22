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

#include "QRCodeV18.h"
#include <string.h>
#include <iomanip>

QRCodeV18::QRCodeV18() : QRCode()
{
    Version             = 18;
    Modules             = 89;
    REMINDER_BIT_COUNT  = 3;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV18::~QRCodeV18()
{

}

//----------------------------------------------------------------
void QRCodeV18::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 1725;
    CAP_L_CORRECTION_ALPHANUMERIC       = 1046;
    CAP_L_CORRECTION_BYTE               = 718;
    CAP_L_CORRECTION_KANJI              = 442;

    CAP_M_CORRECTION_NUMERIC            = 1346;
    CAP_M_CORRECTION_ALPHANUMERIC       = 816;
    CAP_M_CORRECTION_BYTE               = 560;
    CAP_M_CORRECTION_KANJI              = 345;

    CAP_Q_CORRECTION_NUMERIC            = 948;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 574;
    CAP_Q_CORRECTION_BYTE               = 394;
    CAP_Q_CORRECTION_KANJI              = 243;

    CAP_H_CORRECTION_NUMERIC            = 746;
    CAP_H_CORRECTION_ALPHANUMERIC       = 452;
    CAP_H_CORRECTION_BYTE               = 310;
    CAP_H_CORRECTION_KANJI              = 191;
}
//----------------------------------------------------------------

void QRCodeV18::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 721;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 5;
    ECL_LOW_EC_INFO.BlocksGroup2        = 1;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 120;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 121;

    ECL_MEDIUM_EC_INFO.TotalCW          = 563;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 26;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 9;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 4;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 43;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 44;

    ECL_QUALITY_EC_INFO.TotalCW         = 397;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 28;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 17;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 1;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 22;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 23;

    ECL_HIGH_EC_INFO.TotalCW            = 313;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 28;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 2;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 19;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 14;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 15;
}
//----------------------------------------------------------------

void QRCodeV18::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(30,6));
    AlignementPatterns.push_back(Point(6,30));
    AlignementPatterns.push_back(Point(30,30));
    AlignementPatterns.push_back(Point(6,56));
    AlignementPatterns.push_back(Point(56,6));

    AlignementPatterns.push_back(Point(30,56));
    AlignementPatterns.push_back(Point(56,30));
    AlignementPatterns.push_back(Point(56,56));
    AlignementPatterns.push_back(Point(30,82));
    AlignementPatterns.push_back(Point(82,30));

    AlignementPatterns.push_back(Point(56,82));
    AlignementPatterns.push_back(Point(82,56));
    AlignementPatterns.push_back(Point(82,82));
}
//----------------------------------------------------------------


