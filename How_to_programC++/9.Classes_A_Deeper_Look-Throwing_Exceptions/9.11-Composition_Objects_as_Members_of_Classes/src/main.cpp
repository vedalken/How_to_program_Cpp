#include <iostream>
#include "Date.h"
#include "Employee.h"

int main()
{
	Date birth(1987, 12, 15);
	Date hire(2015, 6, 15);
	Employee manager("Tinko", "Polovinko", birth, hire);
	
	std::cout << '\n';
	manager.print();

	return 0;
}	
