#include <iostream>
#include "Count.h"

void Count::print() const
{
	std::cout << m_x << std::endl;
}

void setX(Count &count, int value)
{
	count.m_x = value;
}
