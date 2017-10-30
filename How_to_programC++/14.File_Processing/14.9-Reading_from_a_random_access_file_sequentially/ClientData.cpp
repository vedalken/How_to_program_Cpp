#include "ClientData.h"

ClientData::ClientData(
	int a_accountNumber,
	const std::string &a_lastName,
	const std::string &a_firstName,
	double a_balance )
	: m_accountNumber( a_accountNumber ),
	  m_balance( a_balance )
{
	setLastName( a_lastName );
	setFirstName( a_firstName );
}

void ClientData::setAccountNumber( int a_number )
{
	m_accountNumber = a_number;
}

int ClientData::getAccountNumber() const
{
	return m_accountNumber;
}

void ClientData::setLastName( const std::string& a_lastName )
{
	size_t length = a_lastName.size();
	length = (length < 15) ? length : 14;
	a_lastName.copy( m_lastName, length );
	m_lastName[ length ] = '\0';
}

const std::string ClientData::getLastName() const
{
	return m_lastName;
}

void ClientData::setFirstName( const std::string& a_firstName )
{
	size_t length = a_firstName.size();
	length = (length < 10) ? length : 9;
	a_firstName.copy( m_firstName, length );
	m_firstName[ length ] = '\0';
}

const std::string ClientData::getFirstName() const
{
	return m_firstName;
}

void ClientData::setBalance( double a_balance )
{
	m_balance = a_balance;
}

double ClientData::getBalance() const
{
	return m_balance;
}
