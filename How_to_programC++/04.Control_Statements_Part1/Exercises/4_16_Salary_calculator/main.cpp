// main.cpp
// Salary calculator, calculating employee's gross pay.
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;

int main()
{
	int		hoursPerWeek; 	// employee's worked hours per week
	float	hourlyRate;		// hourly rate of employee

	// Prompt user message 
	cout << "Enter hours worked (-1 to quit): ";
	cin >> hoursPerWeek;

	while (hoursPerWeek != -1)
	{
		cout << "Enter hourly rate of the employee (€00.0): ";
		cin >> hourlyRate;
		
		cout << "Salary is €" << fixed << setprecision(1) 
			<< hourlyRate * hoursPerWeek << endl;	
	
		// Prompt user message 
		cout << "Enter hours worked (-1 to quit): ";
		cin >> hoursPerWeek;
	}

	return 0;
}
