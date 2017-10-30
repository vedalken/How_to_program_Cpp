#include <iostream>

using namespace std;

int main () {
	int number1, number2 ;

	cout << "Insert two numbers: " ;
	
	number1 = cin.get() ;
	cin.ignore(100,' ') ;
	
	number2 = cin.get() ;
	cout << "Your initials are: " << number1 << endl;
	cout << "and " << number2 << endl;
	
	return 0 ;
}
