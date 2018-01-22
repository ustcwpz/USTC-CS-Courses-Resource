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

#include "QRCodeV12.h"
#include <string.h>
#include <iomanip>

QRCodeV12::QRCodeV12() : QRCode()
{
    Version             = 12;
    Modules             = 65;
    REMINDER_BIT_COUNT  = 0;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV12::~QRCodeV12()
{

}

//----------------------------------------------------------------
void QRCodeV12::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 883;
    CAP_L_CORRECTION_ALPHANUMERIC       = 535;
    CAP_L_CORRECTION_BYTE               = 367;
    CAP_L_CORRECTION_KANJI              = 226;

    CAP_M_CORRECTION_NUMERIC            = 691;
    CAP_M_CORRECTION_ALPHANUMERIC       = 419;
    CAP_M_CORRECTION_BYTE               = 287;
    CAP_M_CORRECTION_KANJI              = 177;

    CAP_Q_CORRECTION_NUMERIC            = 489;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 296;
    CAP_Q_CORRECTION_BYTE               = 203;
    CAP_Q_CORRECTION_KANJI              = 125;

    CAP_H_CORRECTION_NUMERIC            = 374;
    CAP_H_CORRECTION_ALPHANUMERIC       = 227;
    CAP_H_CORRECTION_BYTE               = 155;
    CAP_H_CORRECTION_KANJI              = 96;
}
//----------------------------------------------------------------

void QRCodeV12::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 370;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 24;
    ECL_LOW_EC_INFO.BlocksGroup1        = 2;
    ECL_LOW_EC_INFO.BlocksGroup2        = 2;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 92;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 93;

    ECL_MEDIUM_EC_INFO.TotalCW          = 290;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 22;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 6;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 2;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 36;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 37;

    ECL_QUALITY_EC_INFO.TotalCW         = 206;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 26;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 4;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 6;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 20;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 21;

    ECL_HIGH_EC_INFO.TotalCW            = 158;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 28;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 7;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 4;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 14;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 15;
}
//----------------------------------------------------------------

void QRCodeV12::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(32,6));
    AlignementPatterns.push_back(Point(6,32));
    AlignementPatterns.push_back(Point(32,32));
    AlignementPatterns.push_back(Point(58,32));
    AlignementPatterns.push_back(Point(32,58));
    AlignementPatterns.push_back(Point(58,58));
}
//----------------------------------------------------------------


