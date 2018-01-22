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

#include "QRController.h"

void test_version(eVersions version)
{
    string data              = "";

    int width                = 500;
    int height               = 500;

    eCorrectionLevel ecl     = eclLow;

    QRController* controller = new QRController(data, ecl, width, height, version);


    //Numeric
    controller->setData("0123456789");

    controller->setCorrectionLevel(eclLow);
    controller->SaveToFile("./numeric_low.bmp");

    controller->setCorrectionLevel(eclMedium);
    controller->SaveToFile("./numeric_medium.bmp");

    controller->setCorrectionLevel(eclQuality);
    controller->SaveToFile("./numeric_quality.bmp");

    controller->setCorrectionLevel(eclHigh);
    controller->SaveToFile("./numeric_high.bmp");


    //AplhaNUmeric
    controller->setData("HELLO WORLD");

    controller->setCorrectionLevel(eclLow);
    controller->SaveToFile("./alpha_low.bmp");

    controller->setCorrectionLevel(eclMedium);
    controller->SaveToFile("./alpha_medium.bmp");

    controller->setCorrectionLevel(eclQuality);
    controller->SaveToFile("./alpha_quality.bmp");

    controller->setCorrectionLevel(eclHigh);
    controller->SaveToFile("./alpha_high.bmp");


    //Byte
    controller->setData("Hello World");

    controller->setCorrectionLevel(eclLow);
    controller->SaveToFile("./byte_low.bmp");

    controller->setCorrectionLevel(eclMedium);
    controller->SaveToFile("./byte_medium.bmp");

    controller->setCorrectionLevel(eclQuality);
    controller->SaveToFile("./byte_quality.bmp");

    controller->setCorrectionLevel(eclHigh);
    controller->SaveToFile("./byte_high.bmp");

    delete controller;
}
