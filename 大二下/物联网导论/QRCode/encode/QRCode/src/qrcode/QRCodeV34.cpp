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

#include "QRCodeV34.h"
#include <string.h>
#include <iomanip>

QRCodeV34::QRCodeV34() : QRCode()
{
    Version             = 34;
    Modules             = 153;
    REMINDER_BIT_COUNT  = 3;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV34::~QRCodeV34()
{

}

//----------------------------------------------------------------
void QRCodeV34::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 5253;
    CAP_L_CORRECTION_ALPHANUMERIC       = 3183;
    CAP_L_CORRECTION_BYTE               = 2188;
    CAP_L_CORRECTION_KANJI              = 1347;

    CAP_M_CORRECTION_NUMERIC            = 4134;
    CAP_M_CORRECTION_ALPHANUMERIC       = 2506;
    CAP_M_CORRECTION_BYTE               = 1722;
    CAP_M_CORRECTION_KANJI              = 1060;

    CAP_Q_CORRECTION_NUMERIC            = 2949;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 1787;
    CAP_Q_CORRECTION_BYTE               = 1228;
    CAP_Q_CORRECTION_KANJI              = 756;

    CAP_H_CORRECTION_NUMERIC            = 2301;
    CAP_H_CORRECTION_ALPHANUMERIC       = 1394;
    CAP_H_CORRECTION_BYTE               = 958;
    CAP_H_CORRECTION_KANJI              = 590;
}
//----------------------------------------------------------------

void QRCodeV34::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 2191;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 13;
    ECL_LOW_EC_INFO.BlocksGroup2        = 6;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 115;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 116;

    ECL_MEDIUM_EC_INFO.TotalCW          = 1725;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 14;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 23;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 46;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 47;

    ECL_QUALITY_EC_INFO.TotalCW         = 1231;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 44;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 7;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 961;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 59;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 1;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 16;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 17;
}
//----------------------------------------------------------------

void QRCodeV34::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(34,6));
    AlignementPatterns.push_back(Point(62,6));
    AlignementPatterns.push_back(Point(90,6));
    AlignementPatterns.push_back(Point(118,6));

    AlignementPatterns.push_back(Point(6,34));
    AlignementPatterns.push_back(Point(34,34));
    AlignementPatterns.push_back(Point(62,34));
    AlignementPatterns.push_back(Point(90,34));
    AlignementPatterns.push_back(Point(118,34));
    AlignementPatterns.push_back(Point(146,34));

    AlignementPatterns.push_back(Point(6,62));
    AlignementPatterns.push_back(Point(34,62));
    AlignementPatterns.push_back(Point(62,62));
    AlignementPatterns.push_back(Point(90,62));
    AlignementPatterns.push_back(Point(118,62));
    AlignementPatterns.push_back(Point(146,62));

    AlignementPatterns.push_back(Point(6,90));
    AlignementPatterns.push_back(Point(34,90));
    AlignementPatterns.push_back(Point(62,90));
    AlignementPatterns.push_back(Point(90,90));
    AlignementPatterns.push_back(Point(118,90));
    AlignementPatterns.push_back(Point(146,90));

    AlignementPatterns.push_back(Point(6,118));
    AlignementPatterns.push_back(Point(34,118));
    AlignementPatterns.push_back(Point(62,118));
    AlignementPatterns.push_back(Point(90,118));
    AlignementPatterns.push_back(Point(118,118));
    AlignementPatterns.push_back(Point(146,118));

    AlignementPatterns.push_back(Point(34,146));
    AlignementPatterns.push_back(Point(62,146));
    AlignementPatterns.push_back(Point(90,146));
    AlignementPatterns.push_back(Point(118,146));
    AlignementPatterns.push_back(Point(146,146));
}
//----------------------------------------------------------------


