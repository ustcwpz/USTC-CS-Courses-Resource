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

#include "QRCodeV24.h"
#include <string.h>
#include <iomanip>

QRCodeV24::QRCodeV24() : QRCode()
{
    Version             = 24;
    Modules             = 113;
    REMINDER_BIT_COUNT  = 4;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV24::~QRCodeV24()
{

}

//----------------------------------------------------------------
void QRCodeV24::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 2812;
    CAP_L_CORRECTION_ALPHANUMERIC       = 1704;
    CAP_L_CORRECTION_BYTE               = 1171;
    CAP_L_CORRECTION_KANJI              = 721;

    CAP_M_CORRECTION_NUMERIC            = 2188;
    CAP_M_CORRECTION_ALPHANUMERIC       = 1326;
    CAP_M_CORRECTION_BYTE               = 911;
    CAP_M_CORRECTION_KANJI              = 561;

    CAP_Q_CORRECTION_NUMERIC            = 1588;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 963;
    CAP_Q_CORRECTION_BYTE               = 661;
    CAP_Q_CORRECTION_KANJI              = 407;

    CAP_H_CORRECTION_NUMERIC            = 1228;
    CAP_H_CORRECTION_ALPHANUMERIC       = 744;
    CAP_H_CORRECTION_BYTE               = 511;
    CAP_H_CORRECTION_KANJI              = 315;
}
//----------------------------------------------------------------

void QRCodeV24::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 1174;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 6;
    ECL_LOW_EC_INFO.BlocksGroup2        = 4;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 117;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 118;

    ECL_MEDIUM_EC_INFO.TotalCW          = 914;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 6;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 14;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 45;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 46;

    ECL_QUALITY_EC_INFO.TotalCW         = 664;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 11;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 16;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 514;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 30;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 2;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 16;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 17;
}
//----------------------------------------------------------------

void QRCodeV24::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(28,6));
    AlignementPatterns.push_back(Point(54,6));
    AlignementPatterns.push_back(Point(80,6));

    AlignementPatterns.push_back(Point(6,28));
    AlignementPatterns.push_back(Point(28,28));
    AlignementPatterns.push_back(Point(54,28));
    AlignementPatterns.push_back(Point(80,28));
    AlignementPatterns.push_back(Point(106,28));

    AlignementPatterns.push_back(Point(6,54));
    AlignementPatterns.push_back(Point(28,54));
    AlignementPatterns.push_back(Point(54,54));
    AlignementPatterns.push_back(Point(80,54));
    AlignementPatterns.push_back(Point(106,54));

    AlignementPatterns.push_back(Point(6,80));
    AlignementPatterns.push_back(Point(28,80));
    AlignementPatterns.push_back(Point(54,80));
    AlignementPatterns.push_back(Point(80,80));
    AlignementPatterns.push_back(Point(106,80));

    AlignementPatterns.push_back(Point(28,106));
    AlignementPatterns.push_back(Point(54,106));
    AlignementPatterns.push_back(Point(80,106));
    AlignementPatterns.push_back(Point(106,106));
}
//----------------------------------------------------------------


