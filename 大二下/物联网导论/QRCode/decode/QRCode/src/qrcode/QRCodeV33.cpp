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

#include "QRCodeV33.h"
#include <string.h>
#include <iomanip>

QRCodeV33::QRCodeV33() : QRCode()
{
    Version             = 33;
    Modules             = 149;
    REMINDER_BIT_COUNT  = 3;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV33::~QRCodeV33()
{

}

//----------------------------------------------------------------
void QRCodeV33::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 4965;
    CAP_L_CORRECTION_ALPHANUMERIC       = 3009;
    CAP_L_CORRECTION_BYTE               = 2068;
    CAP_L_CORRECTION_KANJI              = 1273;

    CAP_M_CORRECTION_NUMERIC            = 3909;
    CAP_M_CORRECTION_ALPHANUMERIC       = 2369;
    CAP_M_CORRECTION_BYTE               = 1628;
    CAP_M_CORRECTION_KANJI              = 1002;

    CAP_Q_CORRECTION_NUMERIC            = 2805;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 1700;
    CAP_Q_CORRECTION_BYTE               = 1168;
    CAP_Q_CORRECTION_KANJI              = 719;

    CAP_H_CORRECTION_NUMERIC            = 2157;
    CAP_H_CORRECTION_ALPHANUMERIC       = 1307;
    CAP_H_CORRECTION_BYTE               = 898;
    CAP_H_CORRECTION_KANJI              = 553;
}
//----------------------------------------------------------------

void QRCodeV33::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 2071;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 17;
    ECL_LOW_EC_INFO.BlocksGroup2        = 1;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 115;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 116;

    ECL_MEDIUM_EC_INFO.TotalCW          = 1631;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 14;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 21;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 46;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 47;

    ECL_QUALITY_EC_INFO.TotalCW         = 1171;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 29;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 19;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 901;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 11;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 46;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV33::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(30,6));
    AlignementPatterns.push_back(Point(58,6));
    AlignementPatterns.push_back(Point(86,6));
    AlignementPatterns.push_back(Point(114,6));

    AlignementPatterns.push_back(Point(6,30));
    AlignementPatterns.push_back(Point(30,30));
    AlignementPatterns.push_back(Point(58,30));
    AlignementPatterns.push_back(Point(86,30));
    AlignementPatterns.push_back(Point(114,30));
    AlignementPatterns.push_back(Point(142,30));

    AlignementPatterns.push_back(Point(6,58));
    AlignementPatterns.push_back(Point(30,58));
    AlignementPatterns.push_back(Point(58,58));
    AlignementPatterns.push_back(Point(86,58));
    AlignementPatterns.push_back(Point(114,58));
    AlignementPatterns.push_back(Point(142,58));

    AlignementPatterns.push_back(Point(6,86));
    AlignementPatterns.push_back(Point(30,86));
    AlignementPatterns.push_back(Point(58,86));
    AlignementPatterns.push_back(Point(86,86));
    AlignementPatterns.push_back(Point(114,86));
    AlignementPatterns.push_back(Point(142,86));

    AlignementPatterns.push_back(Point(6,114));
    AlignementPatterns.push_back(Point(30,114));
    AlignementPatterns.push_back(Point(58,114));
    AlignementPatterns.push_back(Point(86,114));
    AlignementPatterns.push_back(Point(114,114));
    AlignementPatterns.push_back(Point(142,114));

    AlignementPatterns.push_back(Point(30,142));
    AlignementPatterns.push_back(Point(58,142));
    AlignementPatterns.push_back(Point(86,142));
    AlignementPatterns.push_back(Point(114,142));
    AlignementPatterns.push_back(Point(142,142));
}
//----------------------------------------------------------------


