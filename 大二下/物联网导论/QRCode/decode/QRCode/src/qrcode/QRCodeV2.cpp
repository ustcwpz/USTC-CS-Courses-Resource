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

#include "QRCodeV2.h"
#include <string.h>
#include <iomanip>

QRCodeV2::QRCodeV2() : QRCode()
{
    Version             = 2;
    Modules             = 25;
    REMINDER_BIT_COUNT  = 7;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV2::~QRCodeV2()
{

}

//----------------------------------------------------------------
void QRCodeV2::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 77;
    CAP_L_CORRECTION_ALPHANUMERIC       = 47;
    CAP_L_CORRECTION_BYTE               = 32;
    CAP_L_CORRECTION_KANJI              = 20;

    CAP_M_CORRECTION_NUMERIC            = 63;
    CAP_M_CORRECTION_ALPHANUMERIC       = 38;
    CAP_M_CORRECTION_BYTE               = 26;
    CAP_M_CORRECTION_KANJI              = 16;

    CAP_Q_CORRECTION_NUMERIC            = 48;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 29;
    CAP_Q_CORRECTION_BYTE               = 20;
    CAP_Q_CORRECTION_KANJI              = 12;

    CAP_H_CORRECTION_NUMERIC            = 34;
    CAP_H_CORRECTION_ALPHANUMERIC       = 20;
    CAP_H_CORRECTION_BYTE               = 14;
    CAP_H_CORRECTION_KANJI              = 8;
}
//----------------------------------------------------------------

void QRCodeV2::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 34;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 10;
    ECL_LOW_EC_INFO.BlocksGroup1        = 1;
    ECL_LOW_EC_INFO.BlocksGroup2        = 0;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 34;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 0;

    ECL_MEDIUM_EC_INFO.TotalCW          = 28;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 16;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 1;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 0;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 28;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 0;

    ECL_QUALITY_EC_INFO.TotalCW         = 22;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 22;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 1;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 0;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 22;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 0;

    ECL_HIGH_EC_INFO.TotalCW            = 16;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 28;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 1;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 0;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 16;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 0;
}
//----------------------------------------------------------------

void QRCodeV2::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(18,18));
}
//----------------------------------------------------------------


