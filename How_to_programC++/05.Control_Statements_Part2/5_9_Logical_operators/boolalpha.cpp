// modify boolalpha flag
#include <iostream>
using std::cout;
using std::endl;
using std::boolalpha;
using std::noboolalpha;

int main()
{
	bool value = true; 
	
	// Set boolalpha flag
	// display boolean value in alphabetic format
	cout << boolalpha << value << "\n" << !value << endl;	

	// Unset boolalpha flag
	// display boolean value in numeric format
	cout << noboolalpha << value << "\n" << !value << endl;

	return 0;
}
