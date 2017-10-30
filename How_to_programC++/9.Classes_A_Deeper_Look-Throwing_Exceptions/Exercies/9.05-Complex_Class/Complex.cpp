#include "Complex.h"
#include <iostream>

// Default constructor: delegating constructor
Complex::Complex()
    : Complex(1,0)
{
}
 
Complex::Complex(const double real, const double imag)
    : m_real(real),
      m_imag(imag)
{
}

Complex::~Complex()
{
}

Complex& Complex::Add(const Complex& c)
{
    m_real += c.m_real;
    m_imag += c.m_imag;
    return *this;
}

Complex& Complex::Add(const double real, const double imag)
{
    m_real += real;
    m_imag += imag;
    return *this;
}

Complex& Complex::Substract(const Complex& c)
{
    m_real -= c.m_real;
    m_imag -= c.m_imag;
    return *this;
}

Complex& Complex::Substract(const double real, const double imag)
{
    m_real -= real;
    m_imag -= imag;
    return *this;
}

// Print values as (r, im) = r + i*im, defined i = sqrt(-1)
void Complex::Print() const
{
    std::cout << "(" << m_real << ", " << m_imag << ")";   
}
