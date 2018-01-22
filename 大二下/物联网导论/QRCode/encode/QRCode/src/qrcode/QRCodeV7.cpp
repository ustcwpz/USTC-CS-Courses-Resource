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

#include "QRCodeV7.h"
#include <string.h>
#include <iomanip>

QRCodeV7::QRCodeV7() : QRCode()
{
    Version             = 7;
    Modules             = 45;
    REMINDER_BIT_COUNT  = 0;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV7::~QRCodeV7()
{

}

//----------------------------------------------------------------
void QRCodeV7::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 370;
    CAP_L_CORRECTION_ALPHANUMERIC       = 224;
    CAP_L_CORRECTION_BYTE               = 154;
    CAP_L_CORRECTION_KANJI              = 95;

    CAP_M_CORRECTION_NUMERIC            = 293;
    CAP_M_CORRECTION_ALPHANUMERIC       = 178;
    CAP_M_CORRECTION_BYTE               = 122;
    CAP_M_CORRECTION_KANJI              = 75;

    CAP_Q_CORRECTION_NUMERIC            = 207;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 125;
    CAP_Q_CORRECTION_BYTE               = 86;
    CAP_Q_CORRECTION_KANJI              = 53;

    CAP_H_CORRECTION_NUMERIC            = 154;
    CAP_H_CORRECTION_ALPHANUMERIC       = 93;
    CAP_H_CORRECTION_BYTE               = 64;
    CAP_H_CORRECTION_KANJI              = 39;
}
//----------------------------------------------------------------

void QRCodeV7::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 156;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 20;
    ECL_LOW_EC_INFO.BlocksGroup1        = 2;
    ECL_LOW_EC_INFO.BlocksGroup2        = 0;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 78;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 0;

    ECL_MEDIUM_EC_INFO.TotalCW          = 124;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 18;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 4;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 0;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 31;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 0;

    ECL_QUALITY_EC_INFO.TotalCW         = 88;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 18;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 2;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 4;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 14;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 15;

    ECL_HIGH_EC_INFO.TotalCW            = 66;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 26;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 4;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 1;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 13;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 14;
}
//----------------------------------------------------------------

void QRCodeV7::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(22,6));
    AlignementPatterns.push_back(Point(6,22));
    AlignementPatterns.push_back(Point(22,22));
    AlignementPatterns.push_back(Point(38,22));
    AlignementPatterns.push_back(Point(22,38));
    AlignementPatterns.push_back(Point(38,38));
}
//----------------------------------------------------------------


