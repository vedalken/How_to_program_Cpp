// sqrt.cpp
#include <iostream>	// cout, endl
#include <cmath>	// sqrt
#include <iomanip>	// fixed, setprecision
using std::cout; // iostream header
using std::endl;
using std::sqrt; // cmath header
using std::fixed;// iomanip header
using std::setprecision;


int main()
{
	double a = 13.0;
	double b = 4.0;
	long double c = 1.0;

	cout << fixed << setprecision(20) << sqrt( a + b*c ) << endl;

	return 0;
}
