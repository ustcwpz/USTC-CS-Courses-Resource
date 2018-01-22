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

#include "QRCodeV40.h"
#include <string.h>
#include <iomanip>

QRCodeV40::QRCodeV40() : QRCode()
{
    Version             = 40;
    Modules             = 177;
    REMINDER_BIT_COUNT  = 0;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV40::~QRCodeV40()
{

}

//----------------------------------------------------------------
void QRCodeV40::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 7089;
    CAP_L_CORRECTION_ALPHANUMERIC       = 4296;
    CAP_L_CORRECTION_BYTE               = 2953;
    CAP_L_CORRECTION_KANJI              = 1817;

    CAP_M_CORRECTION_NUMERIC            = 5596;
    CAP_M_CORRECTION_ALPHANUMERIC       = 3391;
    CAP_M_CORRECTION_BYTE               = 2331;
    CAP_M_CORRECTION_KANJI              = 1435;

    CAP_Q_CORRECTION_NUMERIC            = 3993;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 2420;
    CAP_Q_CORRECTION_BYTE               = 1663;
    CAP_Q_CORRECTION_KANJI              = 1024;

    CAP_H_CORRECTION_NUMERIC            = 3057;
    CAP_H_CORRECTION_ALPHANUMERIC       = 1852;
    CAP_H_CORRECTION_BYTE               = 1273;
    CAP_H_CORRECTION_KANJI              = 784;
}
//----------------------------------------------------------------

void QRCodeV40::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 2956;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 19;
    ECL_LOW_EC_INFO.BlocksGroup2        = 6;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 118;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 119;

    ECL_MEDIUM_EC_INFO.TotalCW          = 2334;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 18;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 31;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 47;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 48;

    ECL_QUALITY_EC_INFO.TotalCW         = 1666;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 34;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 34;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 1276;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 20;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 61;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV40::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(30,6));
    AlignementPatterns.push_back(Point(58,6));
    AlignementPatterns.push_back(Point(86,6));
    AlignementPatterns.push_back(Point(114,6));
    AlignementPatterns.push_back(Point(142,6));

    AlignementPatterns.push_back(Point(6,30));
    AlignementPatterns.push_back(Point(30,30));
    AlignementPatterns.push_back(Point(58,30));
    AlignementPatterns.push_back(Point(86,30));
    AlignementPatterns.push_back(Point(114,30));
    AlignementPatterns.push_back(Point(142,30));
    AlignementPatterns.push_back(Point(170,30));

    AlignementPatterns.push_back(Point(6,58));
    AlignementPatterns.push_back(Point(30,58));
    AlignementPatterns.push_back(Point(58,58));
    AlignementPatterns.push_back(Point(86,58));
    AlignementPatterns.push_back(Point(114,58));
    AlignementPatterns.push_back(Point(142,58));
    AlignementPatterns.push_back(Point(170,58));

    AlignementPatterns.push_back(Point(6,86));
    AlignementPatterns.push_back(Point(30,86));
    AlignementPatterns.push_back(Point(58,86));
    AlignementPatterns.push_back(Point(86,86));
    AlignementPatterns.push_back(Point(114,86));
    AlignementPatterns.push_back(Point(142,86));
    AlignementPatterns.push_back(Point(170,86));

    AlignementPatterns.push_back(Point(6,114));
    AlignementPatterns.push_back(Point(30,114));
    AlignementPatterns.push_back(Point(58,114));
    AlignementPatterns.push_back(Point(86,114));
    AlignementPatterns.push_back(Point(114,114));
    AlignementPatterns.push_back(Point(142,114));
    AlignementPatterns.push_back(Point(170,114));

    AlignementPatterns.push_back(Point(6,142));
    AlignementPatterns.push_back(Point(30,142));
    AlignementPatterns.push_back(Point(58,142));
    AlignementPatterns.push_back(Point(86,142));
    AlignementPatterns.push_back(Point(114,142));
    AlignementPatterns.push_back(Point(142,142));
    AlignementPatterns.push_back(Point(170,142));

    AlignementPatterns.push_back(Point(30,170));
    AlignementPatterns.push_back(Point(58,170));
    AlignementPatterns.push_back(Point(86,170));
    AlignementPatterns.push_back(Point(114,170));
    AlignementPatterns.push_back(Point(142,170));
    AlignementPatterns.push_back(Point(170,170));
}
//----------------------------------------------------------------


