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

#include "QRCodeV30.h"
#include <string.h>
#include <iomanip>

QRCodeV30::QRCodeV30() : QRCode()
{
    Version             = 30;
    Modules             = 137;
    REMINDER_BIT_COUNT  = 3;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV30::~QRCodeV30()
{

}

//----------------------------------------------------------------
void QRCodeV30::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 4158;
    CAP_L_CORRECTION_ALPHANUMERIC       = 2520;
    CAP_L_CORRECTION_BYTE               = 1732;
    CAP_L_CORRECTION_KANJI              = 1066;

    CAP_M_CORRECTION_NUMERIC            = 3289;
    CAP_M_CORRECTION_ALPHANUMERIC       = 1994;
    CAP_M_CORRECTION_BYTE               = 1370;
    CAP_M_CORRECTION_KANJI              = 843;

    CAP_Q_CORRECTION_NUMERIC            = 2358;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 1429;
    CAP_Q_CORRECTION_BYTE               = 982;
    CAP_Q_CORRECTION_KANJI              = 604;

    CAP_H_CORRECTION_NUMERIC            = 1782;
    CAP_H_CORRECTION_ALPHANUMERIC       = 1080;
    CAP_H_CORRECTION_BYTE               = 742;
    CAP_H_CORRECTION_KANJI              = 457;
}
//----------------------------------------------------------------

void QRCodeV30::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 1735;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 5;
    ECL_LOW_EC_INFO.BlocksGroup2        = 10;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 115;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 116;

    ECL_MEDIUM_EC_INFO.TotalCW          = 1373;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 19;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 10;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 47;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 48;

    ECL_QUALITY_EC_INFO.TotalCW         = 985;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 15;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 25;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 745;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 23;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 25;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV30::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(26,6));
    AlignementPatterns.push_back(Point(52,6));
    AlignementPatterns.push_back(Point(78,6));
    AlignementPatterns.push_back(Point(104,6));

    AlignementPatterns.push_back(Point(6,26));
    AlignementPatterns.push_back(Point(26,26));
    AlignementPatterns.push_back(Point(52,26));
    AlignementPatterns.push_back(Point(78,26));
    AlignementPatterns.push_back(Point(104,26));
    AlignementPatterns.push_back(Point(130,26));

    AlignementPatterns.push_back(Point(6,52));
    AlignementPatterns.push_back(Point(26,52));
    AlignementPatterns.push_back(Point(52,52));
    AlignementPatterns.push_back(Point(78,52));
    AlignementPatterns.push_back(Point(104,52));
    AlignementPatterns.push_back(Point(130,52));

    AlignementPatterns.push_back(Point(6,78));
    AlignementPatterns.push_back(Point(26,78));
    AlignementPatterns.push_back(Point(52,78));
    AlignementPatterns.push_back(Point(78,78));
    AlignementPatterns.push_back(Point(104,78));
    AlignementPatterns.push_back(Point(130,78));

    AlignementPatterns.push_back(Point(6,104));
    AlignementPatterns.push_back(Point(26,104));
    AlignementPatterns.push_back(Point(52,104));
    AlignementPatterns.push_back(Point(78,104));
    AlignementPatterns.push_back(Point(104,104));
    AlignementPatterns.push_back(Point(130,104));

    AlignementPatterns.push_back(Point(26,130));
    AlignementPatterns.push_back(Point(52,130));
    AlignementPatterns.push_back(Point(78,130));
    AlignementPatterns.push_back(Point(104,130));
    AlignementPatterns.push_back(Point(130,130));
}
//----------------------------------------------------------------


