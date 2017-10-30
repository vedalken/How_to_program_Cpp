// main.cpp
// Create and manipulate Account object, using validation.
#include <iostream>
#include "Account.h"
using std::cout;
using std::endl;

// program execution begins with main
int main()
{
	// object initialization; constructor call
	Account account1(2000);
	Account account2(-5);

	// display account balance
	cout << account1.getBalance() << ", " << account2.getBalance() << endl;

	// add money on account
	account1.credit(800);
	account2.credit(100);
	
	// display current account balance
	cout << account1.getBalance() << ", " << account2.getBalance() << endl;

	// witdraw money
	account1.debit(1500);
	account2.debit(300);

	// display current account balance
	cout << account1.getBalance() << ", " << account2.getBalance() << endl;

	return 0;

} // end main
