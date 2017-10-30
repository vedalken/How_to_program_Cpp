#ifndef CALC_H
#define CALC_H
class Calc
{
private:
	int m_value;
public:
	Calc() { m_value = 0; }

	Calc& Add(int value) { m_value += value; return *this; }
	Calc& Sub(int value) { m_value -= value; return *this; }
	Calc& Mult(int value) { m_value *= value; return *this; }

	int GetValue() { return m_value; }
};

#endif
