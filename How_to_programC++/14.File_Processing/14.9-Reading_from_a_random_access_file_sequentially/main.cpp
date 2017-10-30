#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "ClientData.h"

void outputLine( std::ostream &, const ClientData & );

int main()
{
	std::ifstream readFile( "credit.dat", std::ios::in | std::ios::binary );

	if ( !readFile )
	{
		std::cerr << "File could not opened" << std::endl;
		std::exit( EXIT_SUCCESS );
	}

	ClientData client;

	// open file to read
	readFile.read( reinterpret_cast<char *>(&client), sizeof(ClientData) );

	std::cout << std::left 
		<< std::setw(10) << "Account" << std::setw(15) << "Last Name"
		<< std::setw(15) << "First Name" << std::right
		<< std::setw(10) << "Balance" << std::endl;

	while ( readFile && !readFile.eof() ) 
	{
		if ( client.getAccountNumber() != 0 ) 
			outputLine( std::cout, client );

		readFile.read( reinterpret_cast<char *>(&client), sizeof(ClientData) );
	}

	return 0;
}

void outputLine( std::ostream &output, const ClientData &client )
{
	output << std::left << std::setw(10) << client.getAccountNumber()
		<< std::setw(15) << client.getLastName()
		<< std::setw(15) << client.getFirstName()
		<< std::setw(10) << std::right << std::fixed << std::setprecision(2)
		<< std::showpoint << client.getBalance() << std::endl;
}
