#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <iomanip>
#include "PhishingScanner.h"

PhishingScanner::PhishingScanner( const std::string a_databaseName )
{
	m_database.open( a_databaseName, std::ios::in );

	if ( !m_database ) {
		std::cerr << "Failed to open file database " << a_databaseName << std::endl;
		std::exit( EXIT_FAILURE );
	}

	// initialize report database
	_initReportDatabase();
}

PhishingScanner::~PhishingScanner()
{
	// close database
	if ( m_database.is_open() )
		m_database.close();
}

bool PhishingScanner::_initReportDatabase()
{
	int length = 0;
	int point;
	std::string phrase;

	// read database from beginning
	m_database.seekg( 0 );

	while ( m_database >> point ) {
		std::getline( m_database, phrase );
		++length;
	}

	if ( !m_database.eof() ) {
		std::cerr << "Error reading database" << std::endl;
		return false;
	}

	m_reportDatabase.reserve( length );
	
	for (int i = 0; i < length; ++i) {
		m_reportDatabase.push_back(0);
	}

	m_database.clear();
	return true;
}

// Scan filename for phishing scam contents
// The filename contents is searched within phishing database. At the end
// phishing report is created.
bool PhishingScanner::scan( std::ifstream& a_data )
{
	if ( !a_data.is_open() ) {
		std::cout << "Data file is not opened for phishing scanner" << std::endl;
		return false;
	}

	// reset file-position read pointer
	m_database.clear();
	m_database.seekg( 0 );

	int point;
	std::string phrase;
	std::string data;
	size_t index(0);

	// search for match in database
	// TODO: move database into memory
	while ( m_database >> point )
	{
		if ( point < 0 ) {
			throw std::out_of_range("Database point value is negative");
		}

		// ignore whitespace
		m_database.ignore();
		std::getline( m_database, phrase );
		
		// reset file-position read pointer
		a_data.clear();
		a_data.seekg( 0 );
		
		// read from datafile
		//while ( a_data >> data )
		while ( std::getline(a_data, data) )
		{
			if ( data.find( phrase ) != std::string::npos )
			{
				if ( index >= m_reportDatabase.size() ) {
					throw std::out_of_range("Database index is too big");
				}

				++m_reportDatabase[ index ];
			}
		}
		++index;
	}
	
	if ( !a_data.eof() ) {
		std::cerr << "Error reading file for phishing scanner" << std::endl;
		return false;
	}

	return true;
}// end function scan

// Display phishing report
void PhishingScanner::report() const
{
	std::cout << "\n\n----------- Phishing Report -------------\n\n";
	std::cout << std::setw( 20 ) << std::left << "phishing word" << std::setw( 15 ) 
		  << std::left << "occurance" << std::endl
		  << std::setw( 20 ) << "-------------" << std::setw( 15 ) << std::left << "---------"
	          << std::endl;

	long totalPoints(0);
	int point;
	std::string phrase;

	for ( size_t index = 0; index < m_reportDatabase.size(); ++index )
	{
		if ( m_reportDatabase.at( index ) > 0 ) 
		{
			size_t idx = 0;

			// read database from beginning
			m_database.clear();
			m_database.seekg( 0 );

			while ( m_database >> point )
			{
				// skip whitespace
				m_database.ignore();
				std::getline( m_database, phrase );

				if ( idx++ == index )
				{
					long points = point * m_reportDatabase.at( index );

					// calculate total number of scam entry occurance points
					// determined by the scanner (scan member function)
					totalPoints += points;
				
					std::cout << std::setw(20) << phrase << std::setw( 15 ) 
						<< m_reportDatabase.at( index ) << '\n';

					// unique database entry
					break;
				}// end if
			} // end while loop
		} // end if
	} // end for loop

	if ( totalPoints == 0 ) { 
		std::cout << "\n**** No phishing scam detected ****\n";
	}
	else {
		std::cout << "\n**** Phishing detected ****";
		std::cout << "\n\nTotal phishing scam score: " << totalPoints;
	}

	std::cout << "\n\n----------- End Phishing Report ----------\n\n";
}// end function report
