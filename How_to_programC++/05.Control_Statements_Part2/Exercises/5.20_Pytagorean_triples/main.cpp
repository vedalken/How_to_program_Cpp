// main.cpp
// Right triangle can have all sides that are integers. Set of three
// integer values for the sides of a right triangle is called Pythagorean 
// triple. Calculate brute force all possibilities of sides. Sides should
// not be longer than 500!
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	const int maxSideLength = 1000; // maximum lenght of each side
	unsigned count = 0;
	int c2; // c*c
	int a2; // a*a

	for (int c = 1; c <= maxSideLength; ++c) 
	{
		c2 = c*c;
		for (int a = 1; a <= maxSideLength; ++a) 
		{
			a2 = a*a;
			for (int b = a; b <= maxSideLength; ++b) 
			{
				if (c2 == a2 + b*b) { 
					++count;
					continue; // Look for other possibilities
				}
			}
		}
	}

	cout << "All possibilities: " << 2*count << endl;

	return 0;
}
