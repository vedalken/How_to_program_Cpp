#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <initializer_list>

class Complex
{
    friend std::ostream& operator<<( std::ostream& , const Complex & );
    friend std::istream& operator>>( std::istream& , Complex& );
    public:
        Complex();
        Complex( double, double );
        Complex( std::initializer_list<double> args );
        const Complex& operator=( const Complex & );
        const Complex& operator=( std::initializer_list<double> );
    private:
        double m_real;
        double m_imag;
};

#endif
