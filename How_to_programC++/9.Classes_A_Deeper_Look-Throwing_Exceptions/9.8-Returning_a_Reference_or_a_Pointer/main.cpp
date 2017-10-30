#include <iostream>
#include <stdexcept>
#include "Time.h"

int main()
{
	Time t;

	unsigned int& hourRef = {t.badSetHour(20)};

	std::cout << "Valid hour before modification: " << hourRef;
	hourRef = {30};
	std::cout << "\nInvalid hour after modification: " << t.getHour() << std::endl;

	t.badSetHour(12) = {74};

	std::cout << "\n\n*********************************************\n"
		<< "POOR PROGRAMMING PRACTICE!!\n"
		<< "t.badSetHour(12) as a lvalue, invalid hour: "
		<< t.getHour()
		<< "\n*********************************************\n";

	return 0;
}
