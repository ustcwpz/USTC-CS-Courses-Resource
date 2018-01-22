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

#include "QRCodeV22.h"
#include <string.h>
#include <iomanip>

QRCodeV22::QRCodeV22() : QRCode()
{
    Version             = 22;
    Modules             = 105;
    REMINDER_BIT_COUNT  = 4;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV22::~QRCodeV22()
{

}

//----------------------------------------------------------------
void QRCodeV22::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 2409;
    CAP_L_CORRECTION_ALPHANUMERIC       = 1460;
    CAP_L_CORRECTION_BYTE               = 1003;
    CAP_L_CORRECTION_KANJI              = 618;

    CAP_M_CORRECTION_NUMERIC            = 1872;
    CAP_M_CORRECTION_ALPHANUMERIC       = 1134;
    CAP_M_CORRECTION_BYTE               = 779;
    CAP_M_CORRECTION_KANJI              = 480;

    CAP_Q_CORRECTION_NUMERIC            = 1358;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 823;
    CAP_Q_CORRECTION_BYTE               = 565;
    CAP_Q_CORRECTION_KANJI              = 348;

    CAP_H_CORRECTION_NUMERIC            = 1056;
    CAP_H_CORRECTION_ALPHANUMERIC       = 640;
    CAP_H_CORRECTION_BYTE               = 439;
    CAP_H_CORRECTION_KANJI              = 270;
}
//----------------------------------------------------------------

void QRCodeV22::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 1006;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 28;
    ECL_LOW_EC_INFO.BlocksGroup1        = 2;
    ECL_LOW_EC_INFO.BlocksGroup2        = 7;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 111;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 112;

    ECL_MEDIUM_EC_INFO.TotalCW          = 782;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 17;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 0;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 46;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 0;

    ECL_QUALITY_EC_INFO.TotalCW         = 568;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 7;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 16;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 442;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 24;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 34;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 0;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 13;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 0;
}
//----------------------------------------------------------------

void QRCodeV22::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(26,6));
    AlignementPatterns.push_back(Point(50,6));
    AlignementPatterns.push_back(Point(74,6));

    AlignementPatterns.push_back(Point(6,26));
    AlignementPatterns.push_back(Point(26,26));
    AlignementPatterns.push_back(Point(50,26));
    AlignementPatterns.push_back(Point(74,26));
    AlignementPatterns.push_back(Point(98,26));

    AlignementPatterns.push_back(Point(6,50));
    AlignementPatterns.push_back(Point(26,50));
    AlignementPatterns.push_back(Point(50,50));
    AlignementPatterns.push_back(Point(74,50));
    AlignementPatterns.push_back(Point(98,50));

    AlignementPatterns.push_back(Point(6,74));
    AlignementPatterns.push_back(Point(26,74));
    AlignementPatterns.push_back(Point(50,74));
    AlignementPatterns.push_back(Point(74,74));
    AlignementPatterns.push_back(Point(98,74));

    AlignementPatterns.push_back(Point(26,98));
    AlignementPatterns.push_back(Point(50,98));
    AlignementPatterns.push_back(Point(74,98));
    AlignementPatterns.push_back(Point(98,98));
}
//----------------------------------------------------------------


