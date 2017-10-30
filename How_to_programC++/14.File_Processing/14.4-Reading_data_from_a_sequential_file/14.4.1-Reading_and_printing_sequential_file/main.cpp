#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

void outputLine(int a_account, const std::string& a_name, double a_balance);

int main()
{
	// open file for reading
	std::ifstream inClientFile( "clients.txt", std::ios::in );

	if ( !inClientFile )
	{
		std::cerr << "File could not be opened" << std::endl;
		std::exit( EXIT_FAILURE );
	}

	int account;
	std::string name;
	double balance;

	std::cout << std::left << std::setw(10) << "Account" << std::setw(10) << "Name"
		<< std::right << std::setw(10) << "Balance" << std::endl << std::fixed << std::showpoint;

	// read from file until failbit (occure end-of-file)
	while ( inClientFile >> account >> name >> balance )
		outputLine( account, name, balance );

	if ( inClientFile.eof() )
	{
		std::cout << "Reached end-of-file with set";
		if ( inClientFile.bad() )  std::cout << " badbit";
		if ( inClientFile.fail() ) std::cout << " failbit";
		std::cout << std::endl;
	}

	inClientFile.close();
	return 0;
}

void outputLine(int a_account, const std::string& a_name, double a_balance)
{
	std::cout << std::left << std::setw( 10 ) << a_account << std::setw(10) << a_name 
		<< std::setprecision(2) << std::right << std::setw(10) << a_balance << std::endl;
}
