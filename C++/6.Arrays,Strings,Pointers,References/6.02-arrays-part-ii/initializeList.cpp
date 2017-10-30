// initializeList.cpp
// Initialize array via initialization list and 
// display its elements.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	// compiler determines array size
	int anArray[] = { 0, 1, 2, 3, 4 };
	
	cout << "Size: " 		<< sizeof(anArray) 
		 << endl;
	cout << "N elements:" 	<< sizeof(anArray) / sizeof(anArray[0]) 
		 << endl;
	cout << anArray[0] << endl;
	cout << anArray[1] << endl;
	cout << anArray[2] << endl;
	cout << anArray[3] << endl;
	cout << anArray[4] << endl;

	return 0;	
}
