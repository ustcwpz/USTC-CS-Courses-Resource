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

#include "QRCodeV27.h"
#include <string.h>
#include <iomanip>

QRCodeV27::QRCodeV27() : QRCode()
{
    Version             = 27;
    Modules             = 125;
    REMINDER_BIT_COUNT  = 4;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV27::~QRCodeV27()
{

}

//----------------------------------------------------------------
void QRCodeV27::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 3517;
    CAP_L_CORRECTION_ALPHANUMERIC       = 2132;
    CAP_L_CORRECTION_BYTE               = 1465;
    CAP_L_CORRECTION_KANJI              = 902;

    CAP_M_CORRECTION_NUMERIC            = 2701;
    CAP_M_CORRECTION_ALPHANUMERIC       = 1637;
    CAP_M_CORRECTION_BYTE               = 1125;
    CAP_M_CORRECTION_KANJI              = 692;

    CAP_Q_CORRECTION_NUMERIC            = 1933;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 1172;
    CAP_Q_CORRECTION_BYTE               = 805;
    CAP_Q_CORRECTION_KANJI              = 496;

    CAP_H_CORRECTION_NUMERIC            = 1501;
    CAP_H_CORRECTION_ALPHANUMERIC       = 910;
    CAP_H_CORRECTION_BYTE               = 625;
    CAP_H_CORRECTION_KANJI              = 385;
}
//----------------------------------------------------------------

void QRCodeV27::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 1468;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 8;
    ECL_LOW_EC_INFO.BlocksGroup2        = 4;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 122;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 123;

    ECL_MEDIUM_EC_INFO.TotalCW          = 1128;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 22;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 3;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 45;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 46;

    ECL_QUALITY_EC_INFO.TotalCW         = 808;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 8;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 26;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 23;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 24;

    ECL_HIGH_EC_INFO.TotalCW            = 628;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 12;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 28;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV27::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(34,6));
    AlignementPatterns.push_back(Point(62,6));
    AlignementPatterns.push_back(Point(90,6));

    AlignementPatterns.push_back(Point(6,34));
    AlignementPatterns.push_back(Point(34,34));
    AlignementPatterns.push_back(Point(62,34));
    AlignementPatterns.push_back(Point(90,34));
    AlignementPatterns.push_back(Point(118,34));

    AlignementPatterns.push_back(Point(6,62));
    AlignementPatterns.push_back(Point(34,62));
    AlignementPatterns.push_back(Point(62,62));
    AlignementPatterns.push_back(Point(90,62));
    AlignementPatterns.push_back(Point(118,62));

    AlignementPatterns.push_back(Point(6,90));
    AlignementPatterns.push_back(Point(34,90));
    AlignementPatterns.push_back(Point(62,90));
    AlignementPatterns.push_back(Point(90,90));
    AlignementPatterns.push_back(Point(118,90));

    AlignementPatterns.push_back(Point(34,118));
    AlignementPatterns.push_back(Point(62,118));
    AlignementPatterns.push_back(Point(90,118));
    AlignementPatterns.push_back(Point(118,118));
}
//----------------------------------------------------------------


