// b.cpp
// Print float number in width of 15 characters using precision 1, 2 and 3.
#include <iostream> // cout, endl
#include <iomanip>	// setprecision

int main()
{
	double value = 333.546372; // some value with no meanings
	
	// Print value in width of 15 characters
	std::cout << std::setprecision(9) << value << std::endl;

	std::cout << std::left << std::fixed // left allignment, with decimal display
			// Display float number with setprecision
			<< std::setprecision(1)	<< std::setw(15) << value  	
			<< std::setprecision(2)	<< std::setw(15) << value  	
			<< std::setprecision(3)	<< std::setw(15) << value	
			<< std::endl; 

	return 0;	
}
