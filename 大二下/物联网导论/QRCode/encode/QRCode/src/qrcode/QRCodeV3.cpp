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

#include "QRCodeV3.h"
#include <string.h>
#include <iomanip>

QRCodeV3::QRCodeV3() : QRCode()
{
    Version             = 3;
    Modules             = 29;
    REMINDER_BIT_COUNT  = 7;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV3::~QRCodeV3()
{

}

//----------------------------------------------------------------
void QRCodeV3::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 127;
    CAP_L_CORRECTION_ALPHANUMERIC       = 77;
    CAP_L_CORRECTION_BYTE               = 53;
    CAP_L_CORRECTION_KANJI              = 32;

    CAP_M_CORRECTION_NUMERIC            = 101;
    CAP_M_CORRECTION_ALPHANUMERIC       = 61;
    CAP_M_CORRECTION_BYTE               = 42;
    CAP_M_CORRECTION_KANJI              = 26;

    CAP_Q_CORRECTION_NUMERIC            = 77;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 47;
    CAP_Q_CORRECTION_BYTE               = 32;
    CAP_Q_CORRECTION_KANJI              = 20;

    CAP_H_CORRECTION_NUMERIC            = 58;
    CAP_H_CORRECTION_ALPHANUMERIC       = 35;
    CAP_H_CORRECTION_BYTE               = 24;
    CAP_H_CORRECTION_KANJI              = 15;
}
//----------------------------------------------------------------

void QRCodeV3::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 55;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 15;
    ECL_LOW_EC_INFO.BlocksGroup1        = 1;
    ECL_LOW_EC_INFO.BlocksGroup2        = 0;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 55;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 0;

    ECL_MEDIUM_EC_INFO.TotalCW          = 44;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 26;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 1;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 0;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 44;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 0;

    ECL_QUALITY_EC_INFO.TotalCW         = 34;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 18;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 2;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 0;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 17;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 0;

    ECL_HIGH_EC_INFO.TotalCW            = 26;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 22;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 2;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 0;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 13;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 0;
}
//----------------------------------------------------------------

void QRCodeV3::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(22,22));
}
//----------------------------------------------------------------


