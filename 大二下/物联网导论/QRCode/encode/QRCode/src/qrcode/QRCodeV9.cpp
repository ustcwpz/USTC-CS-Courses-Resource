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

#include "QRCodeV9.h"
#include <string.h>
#include <iomanip>

QRCodeV9::QRCodeV9() : QRCode()
{
    Version             = 9;
    Modules             = 53;
    REMINDER_BIT_COUNT  = 0;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV9::~QRCodeV9()
{

}

//----------------------------------------------------------------
void QRCodeV9::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 552;
    CAP_L_CORRECTION_ALPHANUMERIC       = 335;
    CAP_L_CORRECTION_BYTE               = 230;
    CAP_L_CORRECTION_KANJI              = 141;

    CAP_M_CORRECTION_NUMERIC            = 432;
    CAP_M_CORRECTION_ALPHANUMERIC       = 262;
    CAP_M_CORRECTION_BYTE               = 180;
    CAP_M_CORRECTION_KANJI              = 111;

    CAP_Q_CORRECTION_NUMERIC            = 312;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 189;
    CAP_Q_CORRECTION_BYTE               = 130;
    CAP_Q_CORRECTION_KANJI              = 80;

    CAP_H_CORRECTION_NUMERIC            = 235;
    CAP_H_CORRECTION_ALPHANUMERIC       = 143;
    CAP_H_CORRECTION_BYTE               = 98;
    CAP_H_CORRECTION_KANJI              = 60;
}
//----------------------------------------------------------------

void QRCodeV9::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 232;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 2;
    ECL_LOW_EC_INFO.BlocksGroup2        = 0;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 116;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 0;

    ECL_MEDIUM_EC_INFO.TotalCW          = 182;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 22;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 3;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 2;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 36;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 37;

    ECL_QUALITY_EC_INFO.TotalCW         = 132;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 20;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 4;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 4;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 16;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 17;

    ECL_HIGH_EC_INFO.TotalCW            = 100;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 24;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 4;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 4;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 12;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 13;
}
//----------------------------------------------------------------

void QRCodeV9::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(26,6));
    AlignementPatterns.push_back(Point(6,26));
    AlignementPatterns.push_back(Point(26,26));
    AlignementPatterns.push_back(Point(46,26));
    AlignementPatterns.push_back(Point(26,46));
    AlignementPatterns.push_back(Point(46,46));
}
//----------------------------------------------------------------


