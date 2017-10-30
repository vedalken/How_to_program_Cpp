#include <iostream>

class Accumulator
{
private:
    int m_value;
public:
    Accumulator();
    void add(int);

    friend void reset(Accumulator &);
};

Accumulator::Accumulator()
    : m_value(0)
{
}

void Accumulator::add(int pvalue)
{
    m_value += pvalue;
}

void reset(Accumulator &accumulator)
{
    accumulator.m_value = 0;
}

int main()
{
    Accumulator acc;
    acc.add(5);

    reset(acc);

    return 0;
}
