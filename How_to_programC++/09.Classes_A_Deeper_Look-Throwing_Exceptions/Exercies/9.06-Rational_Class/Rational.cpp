#include <iostream>
#include <stdexcept>
#include "Rational.h"

Rational::Rational()
    : m_numerator(0),
      m_denominator(1)
{
}

Rational::Rational(int nom, int denom)
    : m_numerator(nom),
      m_denominator(denom)
{
    // Find the reduced form
    ReducedForm(); 
}

Rational::~Rational()
{
}

// Reduced rational form
void Rational::ReducedForm()
{
    int min = m_numerator;

    if (min < m_denominator) {
        min = m_denominator;
    }

    // factor reduces the rational in reduced form
    int reducer = 1;

    // find maximal reducer
    for (int module = 2; module <= min; ++module) {
        if (m_numerator % module == 0) {
            if (m_denominator % module == 0) {
                reducer = module;           
            }
        }
    }
    
    // The rational reduced form
    if (reducer > 1) {
        m_numerator   /= reducer;
        m_denominator /= reducer;
    }
}

Rational& Rational::Add(const Rational &r, const bool reduce)
{
    m_numerator = m_numerator   * r.m_denominator +
                  m_denominator * r.m_numerator; 
    
    if (r.m_denominator != 0) {
        m_denominator *= r.m_denominator;
    }
    else {
        throw std::domain_error("Rational::Add: denominator equals 0");
    }

    if (reduce) {
        ReducedForm();
    }

    return *this;
}

Rational& Rational::Substract(const Rational &r, const bool reduce)
{
    m_numerator = m_numerator   * r.m_denominator -
                  m_denominator * r.m_numerator; 
    
    if (r.m_denominator != 0) {
        m_denominator *= r.m_denominator;
    }
    else {
        throw std::domain_error("Rational::Substract: denominator equals 0");
    }

    if (reduce) {
        ReducedForm();
    }

    return *this;
}

// (a/b) * (c/d) = (a*c) / (b*d)
Rational& Rational::Multiply(const Rational &r, const bool reduce)
{
    m_numerator   *= r.m_numerator;
    m_denominator *= r.m_denominator;

    if (reduce) {
        ReducedForm();
    }

    return *this;
}

// (a/b) / (c/d) = (a/c) * (d/b) = (a*d) / (b*c)
Rational& Rational::Divide(const Rational &r, const bool reduce)
{
    m_numerator   *= r.m_denominator;
    
    if (r.m_numerator != 0) {
        m_denominator *= r.m_numerator;
    }
    else {
        throw std::domain_error("Denominator equals 0!");
    }

    if (reduce) {
        ReducedForm();
    }

    return *this;
}

void Rational::PrintRationalFormat() const
{
    std::cout << m_numerator << "/" << m_denominator << std::endl; 
}

void Rational::PrintFloatFormat() const 
{
    std::cout << static_cast<double>(m_numerator)/m_denominator << std::endl;
}
