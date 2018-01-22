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

#include "QRCodeV14.h"
#include <string.h>
#include <iomanip>

QRCodeV14::QRCodeV14() : QRCode()
{
    Version             = 14;
    Modules             = 73;
    REMINDER_BIT_COUNT  = 3;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV14::~QRCodeV14()
{

}

//----------------------------------------------------------------
void QRCodeV14::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 1101;
    CAP_L_CORRECTION_ALPHANUMERIC       = 667;
    CAP_L_CORRECTION_BYTE               = 458;
    CAP_L_CORRECTION_KANJI              = 282;

    CAP_M_CORRECTION_NUMERIC            = 871;
    CAP_M_CORRECTION_ALPHANUMERIC       = 528;
    CAP_M_CORRECTION_BYTE               = 362;
    CAP_M_CORRECTION_KANJI              = 223;

    CAP_Q_CORRECTION_NUMERIC            = 621;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 376;
    CAP_Q_CORRECTION_BYTE               = 258;
    CAP_Q_CORRECTION_KANJI              = 159;

    CAP_H_CORRECTION_NUMERIC            = 468;
    CAP_H_CORRECTION_ALPHANUMERIC       = 283;
    CAP_H_CORRECTION_BYTE               = 194;
    CAP_H_CORRECTION_KANJI              = 120;
}
//----------------------------------------------------------------

void QRCodeV14::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 461;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 3;
    ECL_LOW_EC_INFO.BlocksGroup2        = 1;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 115;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 116;

    ECL_MEDIUM_EC_INFO.TotalCW          = 365;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 24;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 4;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 5;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 40;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 41;

    ECL_QUALITY_EC_INFO.TotalCW         = 261;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 20;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 11;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 5;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 16;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 17;

    ECL_HIGH_EC_INFO.TotalCW            = 197;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 24;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 11;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 5;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 12;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 13;
}
//----------------------------------------------------------------

void QRCodeV14::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(26,6));
    AlignementPatterns.push_back(Point(6,26));
    AlignementPatterns.push_back(Point(26,26));
    AlignementPatterns.push_back(Point(6,46));
    AlignementPatterns.push_back(Point(46,6));

    AlignementPatterns.push_back(Point(26,46));
    AlignementPatterns.push_back(Point(46,26));
    AlignementPatterns.push_back(Point(46,46));
    AlignementPatterns.push_back(Point(26,66));
    AlignementPatterns.push_back(Point(66,26));

    AlignementPatterns.push_back(Point(46,66));
    AlignementPatterns.push_back(Point(66,46));
    AlignementPatterns.push_back(Point(66,66));
}
//----------------------------------------------------------------


