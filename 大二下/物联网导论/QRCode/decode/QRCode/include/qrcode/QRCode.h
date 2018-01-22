#ifndef QRCODE_H
#define QRCODE_H

#include "Bitmap.h"
#include <string>
#include "PolynomialGenerator.h"
#include "StructPoint.h"
#include "StructECInfo.h"
#include "enumCorrectionLevel.h"
#include "enumMode.h"

using namespace std;

class QRCode
{
    protected:
        string Data;
        eMode Mode;

        int Modules;
        int Version;
        eCorrectionLevel ErrorCorrectonLevel;

        bool VersionInfoRequired;

        //This vector contain the center point of the
        //alignment patterns. The point 0,0 is top left of the matrix.
        vector<Point> AlignementPatterns;

        ECInfo getECInfo(void);

        void SelectMode(void);
        bool CheckDataCapabilities(void);

        string getCountIndicator(void);
        string DecimalToBinary(int value);

        int BinaryToDecimal(string value);
        int getReminderBitsCount(void);

        int CAP_L_CORRECTION_NUMERIC;
        int CAP_L_CORRECTION_ALPHANUMERIC;
        int CAP_L_CORRECTION_BYTE;
        int CAP_L_CORRECTION_KANJI;

        int CAP_M_CORRECTION_NUMERIC;
        int CAP_M_CORRECTION_ALPHANUMERIC;
        int CAP_M_CORRECTION_BYTE;
        int CAP_M_CORRECTION_KANJI;

        int CAP_Q_CORRECTION_NUMERIC;
        int CAP_Q_CORRECTION_ALPHANUMERIC;
        int CAP_Q_CORRECTION_BYTE;
        int CAP_Q_CORRECTION_KANJI;

        int CAP_H_CORRECTION_NUMERIC;
        int CAP_H_CORRECTION_ALPHANUMERIC;
        int CAP_H_CORRECTION_BYTE;
        int CAP_H_CORRECTION_KANJI;

        int REMINDER_BIT_COUNT;

        ECInfo ECL_LOW_EC_INFO;
        ECInfo ECL_MEDIUM_EC_INFO;
        ECInfo ECL_QUALITY_EC_INFO;
        ECInfo ECL_HIGH_EC_INFO;

        virtual void InitCapabilities(void)=0;
        virtual void InitECInfo(void)=0;
        virtual void InitAlignementPatterns(void)=0;

    private:
        string NumberToString (int number);
        string getModeIndicator(void);
        string getEncodedData(void);
        string EncodeNumericMode(void);
        string EncodeAlphanumericMode(void);
        string EncodeByteMode(void);
        string EncodeKanjiMode(void);
        string BinaryPadLeft(string binary, int length, char* pad_char="0");
        string BinaryPadRight(string binary, int length, char* pad_char="0");
        string getInterlivedCodewords(vector<string> data_blocks, vector<string> error_correction);
        string Binary_XOR(string A, string B);

        int getAlphanumericValue(char character);

        string EncodeData(void);

        vector<string> CreateEC(const vector<string> data_blocks, int cw_per_blocks);

        vector<int> CreateECPerBlock(int cw_per_block, string data_block);
        vector<int> SplitEncodedData(const string encoded_data, int &data_size);

        vector<Monomial> getMessagePolynomial(int cw_per_blocks, const string encoded_data);
        vector<Monomial> getEC_Moltiplication(vector<Monomial> previous, vector<Monomial> gen_polynomial);
        vector<Monomial> getEC_XORing(vector<Monomial> previous, vector<Monomial> first_step);

    public:
        QRCode();

        string CreateQRData(void);
        string CreateFormatInformation(string mask_id);
        string CreateVersionInformation(void);

        void setData(string data);
        string getData(void);
        string getBinary_ECL(void);
        void setErrorCorrectionLevel(eCorrectionLevel error_correction_level);
        eCorrectionLevel getCorrectionLevel(void);

        int getVersion(void);

        int getModuleWidth(void);

        int getModules(void);

        bool IsVersionInfoRequired(void);
        bool CanContainData(void);
        vector<Point> getAlignementPatterns(void);
        virtual ~QRCode();
};

#endif // QRCODE_H
