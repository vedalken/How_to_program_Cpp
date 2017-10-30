#include "Derived.h"

Derived::Derived( int value, char latter, double real )
	: Base1( value ),
	  Base2( latter ),
	  _real( real )
{
}

std::ostream& operator<<(std::ostream& output, const Derived& derived)
{
	output << "integer: "     << derived._value
	       << "\ncharacter: " << derived._latter
	       << "\nreal: "      << derived._real << std::endl;
	return output;
}
