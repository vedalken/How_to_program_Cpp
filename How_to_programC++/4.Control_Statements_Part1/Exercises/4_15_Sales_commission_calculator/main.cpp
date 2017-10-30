// main.cpp
// Program calculates salesperson's week earning based on
// gross sales.
// Salespersons gets 200 € per week and 9% of their gross sales.
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;

// Program execution
int main()
{
	int	sales; // salesperson's sales per week 
	
	// Prompt message to user
	cout << "Enter sales in euros (-1 to quit): ";
	cin >> sales; // save sales per week
	
	int		weekEarning			= 200;	// week earning, regardless of gross sales
	float 	procentOfGrossSales = 0.09; // procentage of gross sales, goes to salesperson's earning
	float	salesEarning;				// earning per week

	while (sales != -1) 
	{
		// Compute saley of salesperson
		salesEarning = weekEarning + procentOfGrossSales * sales;
		
		// Display salesperson salery
		cout << "Salery is: €" << fixed << setprecision(2) << salesEarning << endl;
		
		// Prompt message to user
		cout << "Enter sales in euros (-1 to quit): ";
		cin >> sales;
	}

	return 0;	
}
