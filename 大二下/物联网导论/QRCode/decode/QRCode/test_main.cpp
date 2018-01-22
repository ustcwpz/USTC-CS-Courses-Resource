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

#include <string.h>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <stdlib.h>
#include "QRController.h"

using namespace std;

typedef struct _params
{
    bool Verbose;
    int Version;
    int Width;
    int Height;
    string Data;
    string of;
    eCorrectionLevel ECL;

    _params(void)
    {
        Verbose = false;
        Version = 0;
        Width   = 300;
        Height  = 300;
        Data    = "QR CODE";
        of      = "./out.bmp";
        ECL     = eclLow;

    }
}params;

string load_from_file(char* file_name)
{
    string data = "";

    ifstream f(file_name);

    f.seekg(0, std::ios::end);
    data.reserve(f.tellg());
    f.seekg(0, std::ios::beg);

    data.assign((std::istreambuf_iterator<char>(f)),
            std::istreambuf_iterator<char>());

    f.close();

    return data;
}

void parse_parameters(int argc, char* argv[], params &p)
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp (argv[i],"-w") == 0)
        {
            i++;
            if (atoi(argv[i]) > 0)
                p.Width = atoi(argv[i]);
        }
        else if (strcmp (argv[i],"-h") == 0)
        {
            i++;
            if (atoi(argv[i]) > 0)
                p.Height = atoi(argv[i]);
        }

        else if (strcmp (argv[i],"-ecl") == 0)
        {
            i++;

            if (strcmp (argv[i],"L") == 0)
                p.ECL = eclLow;
            else if (strcmp (argv[i],"M") == 0)
                p.ECL = eclMedium;
            else if (strcmp (argv[i],"Q") == 0)
                p.ECL = eclQuality;
            else if (strcmp (argv[i],"H") == 0)
                p.ECL = eclHigh;
        }
        else if (strcmp (argv[i],"-v") == 0)
        {
            i++;

            if (atoi(argv[i]) >= 0 && atoi(argv[i]) <= 40)
                p.Version = atoi(argv[i]);
        }
        else if (strcmp (argv[i],"-if") == 0)
        {
            i++;

            string data = load_from_file(argv[i]);

            if (data.length() > 0)
                p.Data = data;
        }
        else if (strcmp (argv[i],"-d") == 0)
            p.Data = argv[++i];
        else if (strcmp (argv[i],"-of") == 0)
            p.of = argv[++i];
        else if (strcmp (argv[i],"--V") == 0)
            p.Verbose = true;
    }
}

void show_license(void)
{
    printf("QR CODE Version 1.0\n"
           "Copyright (C) 2014 Stefano BARILETTI <hackaroth@gmail.com>\n\n"
           "This program is free software: you can redistribute it and/or modify it\n"
           "under the terms of the GNU General Public License as published by the\n"
           "Free Software Foundation, either version 3 of the License, or\n"
           "(at your option) any later version.\n\n"
            "This program is distributed in the hope that it will be useful, but\n"
            "WITHOUT ANY WARRANTY; without even the implied warranty of\n"
            "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"
            "See the GNU General Public License for more details.\n\n");
}

void show_help(void)
{
    printf("USAGE:\n"
           "QRCODE -v, -w, -h, -ecl, -if, -d, -of, --V, --help\n\n"
           "-v\tQR Code Version: From 0 to 40\n\tSet 0 for auto version selection.\n\n"
           "-w\tImage width\n\tSet the width of the output image\n\n"
           "-h\tImage height\n\tSet the height of the output image\n\n"
           "-ecl\tError correction level: L, M, Q, H\n\tSet the error correction level of the qr code.\n\tDefault value is L\n\n"
           "-if\tInput File\n\tCreate a Qr Code reading data from a file\n\n"
           "-d\tData\n\tSpecifies the data that must be encoded.\n\tIf the -if option is specified, this option take precedence \n\n"
           "-of\tOutput File\n\tSpecifies the output file name and path\n\n"
           "--V\tVerbose\n\tShow the Qr Code settings\n\n"
           "--help\tHelp\n\tShow this help\n\n");
}


int test_main(int argc, char* argv[])
{
    show_license();

    params p;

    if (argc > 1 && strcmp (argv[1],"--help") == 0)
    {
        show_help();
    }
    else
    {
        parse_parameters(argc, argv, p);

        if (p.Verbose)
        {
            cout << "*** SETTINGS ***" << endl;
            cout << "Ver:\t" << p.Version << endl;
            cout << "Width:\t" << p.Width << endl;
            cout << "Height:\t" << p.Height << endl;
            cout << "ECL:\t" << p.ECL << endl;
            cout << "Output:\t" << p.of << endl;
            cout << endl;
            cout << p.Data << endl;
        }

        QRController* controller = new QRController(p.Data, p.ECL, p.Width, p.Height, p.Version);

        controller->SaveToFile(p.of);

        delete controller;
    }


    return 0;
}
