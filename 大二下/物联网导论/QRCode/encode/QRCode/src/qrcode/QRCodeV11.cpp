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
#include "QRCodeV11.h"
#include <string.h>
#include <iomanip>

QRCodeV11::QRCodeV11() : QRCode()
{
    Version             = 11;
    Modules             = 61;
    REMINDER_BIT_COUNT  = 0;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV11::~QRCodeV11()
{

}

//----------------------------------------------------------------
void QRCodeV11::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 772;
    CAP_L_CORRECTION_ALPHANUMERIC       = 468;
    CAP_L_CORRECTION_BYTE               = 321;
    CAP_L_CORRECTION_KANJI              = 198;

    CAP_M_CORRECTION_NUMERIC            = 604;
    CAP_M_CORRECTION_ALPHANUMERIC       = 366;
    CAP_M_CORRECTION_BYTE               = 251;
    CAP_M_CORRECTION_KANJI              = 155;

    CAP_Q_CORRECTION_NUMERIC            = 427;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 259;
    CAP_Q_CORRECTION_BYTE               = 177;
    CAP_Q_CORRECTION_KANJI              = 109;

    CAP_H_CORRECTION_NUMERIC            = 331;
    CAP_H_CORRECTION_ALPHANUMERIC       = 200;
    CAP_H_CORRECTION_BYTE               = 137;
    CAP_H_CORRECTION_KANJI              = 85;
}
//----------------------------------------------------------------

void QRCodeV11::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 324;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 20;
    ECL_LOW_EC_INFO.BlocksGroup1        = 4;
    ECL_LOW_EC_INFO.BlocksGroup2        = 0;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 81;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 0;

    ECL_MEDIUM_EC_INFO.TotalCW          = 254;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 30;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 1;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 4;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 50;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 51;

    ECL_QUALITY_EC_INFO.TotalCW         = 180;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 28;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 4;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 4;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 22;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 23;

    ECL_HIGH_EC_INFO.TotalCW            = 140;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 24;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 3;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 8;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 12;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 13;
}
//----------------------------------------------------------------

void QRCodeV11::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(30,6));
    AlignementPatterns.push_back(Point(6,30));
    AlignementPatterns.push_back(Point(30,30));
    AlignementPatterns.push_back(Point(54,30));
    AlignementPatterns.push_back(Point(30,54));
    AlignementPatterns.push_back(Point(54,54));
}
//----------------------------------------------------------------


