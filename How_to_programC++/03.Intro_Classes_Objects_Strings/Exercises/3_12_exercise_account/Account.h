// Account.h
// Account class definition. Bank uses accounts managment for administration
// purposes.

class Account
{
	public:
		// constructor to initialize account balance
		Account(int moneyOnAccount);

		// add amount to current account balance
		void credit(int addAmount);
		
		// withdraw money from account
		void debit(int withdrawAmount);
		
		// set current account balance
		void setBalance(int currentBalance);
		
		// current account balance
		int getBalance();
	private:
		// account balance
		int accountBalance; 
};
