#include <fstream>
#include <iostream>
#include <cstdlib>
#include "ClientData.h"

int main()
{
	int accountNumber;
	std::string lastName;
	std::string firstName;
	double balance;

	std::fstream outCredit( "credit.dat", std::ios::in | std::ios::out | std::ios::binary );

	if ( !outCredit )
	{
		std::cerr << "File could not be opened" << std::endl;
		std::exit( EXIT_FAILURE );
	}

	ClientData client;

	std::cout << "Enter account number (1 to 100, 0 to end input)\n? ";
	std::cin >> accountNumber;

	while ( accountNumber > 0 && accountNumber <= 100 )
	{
		std::cout << "Enter lastname, firstname, balance\n? ";
		std::cin >> lastName;
		std::cin >> firstName;
		std::cin >> balance;

		client.setAccountNumber( accountNumber );
		client.setLastName( lastName );
		client.setFirstName( firstName );
		client.setBalance( balance );

		// seekp position in file of user-defined record
		outCredit.seekp( (client.getAccountNumber() - 1) * sizeof(ClientData) );
		
		// write user-specified information in file
		outCredit.write( reinterpret_cast<const char *>(&client), sizeof(ClientData) );
	
		std::cout << "Enter account number (1 to 100, 0 to end input)\n? ";
		std::cin >> accountNumber;
	}

	return 0;
}
