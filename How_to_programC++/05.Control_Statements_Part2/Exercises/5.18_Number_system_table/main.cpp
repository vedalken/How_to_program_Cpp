// main.cpp
// Display table of binary, octal and hexadecimal equivalents 
// of the decimal numbers in range 1-256.
#include <iostream> // cout, cin, endl
#include <iomanip>	// setw
#include "functions.h" // use implementation of functions

int main()
{ 
	std::cout << "Enter decimal value (1-256): ";
	int decimal;
	std::cin >> decimal;

	std::cout << "Decimal: " << decimal << std::endl;
	std::cout << "Binary: ";
	decimal2binary( decimal );
	
	std::cout << "Octal: ";
	decimal2octal( decimal );
	
	std::cout << "Hexadecimal: ";
	decimal2hexadecimal( decimal );

	// Use build manipulators
	std::cout << std::dec << decimal << std::endl;
	std::cout << std::oct << decimal << std::endl;
	std::cout << std::hex << decimal << std::endl;

	return 0;	
}
