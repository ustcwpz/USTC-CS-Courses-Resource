#ifndef POLYNOMIALGENERATOR_H
#define POLYNOMIALGENERATOR_H

#include "Monomial.h"
#include "vector"

class PolynomialGenerator
{
    public:
        PolynomialGenerator();
        ~PolynomialGenerator();

        vector<Monomial> getPolynomial(int ec_codewords);
        string ConvertToString(const vector<Monomial> monomial_list);

        protected:
    private:

        int ExistsExpX(const vector<Monomial> monomial_list, int exp_x);
};

#endif // POLYNOMIALGENERATOR_H
