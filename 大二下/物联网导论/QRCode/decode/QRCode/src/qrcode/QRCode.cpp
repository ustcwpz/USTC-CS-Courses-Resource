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

#include "QRCode.h"
#include <math.h>
#include <string.h>
#include "EQRCapabilities.h"
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include "EQRErrorCorrection.h"
#include "EQRGeneric.h"

QRCode::QRCode()
{
    Modules              = 0;
    ErrorCorrectonLevel  = eclLow;
    VersionInfoRequired  = false;

    AlignementPatterns.clear();
}
//-------------------------------------------------------------------
QRCode::~QRCode()
{

}

//-------------------------------------------------------------------

bool QRCode::IsVersionInfoRequired(void)
{
    return VersionInfoRequired;
}
//-------------------------------------------------------------------

vector<Point> QRCode::getAlignementPatterns(void)
{
    return AlignementPatterns;
}
//-------------------------------------------------------------------
bool QRCode::CheckDataCapabilities(void)
{
    bool check      = false;
    int data_lenght = strlen(Data.c_str());

    if (ErrorCorrectonLevel == eclLow)
    {
        if (Mode == emNumeric)
            check = (data_lenght <= CAP_L_CORRECTION_NUMERIC);
        else if (Mode == emAlphanumeric)
            check = (data_lenght <= CAP_L_CORRECTION_ALPHANUMERIC);
        else if (Mode == emByte)
            check = (data_lenght <= CAP_L_CORRECTION_BYTE);
        else if (Mode == emKanji)
            check = (data_lenght <= CAP_L_CORRECTION_KANJI);
        else
            check = false;

    }
    else if (ErrorCorrectonLevel == eclMedium)
    {
        if (Mode == emNumeric)
            check = (data_lenght <= CAP_M_CORRECTION_NUMERIC);
        else if (Mode == emAlphanumeric)
            check = (data_lenght <= CAP_M_CORRECTION_ALPHANUMERIC);
        else if (Mode == emByte)
            check = (data_lenght <= CAP_M_CORRECTION_BYTE);
        else if (Mode == emKanji)
            check = (data_lenght <= CAP_M_CORRECTION_KANJI);
        else
            check = false;

    }
    else if (ErrorCorrectonLevel == eclQuality)
    {
        if (Mode == emNumeric)
            check = (data_lenght <= CAP_Q_CORRECTION_NUMERIC);
        else if (Mode == emAlphanumeric)
            check = (data_lenght <= CAP_Q_CORRECTION_ALPHANUMERIC);
        else if (Mode == emByte)
            check = (data_lenght <= CAP_Q_CORRECTION_BYTE);
        else if (Mode == emKanji)
            check = (data_lenght <= CAP_Q_CORRECTION_KANJI);
        else
            check = false;
    }
    else
    {
        if (Mode == emNumeric)
            check = (data_lenght <= CAP_H_CORRECTION_NUMERIC);
        else if (Mode == emAlphanumeric)
            check = (data_lenght <= CAP_H_CORRECTION_ALPHANUMERIC);
        else if (Mode == emByte)
            check = (data_lenght <= CAP_H_CORRECTION_BYTE);
        else if (Mode == emKanji)
            check = (data_lenght <= CAP_H_CORRECTION_KANJI);
        else
            check = false;
    }

    return check;

}
//----------------------------------------------------------------
bool QRCode::CanContainData(void)
{
    bool res = false;

    SelectMode();

    res = CheckDataCapabilities();

    return res;
}
//----------------------------------------------------------------

string QRCode::getCountIndicator(void)
{
    int padding_size    = 0;
    int data_length     = strlen(Data.c_str());
    string binary_data  = DecimalToBinary(data_length);

    if (Version >= 1 && Version <= 9)
    {
        if (Mode == emNumeric)
            padding_size = 10;
        else if (Mode == emAlphanumeric)
            padding_size = 9;
        else if (Mode == emByte)
            padding_size = 8;
        else
            padding_size = 8;
    }
    else if (Version >= 10 && Version <= 26)
    {
        if (Mode == emNumeric)
            padding_size = 12;
        else if (Mode == emAlphanumeric)
            padding_size = 11;
        else if (Mode == emByte)
            padding_size = 16;
        else
            padding_size = 10;
    }
    else if (Version >= 27 && Version <= 40)
    {
        if (Mode == emNumeric)
            padding_size = 14;
        else if (Mode == emAlphanumeric)
            padding_size = 13;
        else if (Mode == emByte)
            padding_size = 16;
        else
            padding_size = 12;
    }

    while (strlen(binary_data.c_str()) < padding_size)
        binary_data.insert(0, "0");

    return binary_data;
}
//----------------------------------------------------------------
int QRCode::getReminderBitsCount(void)
{
    return REMINDER_BIT_COUNT;
}
//----------------------------------------------------------------
ECInfo QRCode::getECInfo(void)
{
    ECInfo res;

    if (ErrorCorrectonLevel == eclLow)
        res = ECL_LOW_EC_INFO;
    else if (ErrorCorrectonLevel == eclMedium)
        res = ECL_MEDIUM_EC_INFO;
    else if (ErrorCorrectonLevel == eclQuality)
        res = ECL_QUALITY_EC_INFO;
    else if (ErrorCorrectonLevel == eclHigh)
        res = ECL_HIGH_EC_INFO;

    return res;
}

//----------------------------------------------------------------

void QRCode::SelectMode(void)
{
    int number_count        = 0;
    int alphanumeric_count  = 0;
    int byte_count          = 0;

    int data_lenght         = strlen(Data.c_str());

    for (int i = 0; i < data_lenght; i++)
    {
        if ((int)Data[i] >= 48 && (int)Data[i] <= 57)
            number_count++;
        else if (((int)Data[i] >= 65 && (int)Data[i] <= 90) ||
                 (int)Data[i] == 32 || (int)Data[i] == 36 ||
                 (int)Data[i] == 37 || (int)Data[i] == 42 ||
                 (int)Data[i] == 43 || (int)Data[i] == 45 ||
                 (int)Data[i] == 46 || (int)Data[i] == 47 ||
                 (int)Data[i] == 58)
            alphanumeric_count++;
        else
            byte_count++;
    }

    if (byte_count > 0)
        Mode = emByte;
    else if (alphanumeric_count > 0)
        Mode = emAlphanumeric;
    else if (number_count > 0)
        Mode = emNumeric;
}
//-------------------------------------------------------------------

void QRCode::setData(string data)
{
    Data = data;
}
//-------------------------------------------------------------------

string QRCode::getData(void)
{
    return Data;
}

//-------------------------------------------------------------------
void QRCode::setErrorCorrectionLevel(eCorrectionLevel error_correction_level)
{
    ErrorCorrectonLevel = error_correction_level;
}
//-------------------------------------------------------------------

eCorrectionLevel QRCode::getCorrectionLevel(void)
{
    return ErrorCorrectonLevel;
}
//-------------------------------------------------------------------

int QRCode::getVersion(void)
{
    return Version;
}
//-------------------------------------------------------------------

int QRCode::getModules(void)
{
    return Modules;
}
//-------------------------------------------------------------------
int QRCode::getAlphanumericValue(char character)
{
    int res = -1;

    if (character == '0') res = 0;
    else if (character == '1') res = 1;
    else if (character == '2') res = 2;
    else if (character == '3') res = 3;
    else if (character == '4') res = 4;
    else if (character == '5') res = 5;
    else if (character == '6') res = 6;
    else if (character == '7') res = 7;
    else if (character == '8') res = 8;
    else if (character == '9') res = 9;
    else if (character == 'A') res = 10;
    else if (character == 'B') res = 11;
    else if (character == 'C') res = 12;
    else if (character == 'D') res = 13;
    else if (character == 'E') res = 14;
    else if (character == 'F') res = 15;
    else if (character == 'G') res = 16;
    else if (character == 'H') res = 17;
    else if (character == 'I') res = 18;
    else if (character == 'J') res = 19;
    else if (character == 'K') res = 20;
    else if (character == 'L') res = 21;
    else if (character == 'M') res = 22;
    else if (character == 'N') res = 23;
    else if (character == 'O') res = 24;
    else if (character == 'P') res = 25;
    else if (character == 'Q') res = 26;
    else if (character == 'R') res = 27;
    else if (character == 'S') res = 28;
    else if (character == 'T') res = 29;
    else if (character == 'U') res = 30;
    else if (character == 'V') res = 31;
    else if (character == 'W') res = 32;
    else if (character == 'X') res = 33;
    else if (character == 'Y') res = 34;
    else if (character == 'Z') res = 35;
    else if (character == ' ') res = 36;
    else if (character == '$') res = 37;
    else if (character == '%') res = 38;
    else if (character == '*') res = 39;
    else if (character == '+') res = 40;
    else if (character == '-') res = 41;
    else if (character == '.') res = 42;
    else if (character == '/') res = 43;
    else if (character == ':') res = 44;

    return res;
}
//-------------------------------------------------------------------

string QRCode::getModeIndicator(void)
{
    string res = "";

    if (Mode == emNumeric)
        res = "0001";
    else if (Mode == emAlphanumeric)
        res = "0010";
    else if (Mode == emByte)
        res = "0100";
    else if (Mode == emKanji)
        res = "1000";

    return res;
}
//-------------------------------------------------------------------

string QRCode::EncodeNumericMode(void)
{
    string res          = "";
    string temp         = "";
    string binary_data  = "";

    int subset      = 0;
    int data_length = strlen(Data.c_str());

    for (int i = 0; i < data_length; i=i+3)
    {
        temp    = Data.substr(i,3);
        subset  = atoi(temp.c_str());

        binary_data = DecimalToBinary(subset);

        if (strlen(temp.c_str()) == 3)
            binary_data = BinaryPadLeft(binary_data, 10);
        else if (strlen(temp.c_str()) == 2)
            binary_data = BinaryPadLeft(binary_data, 7);
        else
            binary_data = BinaryPadLeft(binary_data, 4);

        res.append(binary_data);
    }

    return res;
}
//-------------------------------------------------------------------
string QRCode::EncodeAlphanumericMode(void)
{
    string res          = "";
    string binary_value = "";
    int idx             = 1;
    int padding_count   = 0;
    int char_value      = -1;

    int data_length = strlen(Data.c_str());

    for (int i = 0; i < data_length; i++)
    {
        if (idx == 1 && i < data_length-1)
        {
            char_value = getAlphanumericValue(Data[i]);
            char_value *= 45;

            idx++;
        }
        else if (idx == 2 || i == data_length-1)
        {
            if (char_value < 0)
                char_value  = getAlphanumericValue(Data[i]);
            else
                char_value  += getAlphanumericValue(Data[i]);

            binary_value    = DecimalToBinary(char_value);
            padding_count   = (idx==1)?6:11;
            binary_value    = BinaryPadLeft(binary_value, padding_count);

            char_value      = 0;
            idx             = 1;

            res             += binary_value;
        }
    }

    return res;
}
//-------------------------------------------------------------------
string QRCode::EncodeByteMode(void)
{
    string res          = "";
    string binary_value = "";
    int padding_count   = 8;
    int char_value      = 0;

    int data_length = strlen(Data.c_str());

    for (int i = 0; i < data_length; i++)
    {
        char_value      = (int)((unsigned char)Data[i]);
        binary_value    = DecimalToBinary(char_value);
        binary_value    = BinaryPadLeft(binary_value, padding_count);

        res += binary_value;
    }

    return res;
}
//-------------------------------------------------------------------
string QRCode::EncodeKanjiMode(void)
{
    throw EQRGeneric("Encode mode not implemented yet");
    return "";
}
//-------------------------------------------------------------------
string QRCode::getEncodedData(void)
{
    string res = "";

    if (Mode == emNumeric)
        res = EncodeNumericMode();
    else if (Mode == emAlphanumeric)
        res = EncodeAlphanumericMode();
    else if (Mode == emByte)
        res = EncodeByteMode();
    else if (Mode == emKanji)
        res = EncodeKanjiMode();

    return res;
}
//-------------------------------------------------------------------

string QRCode::EncodeData(void)
{
    string res               = "";

    string mode_indicator    = "";
    string count_indicator   = "";
    string encoded_data      = "";
    string terminator        = "";

    SelectMode();
    if (!CheckDataCapabilities())
        throw EQRCapabilities("Data is too long");

    mode_indicator              = getModeIndicator();
    count_indicator             = getCountIndicator();
    encoded_data                = getEncodedData();
    res                         = mode_indicator + count_indicator + encoded_data;

    ECInfo ec_info              = getECInfo();

    int bits_to_add             = 0;
    int total_bits_requires     = ec_info.TotalCW * 8;
    int data_bits               = strlen(res.c_str());
    int bit_diff                = total_bits_requires - data_bits;

    if (bit_diff > 0 && bit_diff <= 4)
        bits_to_add = bit_diff;
    else if (bit_diff > 4 )
        bits_to_add = 4;

    for (int i=0; i < bits_to_add; i++)
        terminator += "0";

    res += terminator;

    // Pad 0 to the right of the string to make it lenght multiple of 8
    while (strlen(res.c_str()) % 8 != 0)
        res += "0";

    //OK, finally the last step, add pad bytes if the string is too short
    data_bits = strlen(res.c_str());
    int paddind_count = (total_bits_requires - data_bits) / 8;

    for (int i = 0; i < paddind_count; i++)
        res += (i%2 == 0)?"11101100":"00010001";

    return res;
}
//-------------------------------------------------------------------
vector<int> QRCode::SplitEncodedData(string encoded_data, int &data_size)
{
    int i       = 0;
    string str  = "";
    vector<int> res;

    data_size   = 0;

    do
    {
        if (strlen(str.c_str()) == 8)
        {
            res.push_back(BinaryToDecimal(str));
            str = "";
            data_size++;
        }

        str += encoded_data[i];
        i++;
    }
    while (i <= strlen(encoded_data.c_str()));

    return res;
}
//-------------------------------------------------------------------
vector<Monomial> QRCode::getMessagePolynomial(int cw_per_blocks, string encoded_data)
{
    int data_size = 0;
    Monomial value_monomial;

    vector<Monomial> res;

    vector<int> integer_value = SplitEncodedData(encoded_data, data_size);
    Monomial multiplier       = Monomial(0, cw_per_blocks);

    for (int i = 0; i < data_size; i++)
    {
        //To make sure that the exponent of the lead term doesn't become too small
        //during the division, multiply the message polynomial by x^n where n is the
        //number of error correction codewords that are needed.

        //value_monomial = Monomial(integer_value[i], data_size - i - 1) * multiplier;
        value_monomial.ExpA = integer_value[i] + multiplier.ExpA;
        value_monomial.ExpX = (data_size - i - 1) + multiplier.ExpX;
        res.push_back(value_monomial);
    }

    return res;
}
//-------------------------------------------------------------------
vector<Monomial> QRCode::getEC_Moltiplication(vector<Monomial> previous, vector<Monomial> gen_polynomial)
{
    vector<Monomial> res;

    for (int i = 0; i < gen_polynomial.size(); i++)
    {
        int a       = AntiLog[previous.at(0).ExpA];
        int b       = gen_polynomial.at(i).ExpA;
        int a_value = a + b;

        int x_value = previous.at(0).ExpX - i;

        if (a_value > 255)
            a_value = a_value % 255;

        res.push_back(Monomial(Log[a_value], x_value));
    }

    return res;
}
//-------------------------------------------------------------------
vector<Monomial> QRCode::getEC_XORing(vector<Monomial> previous, vector<Monomial> first_step)
{
    vector<Monomial> res;

    int diff = previous.size() - first_step.size() ;
    int cnt  = previous.size();

    if (diff < 0)
        cnt = first_step.size();

    for (int i = 0; i < cnt; i++)
    {
        int a =  (i<previous.size())?previous.at(i).ExpA:0;
        int b =  (i<first_step.size())?first_step.at(i).ExpA:0;

        int a_value = a^b;
        int x_value = (i<previous.size())?previous.at(i).ExpX:first_step.at(i).ExpX;

        if (res.size() > 0 || a_value > 0)
            res.push_back(Monomial(a_value, x_value));
    }
    return res;
}
//-------------------------------------------------------------------

vector<int> QRCode::CreateECPerBlock(int cw_per_block, string data_block)
{
    vector<int> res;

    PolynomialGenerator* generator   = new PolynomialGenerator();
    vector<Monomial> gen_polynomial  = generator->getPolynomial(cw_per_block);
    vector<Monomial> msg_polynomial  = getMessagePolynomial(cw_per_block, data_block);
    vector<Monomial> first_step;
    vector<Monomial> second_step;

    //The lead term of the generator polynomial should also have the same exponent
    //of the message polynomial
    int x_inc_value = msg_polynomial.at(0).ExpX - gen_polynomial.at(0).ExpX;

    if (x_inc_value > 0)
    {
        for (int i = 0; i < gen_polynomial.size(); i++)
            gen_polynomial.at(i).ExpX = x_inc_value + gen_polynomial.at(i).ExpX;
    }

    while (msg_polynomial.back().ExpX > 0)
    {
        first_step  = getEC_Moltiplication(msg_polynomial, gen_polynomial);
        second_step = getEC_XORing(msg_polynomial, first_step);

        first_step.clear();
        msg_polynomial.clear();
        msg_polynomial = second_step;
        second_step.clear();
    }

    for (int i=0; i< msg_polynomial.size(); i++)
        res.push_back(msg_polynomial.at(i).ExpA);

    msg_polynomial.clear();

    delete generator;

    return res;
}
//-------------------------------------------------------------------
string QRCode::BinaryPadLeft(string binary, int length, char* pad_char)
{
    while (strlen(binary.c_str()) < length)
        binary.insert(0, pad_char);

    return binary;
}

//-------------------------------------------------------------------

string QRCode::BinaryPadRight(string binary, int length, char* pad_char)
{
    while (strlen(binary.c_str()) < length)
        binary.append(pad_char);

    return binary;
}
//-------------------------------------------------------------------

vector<string> QRCode::CreateEC(vector<string> data_blocks, int cw_per_blocks)
{
    vector<string> res;

    string binary_block     = "";
    string binary_value     = "";

    vector<int> ec_block;

    for (int i=0; i < data_blocks.size(); i++)
    {
        ec_block = CreateECPerBlock(cw_per_blocks, data_blocks.at(i));

        for (int j = 0; j < ec_block.size(); j++)
        {
            binary_value =  DecimalToBinary(ec_block.at(j));
            binary_block += BinaryPadLeft(binary_value, 8);
        }

        ec_block.clear();
        res.push_back(binary_block);
        binary_block = "";
    }

    ec_block.clear();

    return res;
}
//-------------------------------------------------------------------

string QRCode::NumberToString (int number)
{
	stringstream str;
	str << number;
	return str.str();
}
//-------------------------------------------------------------------

string QRCode::DecimalToBinary(int value)
{
    string res;
    do
    {
        res.insert(0, NumberToString(value%2));
        value=value/2;
    }
    while(value>0);

    return res;
}
//-------------------------------------------------------------------

int QRCode::BinaryToDecimal(string value)
{
    int res = 0;
    int value_size = value.size()-1;
    for (int i = value_size; i >= 0; i--)
    {
        if (value[i] == '1')
            res += pow(2, value_size-i);
    }

    return res;
}

//-------------------------------------------------------------------
string QRCode::getInterlivedCodewords(vector<string> data_blocks, vector<string> error_correction)
{
    /*
    For smaller QR codes that have only one block of data codewords,
    with one set of error correction codewords for that block, no interleaving is necessary.
    Simply place the error correction codewords after the data codewords.
    */

    string res = "";

    if (error_correction.size() == 1)
    {
        for (int i = 0; i < data_blocks.size(); i++)
            res += data_blocks.at(i);

        res += error_correction.at(0);
    }
    else
    {
        ECInfo ec_info  = getECInfo();
        int group1_size = ec_info.CWBlockGroup1 * 8;
        int group2_size = ec_info.CWBlockGroup2 * 8;

        int cnt = (group2_size > group1_size)?group2_size:group1_size;

        for (int i = 0; i < cnt; i+=8)
        {
            for (int j = 0; j < data_blocks.size(); j++)
            {
                if (i < strlen(data_blocks.at(j).c_str()))
                    res += data_blocks.at(j).substr(i, 8);
            }
        }

        for (int i = 0; i < ec_info.EC_CWPerBlocks*8; i+=8)
        {
            for (int j = 0; j < error_correction.size(); j++)
            {
                if (i < strlen(error_correction.at(j).c_str()))
                    res += error_correction.at(j).substr(i, 8);
            }
        }
    }

    return res;
}
//-------------------------------------------------------------------

string QRCode::CreateQRData(void)
{
    string res                      = "";
    string encoded_data             = EncodeData();
    vector<string> data_blocks;

    ECInfo ec_info  = getECInfo();

    int group1_size = ec_info.CWBlockGroup1 * 8;
    int group2_size = ec_info.CWBlockGroup2 * 8;

    for (int i=0; i < ec_info.BlocksGroup1; i++)
        data_blocks.push_back(encoded_data.substr(i*group1_size, group1_size));

    for (int i=0; i < ec_info.BlocksGroup2; i++)
        data_blocks.push_back(encoded_data.substr((group1_size*ec_info.BlocksGroup1) + (i*group2_size), group2_size));

    vector<string> error_correction = CreateEC(data_blocks, ec_info.EC_CWPerBlocks);

    res = getInterlivedCodewords(data_blocks, error_correction);

    int reminder_bits_count = getReminderBitsCount();

    for (int i = 0; i < reminder_bits_count; i++)
        res.append("0");

    return res;
}
//-------------------------------------------------------------------
string QRCode::Binary_XOR(string A, string B)
{
    string res = "";

    for (int i = 0; i < strlen(A.c_str()); i++)
    {
        int a = (A[i] == '0')?0:1;
        int b = (B[i] == '0')?0:1;

        int c = a ^ b;

        res.append(NumberToString(c));
    }

    return res;
}
//-------------------------------------------------------------------

string QRCode::CreateFormatInformation(string mask_id)
{
    string res              = "";
    string gen_polinomyal   = "10100110111";
    string format_mask      = "101010000010010";
    string temp             = "";
    string data             = "";
    string error_correction = "";

    string binary_ecl       = DecimalToBinary(ErrorCorrectonLevel);
    binary_ecl              = BinaryPadLeft(binary_ecl, 2);
    data                    = binary_ecl + mask_id;

    for (int i = 0; i < 10; i++)
        data.append("0");

    temp             = gen_polinomyal;
    temp             = BinaryPadRight(temp, strlen(data.c_str()));

    error_correction = Binary_XOR(temp, data);

    while (error_correction[0] == '0' && strlen(error_correction.c_str()) > 10)
        error_correction.erase(0,1);

    while (strlen(error_correction.c_str()) > 10)
    {
        temp = gen_polinomyal;
        temp = BinaryPadRight(temp, strlen(error_correction.c_str()));

        error_correction = Binary_XOR(temp, error_correction);

        while (error_correction[0] == '0' && strlen(error_correction.c_str()) > 10)
            error_correction.erase(0,1);
    }

    error_correction = BinaryPadLeft(error_correction, 10);
    data             = binary_ecl + mask_id +  error_correction;
    res              = Binary_XOR(data, format_mask);

    return res;
}
//-------------------------------------------------------------------

string QRCode::CreateVersionInformation(void)
{
    string res = "";

    if (VersionInfoRequired)
    {
        string gen_polinomyal   = "1111100100101";
        string data             = "";
        string temp             = "";
        string error_correction = "";

        string binary_ver       = DecimalToBinary(Version);
        binary_ver              = BinaryPadLeft(binary_ver, 6);

        data                    = binary_ver;

        for (int i = 0; i < 12; i++)
            data.append("0");

        temp             = gen_polinomyal;
        temp             = BinaryPadRight(temp, strlen(data.c_str()));

        error_correction = Binary_XOR(temp, data);

        while (error_correction[0] == '0' && strlen(error_correction.c_str()) > 12)
            error_correction.erase(0,1);

        while (strlen(error_correction.c_str()) > 12)
        {
            temp = gen_polinomyal;
            temp = BinaryPadRight(temp, strlen(error_correction.c_str()));

            error_correction = Binary_XOR(temp, error_correction);

            while (error_correction[0] == '0' && strlen(error_correction.c_str()) > 12)
                error_correction.erase(0,1);
        }

        error_correction = BinaryPadLeft(error_correction, 12);
        res              = binary_ver + error_correction;
    }

    return res;
}
//-------------------------------------------------------------------
