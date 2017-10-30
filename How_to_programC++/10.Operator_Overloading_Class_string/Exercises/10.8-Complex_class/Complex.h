#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>

class Complex
{
    friend std::ostream& operator<<( std::ostream& , const Complex& );
    friend std::istream& operator>>( std::istream& , Complex& );

    public:
        // constructor declared as explicit which prevent compiler implicit conversion
        explicit Complex( double = 0.0, double = 0.0 );
        // copy constructor
        Complex( const Complex& );
        
        Complex&    operator=( const Complex& );
        Complex     operator+( const Complex ) const;
        Complex&    operator+=( const Complex );
        Complex     operator-( const Complex ) const;
        Complex     operator*( const Complex ) const;
        bool        operator==( const Complex ) const;
        inline bool operator!=( const Complex right) const { return ! (*this == right); }

    private:
        double _re;
        double _imag;
};

#endif
