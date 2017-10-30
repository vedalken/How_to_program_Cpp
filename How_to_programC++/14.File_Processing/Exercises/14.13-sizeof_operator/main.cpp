#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

int main()
{
	std::ofstream outFile("datasize.dat", std::ios::out);

	if ( !outFile )
	{
		std::cerr << "Failed to open file" << std::endl;
		std::exit( EXIT_FAILURE );
	}

	outFile << std::left << std::setw( 25 ) << "char" << std::setw( 5 ) 
		<< std::right << sizeof(char) << '\n'
		<< std::left << std::setw( 25 ) << "unsigned char" << std::setw( 5 ) 
		<< std::right << sizeof(unsigned char) << '\n'
		<< std::left << std::setw( 25 ) << "short int" << std::setw( 5 ) 
		<< std::right << sizeof(short int) << '\n'
		<< std::left << std::setw( 25 ) << "unsigned short int" << std::setw( 5 ) 
		<< std::right << sizeof(unsigned short int) << '\n'
		<< std::left << std::setw( 25 ) << "int" << std::setw( 5 )
		<< std::right << sizeof(int) << '\n'
		<< std::left << std::setw( 25 ) << "unsigned int" << std::setw( 5 )
		<< std::right << sizeof(unsigned int) << '\n'
		<< std::left << std::setw( 25 ) << "long int" << std::setw( 5 )
		<< std::right << sizeof(long int) << '\n'
		<< std::left << std::setw( 25 ) << "unsigned long int" << std::setw( 5 )
		<< std::right << sizeof(unsigned long int) << '\n'
		<< std::left << std::setw( 25 ) << "float" << std::setw( 5 )
		<< std::right << sizeof(float) << '\n'
		<< std::left << std::setw( 25 ) << "double" << std::setw( 5 )
		<< std::right << sizeof(double) << '\n'
		<< std::left << std::setw( 25 ) << "long double" << std::setw( 5 )
		<< std::right << sizeof(long double) << std::endl;

	outFile.close();
	return 0;
}
