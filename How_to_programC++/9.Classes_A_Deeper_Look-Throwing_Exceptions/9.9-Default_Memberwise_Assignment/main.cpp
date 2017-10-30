#include <iostream>
#include "Date.h"

int main()
{
	Date date1(7,4,2011);
	Date date2; // default date: 1/1/2000

	std::cout << "date1: ";
	date1.print();
	std::cout << "\ndate2: ";
	date2.print();

	// default copy constructor
	date2 = date1;

	std::cout << "\n\nAfter default memberwise assignment, date2 = ";
	date2.print();
	std::cout << '\n';
	
	const Date date3;
	date3.print();
	std::cout << '\n';
	return 0;
}
