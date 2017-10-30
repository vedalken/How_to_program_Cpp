// pi.cpp
// Calculating pi from infinite series
// pi = 4 - 4/3 + 4/5 - 4/7 + 4/9 - 4/11 + ...
#include <iostream>
#include <iomanip>
// iostream header
using std::cout;
using std::endl;
using std::fixed;
// iomanip header
using std::setprecision;

int main()
{
	double value;	// element in sum
	double sum = 0; // sum elements

	// Sum 1000 element in infinite series
	for (int i=1, j=1; i < 100; i += 2, ++j)
	{
		if (j%2 == 0)
			value = -4.0 / i;
		else
			value = 4.0 / i;
			
		sum += value;
	}

	// Display pi numerical value
	cout << "Pi = "
		<< fixed << setprecision(3) << sum << endl;

	return 0;	
}
