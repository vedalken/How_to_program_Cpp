#include <iostream>
#include "Phone.h"
#include "PermutMatrix.h"

int main()
{
	PermutMatrix mat(1,3);
	PermutMatrix mat1 = mat;
	Phone phone;
	std::cout << "Enter a phone number: ";
	std::cin >> phone;
	
	std::cout << phone << std::endl;
	phone.wordGenerator();

	return 0;
}
