#include <iostream>
#include <fstream>

int main()
{
	std::ofstream outTransaction( "trans.dat", std::ios::out );


	int accountNumber;
	double transAmount;

	std::cout << "Enter account number and transaction amount (^D to escape)\n";
	while ( std::cin >> accountNumber >> transAmount )
	{
		outTransaction << accountNumber << ' ' << transAmount << std::endl;
		std::cout << "? ";
	}

	outTransaction.close();
	return 0;
}
