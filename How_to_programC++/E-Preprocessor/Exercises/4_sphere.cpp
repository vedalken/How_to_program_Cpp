// sphere.cpp
// Compute the volume for spheres of radii 1 to 10 and print results in tabular
// format. Write macro with one arguments.
#include <iostream>
#include <iomanip>
using std::cout; // iostream header
using std::endl;
using std::setw; // iomanip header

#define PI 3.14159 // define PI
#define V_SPHERE(r) ((4*PI/3) * (r) * (r) * (r)) // sphere volume

double inline sphereVolume( double r ) { 
	const double pi = 3.1415926;
	return 4*pi/3 * (r) * (r) * (r); 
}

int main() 
{
	cout << "\n"; // newline
	cout << setw(6) << "r []"	<< setw(13) << "V []"		<< endl;
	cout << setw(6) << "------" << setw(13) << "----------" << endl;
	
	// calculate sphere volume
	for (int i = 1; i <= 10; ++i) 
	{
		double volume = sphereVolume( i );
		//cout << setw(6) << i << setw(13) << V_SPHERE( i ) << endl;
		cout << setw(6) << i << setw(13) << volume << endl;
	}
	
	return 0;
}
