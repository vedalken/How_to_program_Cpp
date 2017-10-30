#include <cctype>
#include <string>
#include <cmath>
#include "Complex.h"

Complex::Complex( double real, double imag )
    : m_real( real ),
      m_imag( imag )
{
}

Complex::Complex()
    : Complex(0, 0)
{
}

Complex::Complex( std::initializer_list<double> args )
{
    if ( args.size() > 2 )
        throw std::invalid_argument("Too many arguments");

    auto it = args.begin();
    m_real = *it;

    it = args.end();
    m_imag = *it;
}

const Complex& Complex::operator=( const Complex& a_complex )
{
    if ( this != &a_complex ) // prevent self assignment
    {
        m_real = a_complex.m_real;
        m_imag = a_complex.m_imag;
    }

    return *this;
}

const Complex& Complex::operator=( std::initializer_list<double> args )
{
    Complex tmp( args );
    *this = tmp;

    return *this;
}

std::ostream& operator<<( std::ostream& output, const Complex& a_complex )
{
    bool real(false);

    if ( std::fabs( a_complex.m_real ) > 1e-6 )
    {
        output << a_complex.m_real;
        real = true;
    }

    if ( std::fabs( a_complex.m_imag ) > 1e-6 )
    {
        if (real) output << std::showpos;
        output << a_complex.m_imag << "i";
    }

    return output;
}

std::istream& operator>>( std::istream& input, Complex& a_complex )
{
    std::string tmp, cmplx;

    input >> std::ws; // discard leading whitespaces
    std::getline( input, tmp );

    // remove any spaces
    for (auto c : tmp)
    {
        if ( std::isspace( c ) )
            continue;

        cmplx.push_back( c );
    }

    std::string number1, number2;
    char ch;

    // evaluate input content
    for ( size_t i = 0; i < cmplx.size(); ++i )
    {
        ch = cmplx.at( i );

        if ( std::isdigit( ch ) ) {
            number1.push_back( ch );
            continue;
        }

        switch ( ch )
        {
            case '+':
            case '-':
                static int counter(1);

                if ( counter > 2 )
                {
                    input.clear( std::ios_base::failbit );
                    break;
                }

                if ( i != 0 ) number1.swap( number2 ); // store number
                
                number1.push_back( ch );
                ++counter;
                break;
            case 'i': // imaginary number
            case '.': // floating point
                number1.push_back( ch );
                break;
            default:
                input.clear( std::ios_base::failbit );
        }
    }

    std::string* imag(nullptr), *real(nullptr);

    // extract imaginary and real part
    if ( ! number1.empty() )
    {
        if ( number1.back() == 'i' ) imag = &number1;
        else                         real = &number1;
    }

    if ( ! number2.empty() )
    {
        if ( number2.back() == 'i' ) imag = &number2;
        else                         real = &number2;
    }

    // handle unary part
    if ( imag )
    {
        // remove imaginary i
        imag->pop_back();

        if ( imag->size() <= 1 && (! std::isdigit( imag->front() )) )
            imag->push_back( '1' );
    }
    
    if ( real )
    {
        if ( real->size() <= 1 && (! std::isdigit( real->front() )) )
            real->push_back( '1' );
    }

    a_complex = { 0, 0 };
 
    // convert real and imaginary part
    if ( real ) a_complex.m_real = std::stod( *real );
    if ( imag ) a_complex.m_imag = std::stod( *imag );
    
    return input;
}
