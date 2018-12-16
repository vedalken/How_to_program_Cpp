#include <iostream>
#include "Complex.h"

Complex::Complex( double real, double imag )
    : _re{ real },
      _imag{ imag }
{
}

Complex::Complex( const Complex& c )
    : _re{ c._re },
      _imag{ c._imag }
{
}

// overloaded assignment operator
Complex& Complex::operator=( const Complex& right )
{
    if ( this != &right )
    {
        _re = right._re;
        _imag = right._imag;
    }

    return *this;
}

// overloade addition operator
Complex Complex::operator+( const Complex operand2 ) const
{
    return Complex( _re + operand2._re, _imag + operand2._imag );
}

Complex& Complex::operator+=( const Complex operand2 )
{
    // call overloaded + and = operator
    return *this = *this + operand2;
}

Complex Complex::operator-( const Complex operand2 ) const
{
    return Complex( _re - operand2._re, _imag - operand2._imag );
}

Complex Complex::operator*( const Complex operand2 ) const
{
    return Complex( _re * operand2._re   - _imag * operand2._imag, 
                    _re * operand2._imag + _imag * operand2._re );
}

bool Complex::operator==( const Complex right ) const
{
    if ( _re == right._re && _imag == right._imag )
        return true;

    return false;
}

std::ostream& operator<<( std::ostream& output, const Complex& c )
{
    output << "(" << c._re << ","<< c._imag << ")";

    return output;
}

std::istream& operator>>( std::istream& input, Complex& c )
{
    input >> c._re >> c._imag;
    return input;
}
