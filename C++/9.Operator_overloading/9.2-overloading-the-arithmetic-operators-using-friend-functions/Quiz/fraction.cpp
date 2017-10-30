#include <iostream>

class Fraction
{
    friend Fraction operator*(const Fraction&, int);
    friend Fraction operator*(int, const Fraction&);
    public:
        Fraction(int, int);
        void print() const;
        Fraction operator*(const Fraction& );
    private:
        Fraction();
        int m_nom;
        int m_denom;
};

Fraction operator*( const Fraction& lhs, int rhs )
{
    return Fraction( lhs.m_nom * rhs, lhs.m_denom );
}

Fraction operator*( int lhs, const Fraction& rhs )
{
    // call overloaded operator*(const Fraction&, int)
    return (rhs * lhs);
}

Fraction::Fraction()
    : m_nom(0),
      m_denom(0)
{
}

Fraction::Fraction(int a_nom, int a_denom)
    : m_nom(a_nom),
      m_denom(a_denom)
{
}

void Fraction::print() const
{
    std::cout << m_nom << "/" << m_denom << '\n';
}

Fraction Fraction::operator*( const Fraction& rhs )
{
    return Fraction( m_nom * rhs.m_nom, m_denom * rhs.m_denom );
}

int main()
{
    Fraction f1(1, 4);
    Fraction f2(1, 2);

    f1.print();
    f2.print();
    
    Fraction f3 = f1 * f2;
    Fraction f4 = f1 * 2;
    Fraction f5 = 2  * f2;

    f3.print();
    f4.print();
    f5.print();

    return 0;
}
