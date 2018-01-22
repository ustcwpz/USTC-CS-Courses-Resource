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

#include "QRCodeV10.h"
#include <string.h>
#include <iomanip>

QRCodeV10::QRCodeV10() : QRCode()
{
    Version             = 10;
    Modules             = 57;
    REMINDER_BIT_COUNT  = 0;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV10::~QRCodeV10()
{

}

//----------------------------------------------------------------
void QRCodeV10::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 652;
    CAP_L_CORRECTION_ALPHANUMERIC       = 395;
    CAP_L_CORRECTION_BYTE               = 271;
    CAP_L_CORRECTION_KANJI              = 167;

    CAP_M_CORRECTION_NUMERIC            = 513;
    CAP_M_CORRECTION_ALPHANUMERIC       = 311;
    CAP_M_CORRECTION_BYTE               = 213;
    CAP_M_CORRECTION_KANJI              = 131;

    CAP_Q_CORRECTION_NUMERIC            = 364;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 221;
    CAP_Q_CORRECTION_BYTE               = 151;
    CAP_Q_CORRECTION_KANJI              = 93;

    CAP_H_CORRECTION_NUMERIC            = 288;
    CAP_H_CORRECTION_ALPHANUMERIC       = 174;
    CAP_H_CORRECTION_BYTE               = 119;
    CAP_H_CORRECTION_KANJI              = 74;
}
//----------------------------------------------------------------

void QRCodeV10::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 274;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 18;
    ECL_LOW_EC_INFO.BlocksGroup1        = 2;
    ECL_LOW_EC_INFO.BlocksGroup2        = 2;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 68;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 69;

    ECL_MEDIUM_EC_INFO.TotalCW          = 216;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 26;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 4;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 1;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 43;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 44;

    ECL_QUALITY_EC_INFO.TotalCW         = 154;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 24;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 6;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 2;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 19;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 20;

    ECL_HIGH_EC_INFO.TotalCW            = 122;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 28;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 6;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 2;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV10::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(28,6));
    AlignementPatterns.push_back(Point(6,28));
    AlignementPatterns.push_back(Point(28,28));
    AlignementPatterns.push_back(Point(50,28));
    AlignementPatterns.push_back(Point(28,50));
    AlignementPatterns.push_back(Point(50,50));
}
//----------------------------------------------------------------


