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

#include "QRCodeV5.h"
#include <string.h>
#include <iomanip>

QRCodeV5::QRCodeV5() : QRCode()
{
    Version             = 5;
    Modules             = 37;
    REMINDER_BIT_COUNT  = 7;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV5::~QRCodeV5()
{

}

//----------------------------------------------------------------
void QRCodeV5::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 255;
    CAP_L_CORRECTION_ALPHANUMERIC       = 154;
    CAP_L_CORRECTION_BYTE               = 106;
    CAP_L_CORRECTION_KANJI              = 65;

    CAP_M_CORRECTION_NUMERIC            = 202;
    CAP_M_CORRECTION_ALPHANUMERIC       = 122;
    CAP_M_CORRECTION_BYTE               = 84;
    CAP_M_CORRECTION_KANJI              = 52;

    CAP_Q_CORRECTION_NUMERIC            = 144;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 87;
    CAP_Q_CORRECTION_BYTE               = 60;
    CAP_Q_CORRECTION_KANJI              = 37;

    CAP_H_CORRECTION_NUMERIC            = 106;
    CAP_H_CORRECTION_ALPHANUMERIC       = 64;
    CAP_H_CORRECTION_BYTE               = 44;
    CAP_H_CORRECTION_KANJI              = 27;
}
//----------------------------------------------------------------

void QRCodeV5::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 108;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 26;
    ECL_LOW_EC_INFO.BlocksGroup1        = 1;
    ECL_LOW_EC_INFO.BlocksGroup2        = 0;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 108;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 0;

    ECL_MEDIUM_EC_INFO.TotalCW          = 86;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 24;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 2;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 0;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 43;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 0;

    ECL_QUALITY_EC_INFO.TotalCW         = 62;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 18;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 2;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 2;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 15;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 16;

    ECL_HIGH_EC_INFO.TotalCW            = 46;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 22;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 2;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 2;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 11;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 12;
}
//----------------------------------------------------------------

void QRCodeV5::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(30,30));
}
//----------------------------------------------------------------


