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

#include "QRCodeV23.h"
#include <string.h>
#include <iomanip>

QRCodeV23::QRCodeV23() : QRCode()
{
    Version             = 23;
    Modules             = 109;
    REMINDER_BIT_COUNT  = 4;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV23::~QRCodeV23()
{

}

//----------------------------------------------------------------
void QRCodeV23::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 2620;
    CAP_L_CORRECTION_ALPHANUMERIC       = 1588;
    CAP_L_CORRECTION_BYTE               = 1091;
    CAP_L_CORRECTION_KANJI              = 672;

    CAP_M_CORRECTION_NUMERIC            = 2059;
    CAP_M_CORRECTION_ALPHANUMERIC       = 1248;
    CAP_M_CORRECTION_BYTE               = 857;
    CAP_M_CORRECTION_KANJI              = 528;

    CAP_Q_CORRECTION_NUMERIC            = 1468;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 890;
    CAP_Q_CORRECTION_BYTE               = 611;
    CAP_Q_CORRECTION_KANJI              = 376;

    CAP_H_CORRECTION_NUMERIC            = 1108;
    CAP_H_CORRECTION_ALPHANUMERIC       = 672;
    CAP_H_CORRECTION_BYTE               = 461;
    CAP_H_CORRECTION_KANJI              = 284;
}
//----------------------------------------------------------------

void QRCodeV23::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 1094;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 4;
    ECL_LOW_EC_INFO.BlocksGroup2        = 5;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 121;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 122;

    ECL_MEDIUM_EC_INFO.TotalCW          = 860;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 4;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 14;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 47;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 48;

    ECL_QUALITY_EC_INFO.TotalCW         = 614;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 11;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 14;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 464;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 16;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 14;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV23::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(30,6));
    AlignementPatterns.push_back(Point(54,6));
    AlignementPatterns.push_back(Point(78,6));

    AlignementPatterns.push_back(Point(6,30));
    AlignementPatterns.push_back(Point(30,30));
    AlignementPatterns.push_back(Point(54,30));
    AlignementPatterns.push_back(Point(78,30));
    AlignementPatterns.push_back(Point(102,30));

    AlignementPatterns.push_back(Point(6,54));
    AlignementPatterns.push_back(Point(30,54));
    AlignementPatterns.push_back(Point(54,54));
    AlignementPatterns.push_back(Point(78,54));
    AlignementPatterns.push_back(Point(102,54));

    AlignementPatterns.push_back(Point(6,78));
    AlignementPatterns.push_back(Point(30,78));
    AlignementPatterns.push_back(Point(54,78));
    AlignementPatterns.push_back(Point(78,78));
    AlignementPatterns.push_back(Point(102,78));

    AlignementPatterns.push_back(Point(30,102));
    AlignementPatterns.push_back(Point(54,102));
    AlignementPatterns.push_back(Point(78,102));
    AlignementPatterns.push_back(Point(102,102));
}
//----------------------------------------------------------------


