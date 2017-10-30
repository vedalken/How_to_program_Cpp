#ifndef CLIENT_DATA_H
#define CLIENT_DATA_H
#include <string>

class ClientData
{
public:
	ClientData(int = 0, const std::string & = "", 
		const std::string & = "", double = 0.0);

	// accessor functions for accountNumber
	void setAccountNumber( int );
	int getAccountNumber() const;

	// accessor functions for lastName
	void setLastName( const std::string & );
	const std::string getLastName() const;

	// accessor functions for firstName
	void setFirstName( const std::string & );
	const std::string getFirstName() const;

	// accessor functions for balance
	void setBalance( double );
	double getBalance() const;
private:
	int m_accountNumber;
	char m_lastName[15];
	char m_firstName[10];
	double m_balance;
};

#endif
