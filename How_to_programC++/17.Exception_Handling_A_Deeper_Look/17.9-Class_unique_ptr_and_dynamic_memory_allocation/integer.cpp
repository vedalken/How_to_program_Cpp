#include <iostream>
#include "integer.h"

Integer::Integer(int a_value)
	: m_value(a_value)
{
	std::cout << "Constructor for Integer " << get() << std::endl;
}

Integer::~Integer()
{
	std::cout << "Destructor for Integer " << get() << std::endl;
}

void Integer::set(int a_value)
{
	m_value = a_value;
}

int Integer::get() const
{
	return m_value;
}
