// array.cpp
#include <iostream>
using namespace std;
int main()
{
	int anArray[5] = { 9, 8, 7, 6, 5 };
	
	// pointer to array name points to address 
	// of first element in array: anArray[0]
	cout << "*anArray: " << *anArray 
		<< "\nanArray[0]: " << anArray[0]
		<< "\n*(anArray+1): " << *(anArray + 1)
		<< "\nanArray[1]: " << anArray[1] << endl;
	
	// c-style string
	char name[] = "Milos";
	cout << "*name: " << *name << endl;
	cout << "name[0]: " << name[0] << endl;

	return 0;	
}
