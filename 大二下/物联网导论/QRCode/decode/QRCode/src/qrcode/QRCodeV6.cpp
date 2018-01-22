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

#include "QRCodeV6.h"
#include <string.h>
#include <iomanip>

QRCodeV6::QRCodeV6() : QRCode()
{
    Version             = 6;
    Modules             = 41;
    REMINDER_BIT_COUNT  = 7;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV6::~QRCodeV6()
{

}

//----------------------------------------------------------------
void QRCodeV6::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 322;
    CAP_L_CORRECTION_ALPHANUMERIC       = 195;
    CAP_L_CORRECTION_BYTE               = 134;
    CAP_L_CORRECTION_KANJI              = 82;

    CAP_M_CORRECTION_NUMERIC            = 255;
    CAP_M_CORRECTION_ALPHANUMERIC       = 154;
    CAP_M_CORRECTION_BYTE               = 106;
    CAP_M_CORRECTION_KANJI              = 65;

    CAP_Q_CORRECTION_NUMERIC            = 178;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 108;
    CAP_Q_CORRECTION_BYTE               = 74;
    CAP_Q_CORRECTION_KANJI              = 45;

    CAP_H_CORRECTION_NUMERIC            = 139;
    CAP_H_CORRECTION_ALPHANUMERIC       = 84;
    CAP_H_CORRECTION_BYTE               = 58;
    CAP_H_CORRECTION_KANJI              = 36;
}
//----------------------------------------------------------------

void QRCodeV6::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 136;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 18;
    ECL_LOW_EC_INFO.BlocksGroup1        = 2;
    ECL_LOW_EC_INFO.BlocksGroup2        = 0;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 68;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 0;

    ECL_MEDIUM_EC_INFO.TotalCW          = 108;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 16;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 4;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 0;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 27;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 0;

    ECL_QUALITY_EC_INFO.TotalCW         = 76;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 24;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 4;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 0;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 19;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 0;

    ECL_HIGH_EC_INFO.TotalCW            = 60;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 28;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 4;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 0;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 0;
}
//----------------------------------------------------------------

void QRCodeV6::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(34,34));
}
//----------------------------------------------------------------


