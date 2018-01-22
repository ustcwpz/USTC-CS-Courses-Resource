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

#include "Monomial.h"
#include <sstream>
#include <QtCore>

Monomial::Monomial() :
    ExpA(0)
,   ExpX(0)
{
}

Monomial::Monomial(int exp_a, int exp_x) :
    ExpA(exp_a)
,   ExpX(exp_x)
{
}

void Monomial::Combine(Monomial &ouput, Monomial &inputA, Monomial &inputB)
{
    int exp_a1   = inputA.ExpA;
    int exp_a2   = inputB.ExpA;

    int a1_value = Log[exp_a1];
    int a2_value = Log[exp_a2];

    int a_xor    = a1_value ^ a2_value;

    int exp_a    = AntiLog[a_xor];

    ouput.ExpA = exp_a;
    ouput.ExpX = inputA.ExpX;
}

//-------------------------------------------------------------------
int Monomial::getLog(int idx)
{
    return Log[idx];
}
//-------------------------------------------------------------------
int Monomial::getAntiLog(int idx)
{
    return AntiLog[idx];
}
//-------------------------------------------------------------------

string Monomial::NumberToString (int number)
{
	stringstream str;
	str << number;
	return str.str();
}
//-------------------------------------------------------------------

string Monomial::toString()
{
    string res = "";

    if (ExpA > 0 && ExpX > 0)
        res = "a" + NumberToString(ExpA) + " x" + NumberToString(ExpX);
    else if (ExpA == 0 && ExpX > 0)
        res = "x" + NumberToString(ExpX);
    else if (ExpA > 0 && ExpX == 0)
        res = "a" + NumberToString(ExpA);

    return res;
}
//-------------------------------------------------------------------
