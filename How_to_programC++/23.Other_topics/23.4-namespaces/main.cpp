#include <iostream>

int integer1 = 98;

namespace Example 
{
const double PI = 3.14159;
const double E = 2.71828;
int integer1 = 8;

// function prototype
void printValues();

namespace Inner
{
	enum Years { FISCAL1 = 1990, FISCAL2, FISCAL3 };
}// end namespace Inner
}// end namespace Example

// create unnamed namespace
namespace
{
      double doubleUnnamed = 88.22;
}


int main()
{
	std::cout << "\ndoubleUnnamed = " << doubleUnnamed;

	// output global variable
	std::cout << "\n(global) interger1 = " << integer1;

	// output values for Example namespace
	std::cout << "\nPI = " << Example::PI
		  << "\nE = " << Example::E
		  << "\ninteger1 = " << Example::integer1
		  << "\nFISCAL3 = " << Example::Inner::FISCAL3
		  << std::endl;

	Example::printValues();

	return 0;
}


void Example::printValues()
{
	std::cout << "\nIn printValues:"
		  << "\ninteger1 = " << integer1 
		  << "\nPI = " << PI
		  << "\nE = " << E
		  << "\ndoubleUnnamed = " << doubleUnnamed
		  << "\n(global) integer1 = " << ::integer1
		  << "\nFISCAL3 = " << Inner::FISCAL3
		  << std::endl;
}// end printValues
