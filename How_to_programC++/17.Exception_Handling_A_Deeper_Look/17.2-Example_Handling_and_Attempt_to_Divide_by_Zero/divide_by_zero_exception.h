#ifndef DIVIDE_BY_ZERO_EXCEPTION_H
#define DIVIDE_BY_ZERO_EXCEPTION_H

#include <stdexcept>

class DivideByZeroException : public std::runtime_error
{
public:
	DivideByZeroException()
	  : std::runtime_error("attempt to divide by zero")
	{
	}
};

#endif
