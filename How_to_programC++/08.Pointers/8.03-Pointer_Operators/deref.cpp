// deref.cpp
// Testing dereference operator.
//
// compile:
//   g++ -std=c++11 -Wall deref.cpp -o deref
//
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;

int main()
{
	int y = 5;
	int *yPtr = nullptr; // C++ 11
	yPtr = &y;

	cout << setw(6) << "y:"     << y     << endl;
	cout << setw(6) << "&y:"    << &y    << endl;
	cout << setw(6) << "yPtr:"  << yPtr  << endl;
	cout << setw(6) << "*yPtr:" << *yPtr << endl;
	
	// reasign new value
	*yPtr = 9;
	cout << "Reasign..." << endl;
	cout << setw(6) << "y:" << y << endl;
	cout << setw(6) << "&y:" << &y << endl;
	cout << setw(6) << "yPtr:" << yPtr << endl;
	cout << setw(6) << "*yPtr:" << *yPtr << endl;
	
	return 0;
}
