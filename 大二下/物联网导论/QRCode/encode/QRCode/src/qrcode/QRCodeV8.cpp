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

#include "QRCodeV8.h"
#include <string.h>
#include <iomanip>

QRCodeV8::QRCodeV8() : QRCode()
{
    Version             = 8;
    Modules             = 49;
    REMINDER_BIT_COUNT  = 0;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV8::~QRCodeV8()
{

}

//----------------------------------------------------------------
void QRCodeV8::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 461;
    CAP_L_CORRECTION_ALPHANUMERIC       = 279;
    CAP_L_CORRECTION_BYTE               = 192;
    CAP_L_CORRECTION_KANJI              = 118;

    CAP_M_CORRECTION_NUMERIC            = 365;
    CAP_M_CORRECTION_ALPHANUMERIC       = 221;
    CAP_M_CORRECTION_BYTE               = 152;
    CAP_M_CORRECTION_KANJI              = 93;

    CAP_Q_CORRECTION_NUMERIC            = 259;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 157;
    CAP_Q_CORRECTION_BYTE               = 108;
    CAP_Q_CORRECTION_KANJI              = 66;

    CAP_H_CORRECTION_NUMERIC            = 202;
    CAP_H_CORRECTION_ALPHANUMERIC       = 122;
    CAP_H_CORRECTION_BYTE               = 84;
    CAP_H_CORRECTION_KANJI              = 52;
}
//----------------------------------------------------------------

void QRCodeV8::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 194;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 24;
    ECL_LOW_EC_INFO.BlocksGroup1        = 2;
    ECL_LOW_EC_INFO.BlocksGroup2        = 0;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 97;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 0;

    ECL_MEDIUM_EC_INFO.TotalCW          = 154;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 22;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 2;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 2;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 38;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 39;

    ECL_QUALITY_EC_INFO.TotalCW         = 110;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 22;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 4;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 2;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 18;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 19;

    ECL_HIGH_EC_INFO.TotalCW            = 86;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 26;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 4;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 2;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 14;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 15;
}
//----------------------------------------------------------------

void QRCodeV8::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(24,6));
    AlignementPatterns.push_back(Point(6,24));
    AlignementPatterns.push_back(Point(24,24));
    AlignementPatterns.push_back(Point(42,24));
    AlignementPatterns.push_back(Point(24,42));
    AlignementPatterns.push_back(Point(42,42));
}
//----------------------------------------------------------------


