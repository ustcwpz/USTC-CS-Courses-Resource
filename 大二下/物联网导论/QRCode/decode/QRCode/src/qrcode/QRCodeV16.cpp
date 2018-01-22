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
#include "QRCodeV16.h"
#include <string.h>
#include <iomanip>

QRCodeV16::QRCodeV16() : QRCode()
{
    Version             = 16;
    Modules             = 81;
    REMINDER_BIT_COUNT  = 3;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV16::~QRCodeV16()
{

}

//----------------------------------------------------------------
void QRCodeV16::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 1408;
    CAP_L_CORRECTION_ALPHANUMERIC       = 854;
    CAP_L_CORRECTION_BYTE               = 586;
    CAP_L_CORRECTION_KANJI              = 361;

    CAP_M_CORRECTION_NUMERIC            = 1082;
    CAP_M_CORRECTION_ALPHANUMERIC       = 656;
    CAP_M_CORRECTION_BYTE               = 450;
    CAP_M_CORRECTION_KANJI              = 277;

    CAP_Q_CORRECTION_NUMERIC            = 775;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 470;
    CAP_Q_CORRECTION_BYTE               = 322;
    CAP_Q_CORRECTION_KANJI              = 198;

    CAP_H_CORRECTION_NUMERIC            = 602;
    CAP_H_CORRECTION_ALPHANUMERIC       = 365;
    CAP_H_CORRECTION_BYTE               = 250;
    CAP_H_CORRECTION_KANJI              = 154;
}
//----------------------------------------------------------------

void QRCodeV16::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 589;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 24;
    ECL_LOW_EC_INFO.BlocksGroup1        = 5;
    ECL_LOW_EC_INFO.BlocksGroup2        = 1;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 98;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 99;

    ECL_MEDIUM_EC_INFO.TotalCW          = 453;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 7;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 3;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 45;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 46;

    ECL_QUALITY_EC_INFO.TotalCW         = 325;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 24;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 15;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 2;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 19;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 20;

    ECL_HIGH_EC_INFO.TotalCW            = 253;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 3;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 13;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV16::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(26,6));
    AlignementPatterns.push_back(Point(6,26));
    AlignementPatterns.push_back(Point(26,26));
    AlignementPatterns.push_back(Point(6,50));
    AlignementPatterns.push_back(Point(50,6));

    AlignementPatterns.push_back(Point(26,50));
    AlignementPatterns.push_back(Point(50,26));
    AlignementPatterns.push_back(Point(50,50));
    AlignementPatterns.push_back(Point(26,74));
    AlignementPatterns.push_back(Point(74,26));

    AlignementPatterns.push_back(Point(50,74));
    AlignementPatterns.push_back(Point(74,50));
    AlignementPatterns.push_back(Point(74,74));
}
//----------------------------------------------------------------


