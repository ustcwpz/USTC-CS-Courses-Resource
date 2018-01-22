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

#include "QRCodeV13.h"
#include <string.h>
#include <iomanip>

QRCodeV13::QRCodeV13() : QRCode()
{
    Version             = 13;
    Modules             = 69;
    REMINDER_BIT_COUNT  = 0;
    VersionInfoRequired = true;

    InitCapabilities();
    InitECInfo();
    InitAlignementPatterns();
}
//-------------------------------------------------------------------

QRCodeV13::~QRCodeV13()
{

}

//----------------------------------------------------------------
void QRCodeV13::InitCapabilities(void)
{
    CAP_L_CORRECTION_NUMERIC            = 1022;
    CAP_L_CORRECTION_ALPHANUMERIC       = 619;
    CAP_L_CORRECTION_BYTE               = 425;
    CAP_L_CORRECTION_KANJI              = 262;

    CAP_M_CORRECTION_NUMERIC            = 796;
    CAP_M_CORRECTION_ALPHANUMERIC       = 483;
    CAP_M_CORRECTION_BYTE               = 331;
    CAP_M_CORRECTION_KANJI              = 204;

    CAP_Q_CORRECTION_NUMERIC            = 580;
    CAP_Q_CORRECTION_ALPHANUMERIC       = 352;
    CAP_Q_CORRECTION_BYTE               = 241;
    CAP_Q_CORRECTION_KANJI              = 149;

    CAP_H_CORRECTION_NUMERIC            = 427;
    CAP_H_CORRECTION_ALPHANUMERIC       = 259;
    CAP_H_CORRECTION_BYTE               = 177;
    CAP_H_CORRECTION_KANJI              = 109;
}
//----------------------------------------------------------------

void QRCodeV13::InitECInfo(void)
{
    ECL_LOW_EC_INFO.TotalCW             = 428;
    ECL_LOW_EC_INFO.EC_CWPerBlocks      = 26;
    ECL_LOW_EC_INFO.BlocksGroup1        = 4;
    ECL_LOW_EC_INFO.BlocksGroup2        = 0;
    ECL_LOW_EC_INFO.CWBlockGroup1       = 107;
    ECL_LOW_EC_INFO.CWBlockGroup2       = 0;

    ECL_MEDIUM_EC_INFO.TotalCW          = 334;
    ECL_MEDIUM_EC_INFO.EC_CWPerBlocks   = 22;
    ECL_MEDIUM_EC_INFO.BlocksGroup1     = 8;
    ECL_MEDIUM_EC_INFO.BlocksGroup2     = 1;
    ECL_MEDIUM_EC_INFO.CWBlockGroup1    = 37;
    ECL_MEDIUM_EC_INFO.CWBlockGroup2    = 38;

    ECL_QUALITY_EC_INFO.TotalCW         = 244;
    ECL_QUALITY_EC_INFO.EC_CWPerBlocks  = 24;
    ECL_QUALITY_EC_INFO.BlocksGroup1    = 8;
    ECL_QUALITY_EC_INFO.BlocksGroup2    = 4;
    ECL_QUALITY_EC_INFO.CWBlockGroup1   = 20;
    ECL_QUALITY_EC_INFO.CWBlockGroup2   = 21;

    ECL_HIGH_EC_INFO.TotalCW            = 180;
    ECL_HIGH_EC_INFO.EC_CWPerBlocks     = 22;
    ECL_HIGH_EC_INFO.BlocksGroup1       = 12;
    ECL_HIGH_EC_INFO.BlocksGroup2       = 4;
    ECL_HIGH_EC_INFO.CWBlockGroup1      = 11;
    ECL_HIGH_EC_INFO.CWBlockGroup2      = 12;
}
//----------------------------------------------------------------

void QRCodeV13::InitAlignementPatterns(void)
{
    AlignementPatterns.push_back(Point(34,6));
    AlignementPatterns.push_back(Point(6,34));
    AlignementPatterns.push_back(Point(34,34));
    AlignementPatterns.push_back(Point(62,34));
    AlignementPatterns.push_back(Point(34,62));
    AlignementPatterns.push_back(Point(62,62));
}
//----------------------------------------------------------------


