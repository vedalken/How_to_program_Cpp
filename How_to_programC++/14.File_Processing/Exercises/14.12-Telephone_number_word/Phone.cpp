#include <iostream>
#include <iomanip>
#include <cctype>
#include <array>
#include "Phone.h"

Phone::Phone()
	: m_number{}
{
}

Phone::Phone( const std::string & a_number )
{
	if ( !setNumber(a_number) ) {
		std::cerr << "Failed to set number" << std::endl;
	}
}

Phone::~Phone()
{
}

std::istream& operator>>( std::istream &input, Phone &phone )
{
	std::string num, num1;
	input >> std::setw(3) >> num;
	input.ignore(); // skip dash
	input >> std::setw(4) >> num1;

	// add digits	
	num += num1;

	if ( num.find('1') != std::string::npos ||
	     num.find('0') != std::string::npos ) {
		std::cerr << "Phone number has digit 0 or 1" << std::endl;
		std::exit( EXIT_FAILURE );
	}

	phone.m_number = num;
	return input;
}

std::ostream& operator<<( std::ostream &output, const Phone& phone )
{
	output << phone.m_number.substr(0, 3) << "-" << phone.m_number.substr( 3 );

	return output;
}

bool Phone::setNumber( const std::string &a_number )
{
	if ( a_number.size() != 8 )
		return false;

	if ( a_number.at(3) != '-' )
		return false;

	std::string num;
	num  = a_number.substr( 0, 3 );
	num += a_number.substr( 4 );

	for ( auto i : num )
	{
		if ( !std::isdigit( i ) )
			return false;
	}

	m_number = num;
	return true;
}

const std::string& Phone::getNumber() const
{
	return m_number;
}

// Generator of words (skip digits 0 and 1)
// 2: A B C
// 3: D E F
// 4: G H J
// 5: J K L
// 6: M N O
// 7: P Q R S
// 8: T U V
// 9: W X Y Z
void Phone::wordGenerator() const
{
	static const std::array<std::string, 10> keypads = {
		"",      // 0
		"",      // 1
		"ABC",   // 2
		"DEF",   // 3
		"GHJ",   // 4
		"JKL",   // 5
		"MNO",   // 6
		"PQRS",  // 7
		"TUV",   // 8
		"WXZY"   // 9
	};

	// buffer
	std::string buffer = m_number;
}
