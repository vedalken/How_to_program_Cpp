#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cmath>

enum RequestType { ZERO_BALANCE = 1, CREDIT_BALANCE, DEBIT_BALANCE, END };

bool shouldDisplay( int, double );
void outputLine( int , const std::string & , double );
int getRequest();

int main()
{
	std::ifstream inClientFile( "clients.txt", std::ios::in );

	if ( !inClientFile )
	{
		std::cerr << "File could not be opened" << std::endl;
		std::exit( EXIT_FAILURE );
	}

	int account;
	std::string name;
	double balance;

	int request = getRequest();

	while ( request != END )
	{
		switch ( request )
		{
		case ZERO_BALANCE:
			std::cout << "\nAccounts with zero balance:\n";
			break;
		case CREDIT_BALANCE:
			std::cout << "\nAccounts with credit balance:\n";
			break;
		case DEBIT_BALANCE:
			std::cout << "\nAccounts with debit balance:\n";
			break;
		default:
			std::cout << "\nUnknown request.\n";
			request = getRequest();
			continue;
		}

		// read account, name and balance from file
		inClientFile >> account >> name >> balance;

		while ( !inClientFile.eof() )
		{
			// display record
			if ( shouldDisplay( request, balance ) )
				outputLine( account, name, balance );

			// read next line in file
			inClientFile >> account >> name >> balance;
		}

		inClientFile.clear(); // clear eof for next input
		inClientFile.seekg( 0 ); // reposition to beginning of file
		request = getRequest();
	}

	std::cout << "End of run." << std::endl;

	return 0;
}

bool shouldDisplay( int a_request, double a_balance )
{
	if ( a_request == ZERO_BALANCE && std::fabs(a_balance) < 1e-5 )
		return true;

	if ( a_request == CREDIT_BALANCE && a_balance < 0.0 )
		return true;

	if ( a_request == DEBIT_BALANCE && a_balance > 0.0 )
		return true;

	return false;
}

int getRequest()
{
	int request(0);

	std::cout << "\nEnter request\n"
		<< std::setw(3) << ZERO_BALANCE   << " - List accounts with zero balance\n"
		<< std::setw(3) << CREDIT_BALANCE << " - List accounts with credit balance\n"
		<< std::setw(3) << DEBIT_BALANCE  << " - List accounts with debit balance\n"
		<< std::setw(3) << END            << " - End of run\n";

	do // input user request
	{
		std::cout << "\n? ";
		std::cin >> request;
	} while ( request < ZERO_BALANCE && request > END );

	return request;
}

void outputLine( int a_account, const std::string& a_name, double a_balance )
{
	std::cout << std::fixed << std::setprecision( 2 ) << std::showpoint;
	std::cout << std::right << std::setw(10) << a_account << std::setw(10) << a_name
		<< std::right << std::setw(10) << a_balance << std::endl;
}
