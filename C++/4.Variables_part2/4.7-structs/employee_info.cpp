#include <iostream>
#include <iomanip>
#include "Employee.h" // Employee structure (object)
#include "Company.h" // Company structure (object)

void displayInfo( Employee ); // function prototype
int main()
{
	// Two employees, with listed
	// ID, age, and wage
	typedef struct Employee employee;
	employee sMilos = { .ID = 13894, .age = 25, .wage = 1894.6 };
	employee sUros = { 81728, 26, 1834.3 };

	// display info on employee
	displayInfo( sMilos );
	displayInfo( sUros );
	
	// IJS company information
	Company sIJS;
	sIJS.sCEO.ID = 1;
	sIJS.sCEO.age = 57;
	sIJS.sCEO.wage = 8590.5;
	sIJS.numberOfEmployees = 562; // number of employees in company
	
	// display CEO info
	displayInfo( sIJS.sCEO );

	return 0;		
}// end main

// display information about employee:
// ID, age, wage, etc.
void displayInfo( Employee sEmployee )
{
	using std::cout; // iostream header
	using std::endl;
	using std::setw; // iomanip header

	cout << "Employee" << endl;
	cout << setw(10) << "ID:" << setw(8) << sEmployee.ID << endl;
	cout << setw(10) << "age:" << setw(8) << sEmployee.age << endl;
	cout << setw(10) << "wage:" << setw(8) << sEmployee.wage << endl;
	cout << endl;
}
