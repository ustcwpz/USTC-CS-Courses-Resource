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

#include "QRCodeV17.h"
#include <string.h>
#include <iomanip>

QRCodeV17::QRCodeV17() : QRCode()
{
    Version             = 17;
    Modules             = 85;
    REMINDER_BIT_COUNT  = 3;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV17::~QRCodeV17()
{

}

//----------------------------------------------------------------
void QRCodeV17::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 1548;
    CAP_L_CORRECTION_ALPHANUMERIC       = 938;
    CAP_L_CORRECTION_BYTE               = 644;
    CAP_L_CORRECTION_KANJI              = 397;

    CAP_M_CORRECTION_NUMERIC            = 1212;
    CAP_M_CORRECTION_ALPHANUMERIC       = 734;
    CAP_M_CORRECTION_BYTE               = 504;
    CAP_M_CORRECTION_KANJI              = 310;

    CAP_Q_CORRECTION_NUMERIC            = 876;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 531;
    CAP_Q_CORRECTION_BYTE               = 364;
    CAP_Q_CORRECTION_KANJI              = 224;

    CAP_H_CORRECTION_NUMERIC            = 674;
    CAP_H_CORRECTION_ALPHANUMERIC       = 408;
    CAP_H_CORRECTION_BYTE               = 280;
    CAP_H_CORRECTION_KANJI              = 173;
}
//----------------------------------------------------------------

void QRCodeV17::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 647;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 28;
    ECL_LOW_EC_INFO.BlocksGroup1        = 1;
    ECL_LOW_EC_INFO.BlocksGroup2        = 5;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 107;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 108;

    ECL_MEDIUM_EC_INFO.TotalCW          = 507;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 10;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 1;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 46;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 47;

    ECL_QUALITY_EC_INFO.TotalCW         = 367;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 28;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 1;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 15;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 22;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 23;

    ECL_HIGH_EC_INFO.TotalCW            = 283;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 28;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 2;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 17;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 14;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 15;
}
//----------------------------------------------------------------

void QRCodeV17::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(30,6));
    AlignementPatterns.push_back(Point(6,30));
    AlignementPatterns.push_back(Point(30,30));
    AlignementPatterns.push_back(Point(6,54));
    AlignementPatterns.push_back(Point(54,6));

    AlignementPatterns.push_back(Point(30,54));
    AlignementPatterns.push_back(Point(54,30));
    AlignementPatterns.push_back(Point(54,54));
    AlignementPatterns.push_back(Point(30,78));
    AlignementPatterns.push_back(Point(78,30));

    AlignementPatterns.push_back(Point(54,78));
    AlignementPatterns.push_back(Point(78,54));
    AlignementPatterns.push_back(Point(78,78));
}
//----------------------------------------------------------------


