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

#include "QRCodeV26.h"
#include <string.h>
#include <iomanip>

QRCodeV26::QRCodeV26() : QRCode()
{
    Version             = 26;
    Modules             = 121;
    REMINDER_BIT_COUNT  = 4;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV26::~QRCodeV26()
{

}

//----------------------------------------------------------------
void QRCodeV26::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 3283;
    CAP_L_CORRECTION_ALPHANUMERIC       = 1990;
    CAP_L_CORRECTION_BYTE               = 1367;
    CAP_L_CORRECTION_KANJI              = 842;

    CAP_M_CORRECTION_NUMERIC            = 2544;
    CAP_M_CORRECTION_ALPHANUMERIC       = 1542;
    CAP_M_CORRECTION_BYTE               = 1059;
    CAP_M_CORRECTION_KANJI              = 652;

    CAP_Q_CORRECTION_NUMERIC            = 1804;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 1094;
    CAP_Q_CORRECTION_BYTE               = 751;
    CAP_Q_CORRECTION_KANJI              = 462;

    CAP_H_CORRECTION_NUMERIC            = 1425;
    CAP_H_CORRECTION_ALPHANUMERIC       = 864;
    CAP_H_CORRECTION_BYTE               = 593;
    CAP_H_CORRECTION_KANJI              = 365;
}
//----------------------------------------------------------------

void QRCodeV26::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 1370;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 28;
    ECL_LOW_EC_INFO.BlocksGroup1        = 10;
    ECL_LOW_EC_INFO.BlocksGroup2        = 2;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 114;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 115;

    ECL_MEDIUM_EC_INFO.TotalCW          = 1062;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 19;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 4;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 46;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 47;

    ECL_QUALITY_EC_INFO.TotalCW         = 754;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 28;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 28;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 6;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 22;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 23;

    ECL_HIGH_EC_INFO.TotalCW            = 596;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 33;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 4;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 16;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 17;
}
//----------------------------------------------------------------

void QRCodeV26::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(30,6));
    AlignementPatterns.push_back(Point(58,6));
    AlignementPatterns.push_back(Point(86,6));

    AlignementPatterns.push_back(Point(6,30));
    AlignementPatterns.push_back(Point(30,30));
    AlignementPatterns.push_back(Point(58,30));
    AlignementPatterns.push_back(Point(86,30));
    AlignementPatterns.push_back(Point(114,30));

    AlignementPatterns.push_back(Point(6,58));
    AlignementPatterns.push_back(Point(30,58));
    AlignementPatterns.push_back(Point(58,58));
    AlignementPatterns.push_back(Point(86,58));
    AlignementPatterns.push_back(Point(114,58));

    AlignementPatterns.push_back(Point(6,86));
    AlignementPatterns.push_back(Point(30,86));
    AlignementPatterns.push_back(Point(58,86));
    AlignementPatterns.push_back(Point(86,86));
    AlignementPatterns.push_back(Point(114,86));

    AlignementPatterns.push_back(Point(30,114));
    AlignementPatterns.push_back(Point(58,114));
    AlignementPatterns.push_back(Point(86,114));
    AlignementPatterns.push_back(Point(114,114));
}
//----------------------------------------------------------------


