// A program reads a random-access file sequentially, updates
// data previously written to the file, creates data to be placed
// in the file, and deletes data previously stored in the file

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "ClientData.h"

int enterChoice();
void outputLine( std::ostream &, const ClientData & );
void createTextFile( std::fstream & );
void updateRecord( std::fstream & );
void newRecord( std::fstream & );
void deleteRecord( std::fstream & );
int getAccount( const char * const );

enum Choice { PRINT = 1, UPDATE, NEW, DELETE, END };

int main()
{
	// open binary file
	std::fstream inOutCredit( "credit.dat", std::ios::in | std::ios::out | std::ios::binary );

	if ( !inOutCredit ) {
		std::cerr << "File could not be opened" << std::endl;
		std::exit( EXIT_SUCCESS );
	}

	// store user choice
	int choice;

	// process user choice
	while ( (choice = enterChoice()) != END )
	{
		switch (choice)
		{
		case PRINT:
			createTextFile( inOutCredit );
			break;
		case UPDATE:
			updateRecord( inOutCredit );
			break;
		case NEW:
			newRecord( inOutCredit );
			break;
		case DELETE:
			deleteRecord( inOutCredit );
			break;
		default:
			std::cerr << "Incorrect choice" << std::endl;
			break;
		}// end switch

		// reset end-of-file indicator
		inOutCredit.clear();
	}

	// close file
	inOutCredit.close();
	return 0;
}

void createTextFile( std::fstream &readFromFile )
{
	// store information in formatted file
	std::ofstream outPrintFile( "print.txt", std::ios::out );

	if ( !outPrintFile ) {
		std::cerr << "File could not be opened" << std::endl;
		std::exit( EXIT_SUCCESS );	
	}

	outPrintFile << std::left << std::setw(10) << "Account"
		<< std::setw(16) << "Last Name" << std::setw(11) << "First Name"
		<< std::setw(10) << std::right << "Balance" << std::endl;

	// set file-read-position pointer to the beginning
	readFromFile.seekg( 0 );

	ClientData client;
	readFromFile.read( reinterpret_cast<char *>(&client), sizeof(ClientData) );

	while ( !readFromFile.eof() )
	{
		// skip non-set accounts
		if ( client.getAccountNumber() != 0 )
			outputLine( outPrintFile, client );

		// read another entry from file
		readFromFile.read( reinterpret_cast<char *>(&client), sizeof(ClientData) );
	}

	outPrintFile.close();
}// end createTextFile

void updateRecord( std::fstream &updateFile )
{
	int accountNumber = getAccount( "Enter account to update" );

	ClientData client;
	updateFile.seekg( (accountNumber - 1) * sizeof(ClientData) );
	updateFile.read( reinterpret_cast<char *>(&client), sizeof(ClientData) );

	// update record
	if ( client.getAccountNumber() == accountNumber )
	{
		// before record update
		outputLine( std::cout, client );

		std::cout << "\nEnter a charge (+) or payment (-): ";
		
		double transaction(0.0);
		std::cin >> transaction;
		if ( !std::cin.good() ) {
			std::cerr << "Input error" << std::endl;
			return;
		}
		
		double oldBalance = client.getBalance();
		client.setBalance( oldBalance + transaction );

		// after record update
		outputLine( std::cout, client );

		// move file-position pointer to correct record
		updateFile.seekp( (accountNumber - 1) * sizeof(ClientData) );

		// write updated record
		updateFile.write( reinterpret_cast<const char *>(&client), sizeof(ClientData) );
	}
	else {
		std::cerr << "Account #" << accountNumber << " has no information" << std::endl;
	}
}// end updateRecord

void newRecord( std::fstream &insertInFile )
{
	int accountNumber = getAccount( "Enter account to add" );

	ClientData client;
	insertInFile.seekg( (accountNumber - 1) * sizeof(ClientData) );
	insertInFile.read( reinterpret_cast<char *>(&client), sizeof(ClientData) );

	// insert new record
	if ( client.getAccountNumber() == 0 )
	{
		std::string lastName;
		std::string firstName;
		double balance;

		std::cout << "\nEnter last name, first name and balance:\n";
		std::cin >> std::setw(15) >> lastName;
		std::cin >> std::setw(10) >> firstName;
		std::cin >> balance;

		if ( !std::cin.good()) {
			std::cerr << "Input stream error" << std::endl;
			return;
		}

		client.setAccountNumber( accountNumber );
		client.setLastName( lastName );
		client.setFirstName( firstName );
		client.setBalance( balance );

		// write new record
		insertInFile.seekp( (accountNumber - 1) * sizeof(ClientData) );
		insertInFile.write( reinterpret_cast<const char *>(&client), sizeof(ClientData) );
	}
	else {
		std::cerr << "Account #" << accountNumber << " already exists" << std::endl;
	}
}// end newRecord

void deleteRecord( std::fstream &deleteFromFile )
{
	int accountNumber = getAccount( "Enter account to delete" );

	ClientData client;
	deleteFromFile.seekg( (accountNumber - 1) * sizeof(ClientData) );
	deleteFromFile.read( reinterpret_cast<char *>(&client), sizeof(ClientData) );

	if ( client.getAccountNumber() != 0 )
	{
		ClientData blankClient;
		deleteFromFile.seekp( (accountNumber - 1) * sizeof(ClientData) );
		deleteFromFile.write( reinterpret_cast<const char *>(&blankClient), sizeof(ClientData) );

		std::cout << "Account #" << accountNumber << " deleted.\n";
	}
	else {
		std::cerr << "Account #" << accountNumber << " is already empty!\n";
	}
}

int enterChoice()
{
	int choice;
	std::cout << "\nEnter your choice\n"
		<< PRINT  << " - store a formatted text file of accounts\n "
		<<           "   called \"print.txt\" for printing\n"
		<< UPDATE << " - update an account\n"
		<< NEW    << " - create new account\n"
		<< DELETE << " - delete an account\n"
		<< END    << " - end program\n? ";
	std::cin >> choice;
	if ( !std::cin.good() )
	{
		std::cerr << "Unknown entered option. Exiting." << std::endl;
		return END;
	}

	return choice;
}// end enterChoice

void outputLine( std::ostream &output, const ClientData &record )
{
	output << std::left << std::setw( 10 ) << record.getAccountNumber()
		<< std::setw( 16 ) << record.getLastName()
		<< std::setw( 11 ) << record.getFirstName()
		<< std::setw( 10 ) << std::right << std::fixed << std::setprecision( 2 ) 
		<< std::showpoint << record.getBalance() << std::endl;
}// end outputLine

int getAccount( const char * const prompt )
{
	int accountNumber;

	do {
		std::cout << prompt << " (1-100): ";
		std::cin >> accountNumber;
		
		if ( !std::cin.good() )
		{
			std::cerr << "Input stream error" << std::endl;
			break;
		}
	} while ( accountNumber < 0 || accountNumber > 100 );

	return accountNumber;
} // end getAccount
