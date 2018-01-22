#ifndef EQRGENERIC_H
#define EQRGENERIC_H

#include <exception>

using namespace std;
class EQRGeneric : public exception
{
    public:
        EQRGeneric(char* message);
        virtual const char* what() const throw();
    protected:
    private:
        char* ExceptionMessage;
};

#endif // EQRGENERIC_H
