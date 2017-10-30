#include <iostream>

class Cents 
{
public:
    Cents() 
        : m_cents(0) 
    {
    }
    
    Cents(int cents) 
        : m_cents(cents) 
    {
    }

    int GetValue() { return m_cents; }

    friend Cents Add(Cents &, Cents &);
private:
    int m_cents;
};

Cents Add(Cents &c1, Cents &c2)
{
    return Cents(c1.GetValue() + c2.GetValue());
}

int main()
{
    Cents Cents1(5);
    Cents Cents2(15);

    std::cout << "I have " << Add(Cents1, Cents2).GetValue() << " cents\n";

    return 0;
}
