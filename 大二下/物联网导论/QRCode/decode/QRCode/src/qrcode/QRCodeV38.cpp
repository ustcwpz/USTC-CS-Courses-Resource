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

#include "QRCodeV38.h"
#include <string.h>
#include <iomanip>

QRCodeV38::QRCodeV38() : QRCode()
{
    Version             = 38;
    Modules             = 169;
    REMINDER_BIT_COUNT  = 0;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV38::~QRCodeV38()
{

}

//----------------------------------------------------------------
void QRCodeV38::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 6479;
    CAP_L_CORRECTION_ALPHANUMERIC       = 3927;
    CAP_L_CORRECTION_BYTE               = 2699;
    CAP_L_CORRECTION_KANJI              = 1661;

    CAP_M_CORRECTION_NUMERIC            = 5039;
    CAP_M_CORRECTION_ALPHANUMERIC       = 3054;
    CAP_M_CORRECTION_BYTE               = 2099;
    CAP_M_CORRECTION_KANJI              = 1292;

    CAP_Q_CORRECTION_NUMERIC            = 3599;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 2181;
    CAP_Q_CORRECTION_BYTE               = 1499;
    CAP_Q_CORRECTION_KANJI              = 923;

    CAP_H_CORRECTION_NUMERIC            = 2735;
    CAP_H_CORRECTION_ALPHANUMERIC       = 1658;
    CAP_H_CORRECTION_BYTE               = 1139;
    CAP_H_CORRECTION_KANJI              = 701;
}
//----------------------------------------------------------------

void QRCodeV38::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 2702;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 30;
    ECL_LOW_EC_INFO.BlocksGroup1        = 4;
    ECL_LOW_EC_INFO.BlocksGroup2        = 18;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 122;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 123;

    ECL_MEDIUM_EC_INFO.TotalCW          = 2102;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 28;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 13;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 32;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 46;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 47;

    ECL_QUALITY_EC_INFO.TotalCW         = 1502;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 30;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 48;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 14;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 24;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 25;

    ECL_HIGH_EC_INFO.TotalCW            = 1142;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 30;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 42;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 32;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 15;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 16;
}
//----------------------------------------------------------------

void QRCodeV38::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(32,6));
    AlignementPatterns.push_back(Point(58,6));
    AlignementPatterns.push_back(Point(84,6));
    AlignementPatterns.push_back(Point(110,6));
    AlignementPatterns.push_back(Point(136,6));

    AlignementPatterns.push_back(Point(6,32));
    AlignementPatterns.push_back(Point(32,32));
    AlignementPatterns.push_back(Point(58,32));
    AlignementPatterns.push_back(Point(84,32));
    AlignementPatterns.push_back(Point(110,32));
    AlignementPatterns.push_back(Point(136,32));
    AlignementPatterns.push_back(Point(162,32));

    AlignementPatterns.push_back(Point(6,58));
    AlignementPatterns.push_back(Point(32,58));
    AlignementPatterns.push_back(Point(58,58));
    AlignementPatterns.push_back(Point(84,58));
    AlignementPatterns.push_back(Point(110,58));
    AlignementPatterns.push_back(Point(136,58));
    AlignementPatterns.push_back(Point(162,58));

    AlignementPatterns.push_back(Point(6,84));
    AlignementPatterns.push_back(Point(32,84));
    AlignementPatterns.push_back(Point(58,84));
    AlignementPatterns.push_back(Point(84,84));
    AlignementPatterns.push_back(Point(110,84));
    AlignementPatterns.push_back(Point(136,84));
    AlignementPatterns.push_back(Point(162,84));

    AlignementPatterns.push_back(Point(6,110));
    AlignementPatterns.push_back(Point(32,110));
    AlignementPatterns.push_back(Point(58,110));
    AlignementPatterns.push_back(Point(84,110));
    AlignementPatterns.push_back(Point(110,110));
    AlignementPatterns.push_back(Point(136,110));
    AlignementPatterns.push_back(Point(162,110));

    AlignementPatterns.push_back(Point(6,136));
    AlignementPatterns.push_back(Point(32,136));
    AlignementPatterns.push_back(Point(58,136));
    AlignementPatterns.push_back(Point(84,136));
    AlignementPatterns.push_back(Point(110,136));
    AlignementPatterns.push_back(Point(136,136));
    AlignementPatterns.push_back(Point(162,136));

    AlignementPatterns.push_back(Point(32,162));
    AlignementPatterns.push_back(Point(58,162));
    AlignementPatterns.push_back(Point(84,162));
    AlignementPatterns.push_back(Point(110,162));
    AlignementPatterns.push_back(Point(136,162));
    AlignementPatterns.push_back(Point(162,162));
}
//----------------------------------------------------------------


