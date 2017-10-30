// Account.cpp
// Account class implementation. Class definition is in Account.h.
#include <iostream>		// used for cout, endl
#include "Account.h"
using std::cout;
using std::endl;

// class Account constructor - initialize account balance 
Account::Account( int moneyOnAccount )
{
	setBalance( moneyOnAccount ); // initialize account balance
}

// function that adds amount on account
void Account::credit( int addAmount ) 
{
	accountBalance = accountBalance + addAmount;
}

// function withdraw money from account 
void Account::debit( int withdrawAmount )
{
	if (withdrawAmount > accountBalance)
	{
		// unchange account balance; display message
		cout << "Debit account exceeded account balance." << endl;	
	}

	// ensure that debit amount does not exceed Account's balance
	if (withdrawAmount <= accountBalance)
		accountBalance = accountBalance - withdrawAmount;
}

// function sets account balance
void Account::setBalance( int moneyOnAccount ) 
{
	// check if money on account has meaningful value
	if (moneyOnAccount >= 0)
		accountBalance = moneyOnAccount;
	
	if (moneyOnAccount < 0) 
	{
		// sets account balance to zero
		accountBalance = 0;
		
		cout << "Error: initial balance value is invalid! "
			<< "Set to 0." << endl;
	}
}

// function gets account balance
int Account::getBalance() 
{	
	return accountBalance;
}
