#ifndef MONOMIAL_H
#define MONOMIAL_H

#include <string>
#include <LogAntilog.h>
using namespace std;

class Monomial
{
    public:
        Monomial();
        Monomial(int exp_a, int exp_x);
        //Monomial& operator+(const Monomial& rhs);

        static void Combine(Monomial &ouput, Monomial &inputA, Monomial &inputB);

        int getLog(int idx);
        int getAntiLog(int idx);

        int ExpA;
        int ExpX;

        string toString();
    protected:

    private:
        string NumberToString (int number);
};

#endif // MONOMIAL_H
