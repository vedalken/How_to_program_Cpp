// main.cpp
// Analysis student survey about student cafeteria food quality 
// from 1 to 5.
#include <iostream>
#include <iomanip>
using std::cout; // iostream
using std::endl;
using std::setw; // iomanip

int main() 
{
	const int responseSize = 20; // number of students surveyed
	
	// survey responses
	const int responses[ responseSize ] = {1,2,5,4,3,5,2,1,3,1,4,
		3,3,3,2,3,3,2,2,5};

	// survey number range from 1 to 5; ignore element zero
	const int frequencySize = 6;
	int frequency[ frequencySize ] = {}; // initialize elements to zero

	// count survey responses
	// add one to array's element for each correct response (from 1 to 5)
	for (int i = 0; i < responseSize; ++i)
		++frequency[ responses[i] ];
	
	cout << "Rating" << setw(15) << "Frequency" << endl;

	// display analysis information
	for (int i = 1; i < frequencySize; ++i)
		cout << setw(6) << i << setw(15) << frequency[i] << endl;

	return 0;	
}
