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

#include "QRCodeV1.h"
#include <string.h>
#include <iomanip>

QRCodeV1::QRCodeV1() : QRCode()
{
    Version             = 1;
    Modules             = 21;
    REMINDER_BIT_COUNT  = 0;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV1::~QRCodeV1()
{

}

//----------------------------------------------------------------
void QRCodeV1::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 41;
    CAP_L_CORRECTION_ALPHANUMERIC       = 25;
    CAP_L_CORRECTION_BYTE               = 17;
    CAP_L_CORRECTION_KANJI              = 10;

    CAP_M_CORRECTION_NUMERIC            = 34;
    CAP_M_CORRECTION_ALPHANUMERIC       = 20;
    CAP_M_CORRECTION_BYTE               = 14;
    CAP_M_CORRECTION_KANJI              = 8;

    CAP_Q_CORRECTION_NUMERIC            = 27;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 16;
    CAP_Q_CORRECTION_BYTE               = 11;
    CAP_Q_CORRECTION_KANJI              = 7;

    CAP_H_CORRECTION_NUMERIC            = 17;
    CAP_H_CORRECTION_ALPHANUMERIC       = 10;
    CAP_H_CORRECTION_BYTE               = 7;
    CAP_H_CORRECTION_KANJI              = 4;
}
//----------------------------------------------------------------

void QRCodeV1::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 19;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 7;
    ECL_LOW_EC_INFO.BlocksGroup1        = 1;
    ECL_LOW_EC_INFO.BlocksGroup2        = 0;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 19;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 0;

    ECL_MEDIUM_EC_INFO.TotalCW          = 16;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 10;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 1;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 0;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 16;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 0;

    ECL_QUALITY_EC_INFO.TotalCW         = 13;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 13;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 1;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 0;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 13;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 0;

    ECL_HIGH_EC_INFO.TotalCW            = 9;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 17;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 1;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 0;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 9;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 0;
}
//----------------------------------------------------------------

void QRCodeV1::InitAlignementPatterns(void)
{
    //No alignement patterns for version 1
}
//----------------------------------------------------------------


