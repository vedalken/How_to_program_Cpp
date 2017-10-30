#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main()
{
	// open a file
	std::ofstream outClientFile;
	outClientFile.open( "clients.txt", std::ios::out );

	if ( !outClientFile )
	{
		std::cerr << "File could not be opened" << std::endl;
		std::exit( EXIT_FAILURE );
	}

	std::cout << "Enter the account, name, and balance."
		<< "\nEnter end-of-file to end input.\n? ";

	int account;
	std::string name;
	double balance;

	// read account, name and balance
	// on failure failbit or badbit are set implicitly by calling conversion 
	// operator `operator void* ()' or `operator bool()'
	while ( std::cin >> account >> name >> balance )
	{
		outClientFile << account << ' ' << name << ' ' << balance << std::endl;
		std::cout << "? ";
	}

	// close a file
	outClientFile.close();
	return 0;
}
