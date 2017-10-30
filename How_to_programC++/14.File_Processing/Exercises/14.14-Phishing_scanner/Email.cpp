#include <iostream>
#include "Email.h"
#include "PhishingScanner.h"

Email::Email( const std::string& a_fileName )
{
	m_data.open( a_fileName, std::ios::in );
}

Email::~Email()
{
	if ( m_data.is_open() )
		m_data.close();
}

void Email::phishingScan() const
{
	bool ret;
	PhishingScanner phishingScanner;
	
	try {
		ret = phishingScanner.scan( m_data );
	}
	catch ( const std::out_of_range &oor ) {
		std::cerr << oor.what() << std::endl;
		return;
	}

	if ( !ret )
		return;

	// display report
	phishingScanner.report();
}
