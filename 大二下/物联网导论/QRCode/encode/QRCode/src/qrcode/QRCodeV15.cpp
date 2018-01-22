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

#include "QRCodeV15.h"
#include <string.h>
#include <iomanip>

QRCodeV15::QRCodeV15() : QRCode()
{
    Version             = 15;
    Modules             = 77;
    REMINDER_BIT_COUNT  = 3;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV15::~QRCodeV15()
{

}

//----------------------------------------------------------------
void QRCodeV15::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 1250;
    CAP_L_CORRECTION_ALPHANUMERIC       = 758;
    CAP_L_CORRECTION_BYTE               = 520;
    CAP_L_CORRECTION_KANJI              = 320;

    CAP_M_CORRECTION_NUMERIC            = 991;
    CAP_M_CORRECTION_ALPHANUMERIC       = 600;
    CAP_M_CORRECTION_BYTE               = 412;
    CAP_M_CORRECTION_KANJI              = 254;

    CAP_Q_CORRECTION_NUMERIC            = 703;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 426;
    CAP_Q_CORRECTION_BYTE               = 292;
    CAP_Q_CORRECTION_KANJI              = 180;

    CAP_H_CORRECTION_NUMERIC            = 530;
    CAP_H_CORRECTION_ALPHANUMERIC       = 321;
    CAP_H_CORRECTION_BYTE               = 220;
    CAP_H_CORRECTION_KANJI              = 136;
}
//----------------------------------------------------------------

void QRCodeV15::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 523;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 22;
    ECL_LOW_EC_INFO.BlocksGroup1        = 5;
    ECL_LOW_EC_INFO.BlocksGroup2        = 1;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 87;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 88;

    ECL_MEDIUM_EC_INFO.TotalCW          = 415;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 24;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 5;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 5;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 41;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 42;

    ECL_QUALITY_EC_INFO.TotalCW         = 295;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 5;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 7;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 223;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 24;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 11;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 7;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 12;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 13;
}
//----------------------------------------------------------------

void QRCodeV15::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(26,6));
    AlignementPatterns.push_back(Point(6,26));
    AlignementPatterns.push_back(Point(26,26));
    AlignementPatterns.push_back(Point(6,48));
    AlignementPatterns.push_back(Point(48,6));

    AlignementPatterns.push_back(Point(26,48));
    AlignementPatterns.push_back(Point(48,26));
    AlignementPatterns.push_back(Point(48,48));
    AlignementPatterns.push_back(Point(26,70));
    AlignementPatterns.push_back(Point(70,26));

    AlignementPatterns.push_back(Point(48,70));
    AlignementPatterns.push_back(Point(70,48));
    AlignementPatterns.push_back(Point(70,70));
}
//----------------------------------------------------------------


