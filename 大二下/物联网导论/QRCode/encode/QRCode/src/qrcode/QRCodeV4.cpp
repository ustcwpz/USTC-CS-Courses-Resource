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

#include "QRCodeV4.h"
#include <string.h>
#include <iomanip>

QRCodeV4::QRCodeV4() : QRCode()
{
    Version             = 4;
    Modules             = 33;
    REMINDER_BIT_COUNT  = 7;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV4::~QRCodeV4()
{

}

//----------------------------------------------------------------
void QRCodeV4::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 187;
    CAP_L_CORRECTION_ALPHANUMERIC       = 114;
    CAP_L_CORRECTION_BYTE               = 78;
    CAP_L_CORRECTION_KANJI              = 48;

    CAP_M_CORRECTION_NUMERIC            = 149;
    CAP_M_CORRECTION_ALPHANUMERIC       = 90;
    CAP_M_CORRECTION_BYTE               = 62;
    CAP_M_CORRECTION_KANJI              = 38;

    CAP_Q_CORRECTION_NUMERIC            = 111;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 67;
    CAP_Q_CORRECTION_BYTE               = 46;
    CAP_Q_CORRECTION_KANJI              = 28;

    CAP_H_CORRECTION_NUMERIC            = 82;
    CAP_H_CORRECTION_ALPHANUMERIC       = 50;
    CAP_H_CORRECTION_BYTE               = 34;
    CAP_H_CORRECTION_KANJI              = 21;
}
//----------------------------------------------------------------

void QRCodeV4::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 80;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 20;
    ECL_LOW_EC_INFO.BlocksGroup1        = 1;
    ECL_LOW_EC_INFO.BlocksGroup2        = 0;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 80;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 0;

    ECL_MEDIUM_EC_INFO.TotalCW          = 64;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 18;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 2;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 0;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 32;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 0;

    ECL_QUALITY_EC_INFO.TotalCW         = 48;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 26;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 2;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 0;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 0;

    ECL_HIGH_EC_INFO.TotalCW            = 36;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 16;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 4;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 0;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 9;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 0;
}
//----------------------------------------------------------------

void QRCodeV4::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(26,26));
}
//----------------------------------------------------------------


