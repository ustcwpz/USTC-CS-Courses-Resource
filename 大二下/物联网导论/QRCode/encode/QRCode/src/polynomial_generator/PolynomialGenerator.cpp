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

#include "PolynomialGenerator.h"
#include <math.h>
#include <QtCore>

PolynomialGenerator::PolynomialGenerator()
{

}
//-------------------------------------------------------------------

PolynomialGenerator::~PolynomialGenerator()
{

}
//-------------------------------------------------------------------

vector<Monomial> PolynomialGenerator::getPolynomial(int ec_codewords)
{
    vector<Monomial> A;
    vector<Monomial> B;
    vector<Monomial> C;

    A.clear();
    B.clear();
    C.clear();

    A.push_back(Monomial(0,1));
    A.push_back(Monomial(0,0));

    int idx_x = -1;
    for (int j = 1; j < ec_codewords; j++)
    {
        B.clear();

        B.push_back(Monomial(0,1));
        B.push_back(Monomial(j,0));

        for (int i = 0; i < A.size(); i++)
        {
            Monomial c;
            c.ExpA = A.at(i).ExpA+B.at(0).ExpA;
            c.ExpX = A.at(i).ExpX+B.at(0).ExpX;
            if (c.ExpA > 255)
                c.ExpA = (c.ExpA % 256) + floor(c.ExpA / 256);

            if(c.ExpX > 255)
                c.ExpX = (c.ExpX % 256) + floor(c.ExpX / 256);

            idx_x = ExistsExpX(C, c.ExpX);
            if (C.size() > 0 && idx_x >= 0)
            {
                //c = C.at(idx_x) + c;
                Monomial::Combine(c, C.at(idx_x), c);
                C.erase(C.begin()+idx_x);

                C.insert(C.begin()+idx_x, c);
            }
            else
                C.push_back(c);
        }

        for (int i = 0; i < A.size(); i++)
        {
            Monomial c;
            c.ExpA = A.at(i).ExpA+B.at(1).ExpA;
            c.ExpX = A.at(i).ExpX+B.at(1).ExpX;
            if (c.ExpA > 255)
                c.ExpA = (c.ExpA % 256) + floor(c.ExpA / 256);

            if(c.ExpX > 255)
                c.ExpX = (c.ExpX % 256) + floor(c.ExpX / 256);

            idx_x = ExistsExpX(C, c.ExpX);

            if (C.size() > 0 && idx_x >= 0)
            {
                //c = C.at(idx_x) + c;
                Monomial::Combine(c, C.at(idx_x), c);
                C.erase(C.begin()+idx_x);

                C.insert(C.begin()+idx_x, c);
            }
            else
                C.push_back(c);
        }

        A = C;
        C.clear();
    }

    return A;
}
//-------------------------------------------------------------------
string PolynomialGenerator::ConvertToString(vector<Monomial> monomial_list)
{
    string res = "";

    for (int i = 0; i < monomial_list.size(); i++)
    {
        res +=  monomial_list.at(i).toString();

        if (i < monomial_list.size() -1)
            res += " + ";
    }

    return res;
}
//-------------------------------------------------------------------

int PolynomialGenerator::ExistsExpX(vector<Monomial> monomial_list, int exp_x)
{
    int res = -1;

    for (int i = 0; i < monomial_list.size(); i++)
    {
        if (monomial_list.at(i).ExpX == exp_x)
        {
            res = i;
            break;
        }
    }

    return res;
}

//-------------------------------------------------------------------
