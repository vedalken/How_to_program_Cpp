#include <fstream>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Person.h"

// total id available in table
const int c_ids = 100;
const std::string fileNameAge("nameage.dat");

// list of options
enum class Options_t { PRINT, UPDATE, ADD, DELETE, END };

void initFileName( const std::string &name );
void updatePerson( std::fstream & );
void addPerson( std::fstream & );
void deletePerson( std::fstream & );
void createTextFile( std::fstream & );
int getId();

Options_t getOption();

int main()
{
	// initialize filename
	//initFileName( fileNameAge );

	std::fstream inOutNameAge( fileNameAge, std::ios::in | std::ios::out | std::ios::binary );
	if ( !inOutNameAge ) {
		std::cerr << "File could not be opened" << std::endl;
		std::exit( EXIT_FAILURE );
	}

	Options_t option;

	while ( (option = getOption()) != Options_t::END ) 
	{
		if      ( option == Options_t::PRINT )  createTextFile( inOutNameAge );
		else if ( option == Options_t::UPDATE ) updatePerson( inOutNameAge );
		else if ( option == Options_t::ADD )    addPerson( inOutNameAge );
		else if ( option == Options_t::DELETE ) deletePerson( inOutNameAge );
		else      std::cerr << "Unknown option!" << std::endl;
		
		// reset end-of-file indicator
		inOutNameAge.clear();
	}

	inOutNameAge.close();
	return 0;
}

Options_t getOption()
{
	int option;
	std::cout << "\nEnter your choice:\n"
		<< static_cast<int>(Options_t::PRINT)  << " - store a formated text file of persons\n"
		<< static_cast<int>(Options_t::UPDATE) << " - update a person\n"
		<< static_cast<int>(Options_t::ADD)    << " - add new person\n"
		<< static_cast<int>(Options_t::DELETE) << " - delete a person\n"
		<< static_cast<int>(Options_t::END)    << " - end program\n? ";

	std::cin >> option;

	const Options_t opt = static_cast<Options_t>(option);

	if ( ( opt < Options_t::PRINT ) || ( opt > Options_t::END ) ) {
		std::cerr << "Unknown option" << std::endl;
	   	std::exit( EXIT_FAILURE );
	}

	return opt;
}

void createTextFile( std::fstream &readFromFile )
{
	std::ofstream outTextFile( "data.txt", std::ios::out );

	if ( !outTextFile ) {
		std::cerr << "File could not be opened" << std::endl;
		std::exit( EXIT_FAILURE );
	}

	Person person;
	
	// reset file-position pointer to the beginning
	readFromFile.seekg( 0 );

	while ( !readFromFile.eof() )
	{
		readFromFile.read( reinterpret_cast<char *>(&person), sizeof(Person) );
		if ( person.getId() != 0 ) {
			outTextFile << person << std::endl;
		}
	}
}

void initFileName( const std::string &name )
{
	// initialize file
	std::ofstream outfile( name, std::ios::out | std::ios::binary );
	Person initPerson;

	for ( int i = 0; i < c_ids; ++i )
		outfile.write( reinterpret_cast<const char *>(&initPerson), sizeof(Person) );
	
	// close file
	outfile.close();
}

void updatePerson( std::fstream & writePersonInFile )
{
	int id = getId();
	if ( id < 0 ) return;

	Person person;

	// check existing id
	writePersonInFile.seekg( ( id - 1 ) * sizeof(Person) );
	writePersonInFile.read( reinterpret_cast<char *>(&person), sizeof(Person) );

	if ( person.getId() ==  id )
	{
		std::string firstName;
		std::string lastName;
		int age;

		std::cout << "Enter last name, first name and age\n? ";
		std::cin >> lastName >> firstName >> age;

		if ( std::cin.good() ) 
		{
			// update/add person to the database		
			person.setId( id );
			person.setLastName( lastName );
			person.setFirstName( firstName );
			person.setAge( age );

			// set write position-pointer
			writePersonInFile.seekp( (id - 1) * sizeof(Person) );
			writePersonInFile.write( reinterpret_cast<const char *>(&person), sizeof(Person) );
		}
	}
	else {
		std::cerr << "ID does not exist in database" << std::endl;
	}
}// end updatePerson

void addPerson( std::fstream &writePersonInFile )
{
	int id = getId();
	if ( id < 0 ) return;

	Person person;
	writePersonInFile.seekg( (id - 1) * sizeof(Person) );
	writePersonInFile.read( reinterpret_cast<char *>(&person), sizeof(Person) );

	if ( person.getId() != 0 ) {
		std::cerr << "ID exist in database" << std::endl;
		return;
	}

	std::string firstName, lastName;
	int age;
	std::cout << "Enter last name, first name and age\n? ";
	std::cin >> std::setw( 15 ) >> lastName;
	std::cin >> std::setw( 10 ) >> firstName;
	std::cin >> age;
	
	if ( !std::cin.good() ) {
		std::cerr << "Input error" << std::endl;
		return;
	}

	person.setId( id );
	person.setAge( age );
	person.setLastName( lastName );
	person.setFirstName( firstName );

	writePersonInFile.seekp( (id - 1) * sizeof(Person) );
	writePersonInFile.write( reinterpret_cast<const char *>(&person), sizeof(Person) );
}// end newPerson

void deletePerson( std::fstream & deleteFromFile )
{
	int id = getId();
	if ( id < 0 ) return;

	Person person;

	// check existing id
	deleteFromFile.seekg( ( id - 1 ) * sizeof(Person) );
	deleteFromFile.read( reinterpret_cast<char *>(&person), sizeof(Person) );

	if ( person.getId() == id )
	{
		// write empty entry
		Person emptyPerson;
		deleteFromFile.seekp( (id - 1) * sizeof(Person) );
		deleteFromFile.write( reinterpret_cast<const char *>(&emptyPerson), sizeof(Person) );
	}
}// end deletePerson

int getId()
{
	int id;
	std::cout << "Enter ID: ";
	std::cin >> id;

	if ( !std::cin.good() ) {
		std::cerr << "Input error" << std::endl;
		return -1;
	}

	if ( id <= 0 || id > c_ids ) {
		std::cerr << "Unknown id" << std::endl;
		return -1;
	}

	return id;
}// end getId
