#include <iostream>

using namespace std;
int main()
{
	short* ptr = new short;
	*ptr = 7;
	
	cout << "*ptr = " << *ptr << "\tptr = " << ptr
		<< "\t\t&ptr = " << &ptr << endl;
	
	cout << "sizeof:\n"
		<< sizeof( *ptr ) << '\t' << sizeof( ptr ) << endl;


	delete ptr;
	ptr = 0;
	
	int size = 12;
	int * pnArray = new int [ size ];
	pnArray[ 4 ] = 4;
	delete[] pnArray;
	pnArray = 0;

	return 0;
}
