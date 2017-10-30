#ifndef COMPLEX_H
#define COMPLEX_H

class Complex 
{
private:
    double m_real;
    double m_imag;
public:
    Complex();
    Complex(const double, const double);
    ~Complex();

    Complex& Add(const Complex &);
    Complex& Add(const double real, const double imag);
    Complex& Substract(const Complex &);
    Complex& Substract(const double real, const double imag);
    void Print() const;
};

#endif
