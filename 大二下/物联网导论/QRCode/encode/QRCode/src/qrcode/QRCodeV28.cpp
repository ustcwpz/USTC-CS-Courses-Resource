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

#include "QRCodeV28.h"
#include <string.h>
#include <iomanip>

QRCodeV28::QRCodeV28() : QRCode()
{
    Version             = 28;
    Modules             = 129;
    REMINDER_BIT_COUNT  = 3;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV28::~QRCodeV28()
{

}

//----------------------------------------------------------------
void QRCodeV28::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 3669;
    CAP_L_CORRECTION_ALPHANUMERIC       = 2223;
    CAP_L_CORRECTION_BYTE               = 1528;
    CAP_L_CORRECTION_KANJI              = 940;

    CAP_M_CORRECTION_NUMERIC            = 2857;
    CAP_M_CORRECTION_ALPHANUMERIC       = 1732;
    CAP_M_CORRECTION_BYTE               = 1190;
    CAP_M_CORRECTION_KANJI              = 732;

    CAP_Q_CORRECTION_NUMERIC            = 2085;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 1263;
    CAP_Q_CORRECTION_BYTE               = 868;
    CAP_Q_CORRECTION_KANJI              = 534;

    CAP_H_CORRECTION_NUMERIC            = 1581;
    CAP_H_CORRECTION_ALPHANUMERIC       = 958;
    CAP_H_CORRECTION_BYTE               = 658;
    CAP_H_CORRECTION_KANJI              = 405;
}
//----------------------------------------------------------------

void QRCodeV28::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 1531;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 3;
    ECL_LOW_EC_INFO.BlocksGroup2        = 10;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 117;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 118;

    ECL_MEDIUM_EC_INFO.TotalCW          = 1193;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 3;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 23;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 45;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 46;

    ECL_QUALITY_EC_INFO.TotalCW         = 871;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 4;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 31;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 661;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 11;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 31;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV28::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(26,6));
    AlignementPatterns.push_back(Point(50,6));
    AlignementPatterns.push_back(Point(74,6));
    AlignementPatterns.push_back(Point(98,6));

    AlignementPatterns.push_back(Point(6,26));
    AlignementPatterns.push_back(Point(26,26));
    AlignementPatterns.push_back(Point(50,26));
    AlignementPatterns.push_back(Point(74,26));
    AlignementPatterns.push_back(Point(98,26));
    AlignementPatterns.push_back(Point(122,26));

    AlignementPatterns.push_back(Point(6,50));
    AlignementPatterns.push_back(Point(26,50));
    AlignementPatterns.push_back(Point(50,50));
    AlignementPatterns.push_back(Point(74,50));
    AlignementPatterns.push_back(Point(98,50));
    AlignementPatterns.push_back(Point(122,50));

    AlignementPatterns.push_back(Point(6,74));
    AlignementPatterns.push_back(Point(26,74));
    AlignementPatterns.push_back(Point(50,74));
    AlignementPatterns.push_back(Point(74,74));
    AlignementPatterns.push_back(Point(98,74));
    AlignementPatterns.push_back(Point(122,74));

    AlignementPatterns.push_back(Point(6,98));
    AlignementPatterns.push_back(Point(26,98));
    AlignementPatterns.push_back(Point(50,98));
    AlignementPatterns.push_back(Point(74,98));
    AlignementPatterns.push_back(Point(98,98));
    AlignementPatterns.push_back(Point(122,98));

    AlignementPatterns.push_back(Point(26,122));
    AlignementPatterns.push_back(Point(50,122));
    AlignementPatterns.push_back(Point(74,122));
    AlignementPatterns.push_back(Point(98,122));
    AlignementPatterns.push_back(Point(122,122));
}
//----------------------------------------------------------------


