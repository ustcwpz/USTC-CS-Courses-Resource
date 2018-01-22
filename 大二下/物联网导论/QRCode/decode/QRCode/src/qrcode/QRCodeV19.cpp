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

#include "QRCodeV19.h"
#include <string.h>
#include <iomanip>

QRCodeV19::QRCodeV19() : QRCode()
{
    Version             = 19;
    Modules             = 93;
    REMINDER_BIT_COUNT  = 3;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV19::~QRCodeV19()
{

}

//----------------------------------------------------------------
void QRCodeV19::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 1903;
    CAP_L_CORRECTION_ALPHANUMERIC       = 1153;
    CAP_L_CORRECTION_BYTE               = 792;
    CAP_L_CORRECTION_KANJI              = 488;

    CAP_M_CORRECTION_NUMERIC            = 1500;
    CAP_M_CORRECTION_ALPHANUMERIC       = 909;
    CAP_M_CORRECTION_BYTE               = 624;
    CAP_M_CORRECTION_KANJI              = 384;

    CAP_Q_CORRECTION_NUMERIC            = 1063;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 644;
    CAP_Q_CORRECTION_BYTE               = 442;
    CAP_Q_CORRECTION_KANJI              = 272;

    CAP_H_CORRECTION_NUMERIC            = 813;
    CAP_H_CORRECTION_ALPHANUMERIC       = 493;
    CAP_H_CORRECTION_BYTE               = 338;
    CAP_H_CORRECTION_KANJI              = 208;
}
//----------------------------------------------------------------

void QRCodeV19::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 795;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 28;
    ECL_LOW_EC_INFO.BlocksGroup1        = 3;
    ECL_LOW_EC_INFO.BlocksGroup2        = 4;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 113;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 114;

    ECL_MEDIUM_EC_INFO.TotalCW          = 627;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 26;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 3;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 11;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 44;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 45;

    ECL_QUALITY_EC_INFO.TotalCW         = 445;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 26;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 17;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 4;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 21;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 22;

    ECL_HIGH_EC_INFO.TotalCW            = 341;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 26;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 9;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 16;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 13;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 14;
}
//----------------------------------------------------------------

void QRCodeV19::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(30,6));
    AlignementPatterns.push_back(Point(6,30));
    AlignementPatterns.push_back(Point(30,30));
    AlignementPatterns.push_back(Point(6,58));
    AlignementPatterns.push_back(Point(58,6));

    AlignementPatterns.push_back(Point(30,58));
    AlignementPatterns.push_back(Point(58,30));
    AlignementPatterns.push_back(Point(58,58));
    AlignementPatterns.push_back(Point(30,86));
    AlignementPatterns.push_back(Point(86,30));

    AlignementPatterns.push_back(Point(58,86));
    AlignementPatterns.push_back(Point(86,58));
    AlignementPatterns.push_back(Point(86,86));
}
//----------------------------------------------------------------


