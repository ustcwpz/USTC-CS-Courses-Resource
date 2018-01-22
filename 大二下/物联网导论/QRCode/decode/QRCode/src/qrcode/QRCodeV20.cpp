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

#include "QRCodeV20.h"
#include <string.h>
#include <iomanip>

QRCodeV20::QRCodeV20() : QRCode()
{
    Version             = 20;
    Modules             = 97;
    REMINDER_BIT_COUNT  = 3;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV20::~QRCodeV20()
{

}

//----------------------------------------------------------------
void QRCodeV20::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 2061;
    CAP_L_CORRECTION_ALPHANUMERIC       = 1249;
    CAP_L_CORRECTION_BYTE               = 858;
    CAP_L_CORRECTION_KANJI              = 528;

    CAP_M_CORRECTION_NUMERIC            = 1600;
    CAP_M_CORRECTION_ALPHANUMERIC       = 970;
    CAP_M_CORRECTION_BYTE               = 666;
    CAP_M_CORRECTION_KANJI              = 410;

    CAP_Q_CORRECTION_NUMERIC            = 1159;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 702;
    CAP_Q_CORRECTION_BYTE               = 482;
    CAP_Q_CORRECTION_KANJI              = 297;

    CAP_H_CORRECTION_NUMERIC            = 919;
    CAP_H_CORRECTION_ALPHANUMERIC       = 557;
    CAP_H_CORRECTION_BYTE               = 382;
    CAP_H_CORRECTION_KANJI              = 235;
}
//----------------------------------------------------------------

void QRCodeV20::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 861;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 28;
    ECL_LOW_EC_INFO.BlocksGroup1        = 3;
    ECL_LOW_EC_INFO.BlocksGroup2        = 5;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 107;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 108;

    ECL_MEDIUM_EC_INFO.TotalCW          = 669;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 26;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 3;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 13;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 41;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 42;

    ECL_QUALITY_EC_INFO.TotalCW         = 485;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 15;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 5;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 385;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 28;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 15;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 10;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV20::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(34,6));
    AlignementPatterns.push_back(Point(6,34));
    AlignementPatterns.push_back(Point(34,34));
    AlignementPatterns.push_back(Point(6,62));
    AlignementPatterns.push_back(Point(62,6));

    AlignementPatterns.push_back(Point(34,62));
    AlignementPatterns.push_back(Point(62,34));
    AlignementPatterns.push_back(Point(62,62));
    AlignementPatterns.push_back(Point(34,90));
    AlignementPatterns.push_back(Point(90,34));

    AlignementPatterns.push_back(Point(62,90));
    AlignementPatterns.push_back(Point(90,62));
    AlignementPatterns.push_back(Point(90,90));
}
//----------------------------------------------------------------


