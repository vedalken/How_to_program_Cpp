#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main () {

	string mystr;
	int quantity (0);
	float price (0);
	
	// Numerical input
	cout << "Your price: ";
	// Store input to string mystr
	getline (cin, mystr);
	// Replace string with integer
	stringstream(mystr) >> price;
	cout << "Quantity: ";
	getline (cin, mystr);
	stringstream(mystr) >> quantity;
	
	cout << "Total price " << quantity*price << ".\n"; 
	cin.get();

	return 0;
}
