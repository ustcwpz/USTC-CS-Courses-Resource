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

#include "QRCodeV29.h"
#include <string.h>
#include <iomanip>

QRCodeV29::QRCodeV29() : QRCode()
{
    Version             = 29;
    Modules             = 133;
    REMINDER_BIT_COUNT  = 3;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV29::~QRCodeV29()
{

}

//----------------------------------------------------------------
void QRCodeV29::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 3909;
    CAP_L_CORRECTION_ALPHANUMERIC       = 2369;
    CAP_L_CORRECTION_BYTE               = 1628;
    CAP_L_CORRECTION_KANJI              = 1002;

    CAP_M_CORRECTION_NUMERIC            = 3035;
    CAP_M_CORRECTION_ALPHANUMERIC       = 1839;
    CAP_M_CORRECTION_BYTE               = 1264;
    CAP_M_CORRECTION_KANJI              = 778;

    CAP_Q_CORRECTION_NUMERIC            = 2181;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 1322;
    CAP_Q_CORRECTION_BYTE               = 908;
    CAP_Q_CORRECTION_KANJI              = 559;

    CAP_H_CORRECTION_NUMERIC            = 1677;
    CAP_H_CORRECTION_ALPHANUMERIC       = 1016;
    CAP_H_CORRECTION_BYTE               = 698;
    CAP_H_CORRECTION_KANJI              = 430;
}
//----------------------------------------------------------------

void QRCodeV29::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 1631;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 7;
    ECL_LOW_EC_INFO.BlocksGroup2        = 7;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 116;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 117;

    ECL_MEDIUM_EC_INFO.TotalCW          = 1267;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 21;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 7;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 45;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 46;

    ECL_QUALITY_EC_INFO.TotalCW         = 911;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 1;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 37;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 23;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 24;

    ECL_HIGH_EC_INFO.TotalCW            = 701;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 19;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 26;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV29::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(30,6));
    AlignementPatterns.push_back(Point(54,6));
    AlignementPatterns.push_back(Point(78,6));
    AlignementPatterns.push_back(Point(102,6));

    AlignementPatterns.push_back(Point(6,30));
    AlignementPatterns.push_back(Point(30,30));
    AlignementPatterns.push_back(Point(54,30));
    AlignementPatterns.push_back(Point(78,30));
    AlignementPatterns.push_back(Point(102,30));
    AlignementPatterns.push_back(Point(126,30));

    AlignementPatterns.push_back(Point(6,54));
    AlignementPatterns.push_back(Point(30,54));
    AlignementPatterns.push_back(Point(54,54));
    AlignementPatterns.push_back(Point(78,54));
    AlignementPatterns.push_back(Point(102,54));
    AlignementPatterns.push_back(Point(126,54));

    AlignementPatterns.push_back(Point(6,78));
    AlignementPatterns.push_back(Point(30,78));
    AlignementPatterns.push_back(Point(54,78));
    AlignementPatterns.push_back(Point(78,78));
    AlignementPatterns.push_back(Point(102,78));
    AlignementPatterns.push_back(Point(126,78));

    AlignementPatterns.push_back(Point(6,102));
    AlignementPatterns.push_back(Point(30,102));
    AlignementPatterns.push_back(Point(54,102));
    AlignementPatterns.push_back(Point(78,102));
    AlignementPatterns.push_back(Point(102,102));
    AlignementPatterns.push_back(Point(126,102));

    AlignementPatterns.push_back(Point(30,126));
    AlignementPatterns.push_back(Point(54,126));
    AlignementPatterns.push_back(Point(78,126));
    AlignementPatterns.push_back(Point(102,126));
    AlignementPatterns.push_back(Point(126,126));
}
//----------------------------------------------------------------


