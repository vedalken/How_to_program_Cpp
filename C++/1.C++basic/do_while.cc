#include <iostream>
using namespace std;

int main()
{
	unsigned long n;
	cout << "Number \"0\" terminate a program.\n";

	do{
		cout << "Enter any positive number: ";
		cin >> n;
		cout << "You entered: " << n << "\n";
	
	} while( n != 0 );

	return 0;
}
