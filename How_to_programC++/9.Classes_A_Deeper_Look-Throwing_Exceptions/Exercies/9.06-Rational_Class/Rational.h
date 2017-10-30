#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
    int m_numerator;
    int m_denominator;
    
    void ReducedForm();
public:
    Rational();
    Rational(int, int);
    ~Rational();
    
    Rational& Add(const Rational &,       const bool reduce = {true});
    Rational& Substract(const Rational &, const bool reduce = {true});
    Rational& Multiply(const Rational &,  const bool reduce = {true});
    Rational& Divide(const Rational &,    const bool reduce = {true});
    
    void PrintRationalFormat() const;
    void PrintFloatFormat()    const;
};

#endif
