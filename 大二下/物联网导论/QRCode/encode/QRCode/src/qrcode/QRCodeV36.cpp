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

#include "QRCodeV36.h"
#include <string.h>
#include <iomanip>

QRCodeV36::QRCodeV36() : QRCode()
{
    Version             = 36;
    Modules             = 161;
    REMINDER_BIT_COUNT  = 0;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV36::~QRCodeV36()
{

}

//----------------------------------------------------------------
void QRCodeV36::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 5836;
    CAP_L_CORRECTION_ALPHANUMERIC       = 3537;
    CAP_L_CORRECTION_BYTE               = 2431;
    CAP_L_CORRECTION_KANJI              = 1496;

    CAP_M_CORRECTION_NUMERIC            = 4588;
    CAP_M_CORRECTION_ALPHANUMERIC       = 2780;
    CAP_M_CORRECTION_BYTE               = 1911;
    CAP_M_CORRECTION_KANJI              = 1176;

    CAP_Q_CORRECTION_NUMERIC            = 3244;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 1966;
    CAP_Q_CORRECTION_BYTE               = 1351;
    CAP_Q_CORRECTION_KANJI              = 832;

    CAP_H_CORRECTION_NUMERIC            = 2524;
    CAP_H_CORRECTION_ALPHANUMERIC       = 1530;
    CAP_H_CORRECTION_BYTE               = 1051;
    CAP_H_CORRECTION_KANJI              = 647;
}
//----------------------------------------------------------------

void QRCodeV36::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 2434;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 6;
    ECL_LOW_EC_INFO.BlocksGroup2        = 14;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 121;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 122;

    ECL_MEDIUM_EC_INFO.TotalCW          = 1914;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 6;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 34;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 47;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 48;

    ECL_QUALITY_EC_INFO.TotalCW         = 1354;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 46;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 10;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 1054;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 2;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 64;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV36::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(24,6));
    AlignementPatterns.push_back(Point(50,6));
    AlignementPatterns.push_back(Point(76,6));
    AlignementPatterns.push_back(Point(102,6));
    AlignementPatterns.push_back(Point(128,6));

    AlignementPatterns.push_back(Point(6,24));
    AlignementPatterns.push_back(Point(24,24));
    AlignementPatterns.push_back(Point(50,24));
    AlignementPatterns.push_back(Point(76,24));
    AlignementPatterns.push_back(Point(102,24));
    AlignementPatterns.push_back(Point(128,24));
    AlignementPatterns.push_back(Point(154,24));

    AlignementPatterns.push_back(Point(6,50));
    AlignementPatterns.push_back(Point(24,50));
    AlignementPatterns.push_back(Point(50,50));
    AlignementPatterns.push_back(Point(76,50));
    AlignementPatterns.push_back(Point(102,50));
    AlignementPatterns.push_back(Point(128,50));
    AlignementPatterns.push_back(Point(154,50));

    AlignementPatterns.push_back(Point(6,76));
    AlignementPatterns.push_back(Point(24,76));
    AlignementPatterns.push_back(Point(50,76));
    AlignementPatterns.push_back(Point(76,76));
    AlignementPatterns.push_back(Point(102,76));
    AlignementPatterns.push_back(Point(128,76));
    AlignementPatterns.push_back(Point(154,76));

    AlignementPatterns.push_back(Point(6,102));
    AlignementPatterns.push_back(Point(24,102));
    AlignementPatterns.push_back(Point(50,102));
    AlignementPatterns.push_back(Point(76,102));
    AlignementPatterns.push_back(Point(102,102));
    AlignementPatterns.push_back(Point(128,102));
    AlignementPatterns.push_back(Point(154,102));

    AlignementPatterns.push_back(Point(6,128));
    AlignementPatterns.push_back(Point(24,128));
    AlignementPatterns.push_back(Point(50,128));
    AlignementPatterns.push_back(Point(76,128));
    AlignementPatterns.push_back(Point(102,128));
    AlignementPatterns.push_back(Point(128,128));
    AlignementPatterns.push_back(Point(154,128));

    AlignementPatterns.push_back(Point(24,154));
    AlignementPatterns.push_back(Point(50,154));
    AlignementPatterns.push_back(Point(76,154));
    AlignementPatterns.push_back(Point(102,154));
    AlignementPatterns.push_back(Point(128,154));
    AlignementPatterns.push_back(Point(154,154));
}
//----------------------------------------------------------------


