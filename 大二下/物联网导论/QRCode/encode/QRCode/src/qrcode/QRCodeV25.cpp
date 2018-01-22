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

#include "QRCodeV25.h"
#include <string.h>
#include <iomanip>

QRCodeV25::QRCodeV25() : QRCode()
{
    Version             = 25;
    Modules             = 117;
    REMINDER_BIT_COUNT  = 4;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV25::~QRCodeV25()
{

}

//----------------------------------------------------------------
void QRCodeV25::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 3057;
    CAP_L_CORRECTION_ALPHANUMERIC       = 1853;
    CAP_L_CORRECTION_BYTE               = 1273;
    CAP_L_CORRECTION_KANJI              = 784;

    CAP_M_CORRECTION_NUMERIC            = 2395;
    CAP_M_CORRECTION_ALPHANUMERIC       = 1451;
    CAP_M_CORRECTION_BYTE               = 997;
    CAP_M_CORRECTION_KANJI              = 614;

    CAP_Q_CORRECTION_NUMERIC            = 1718;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 1041;
    CAP_Q_CORRECTION_BYTE               = 715;
    CAP_Q_CORRECTION_KANJI              = 440;

    CAP_H_CORRECTION_NUMERIC            = 1286;
    CAP_H_CORRECTION_ALPHANUMERIC       = 779;
    CAP_H_CORRECTION_BYTE               = 535;
    CAP_H_CORRECTION_KANJI              = 330;
}
//----------------------------------------------------------------

void QRCodeV25::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 1276;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 26;
    ECL_LOW_EC_INFO.BlocksGroup1        = 8;
    ECL_LOW_EC_INFO.BlocksGroup2        = 4;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 106;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 107;

    ECL_MEDIUM_EC_INFO.TotalCW          = 1000;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 8;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 13;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 47;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 48;

    ECL_QUALITY_EC_INFO.TotalCW         = 718;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 7;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 22;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 538;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 22;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 13;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV25::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(32,6));
    AlignementPatterns.push_back(Point(58,6));
    AlignementPatterns.push_back(Point(84,6));

    AlignementPatterns.push_back(Point(6,32));
    AlignementPatterns.push_back(Point(32,32));
    AlignementPatterns.push_back(Point(58,32));
    AlignementPatterns.push_back(Point(84,32));
    AlignementPatterns.push_back(Point(110,32));

    AlignementPatterns.push_back(Point(6,58));
    AlignementPatterns.push_back(Point(32,58));
    AlignementPatterns.push_back(Point(58,58));
    AlignementPatterns.push_back(Point(84,58));
    AlignementPatterns.push_back(Point(110,58));

    AlignementPatterns.push_back(Point(6,84));
    AlignementPatterns.push_back(Point(32,84));
    AlignementPatterns.push_back(Point(58,84));
    AlignementPatterns.push_back(Point(84,84));
    AlignementPatterns.push_back(Point(110,84));

    AlignementPatterns.push_back(Point(32,110));
    AlignementPatterns.push_back(Point(58,110));
    AlignementPatterns.push_back(Point(84,110));
    AlignementPatterns.push_back(Point(110,110));
}
//----------------------------------------------------------------


