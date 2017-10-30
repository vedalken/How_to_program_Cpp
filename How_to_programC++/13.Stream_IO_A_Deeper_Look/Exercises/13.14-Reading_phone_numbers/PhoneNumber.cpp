#include <string>
#include <iomanip>
#include "PhoneNumber.h"

std::ostream& operator<<( std::ostream &output, const PhoneNumber &number )
{
    output << "(" << number.m_areaCode << ") " << number.m_exchange 
        << "-" << number.m_line;
    return output;
}

// stream extraction operator perform error checking on input
// input entire phone of the form (XXX) XXX-XXXX
std::istream& operator>>( std::istream &input, PhoneNumber &number )
{
    const size_t phoneNumberLength( 14 );
    std::string phoneNumber;
    std::getline( input, phoneNumber );

    // test proper number of characters entered
    if ( phoneNumber.size() != phoneNumberLength )
        input.clear( std::ios_base::failbit );

    // test parenthesis
    if ( phoneNumber.at( 0 ) != '(' || phoneNumber.at( 4 ) != ')' )
        input.clear( std::ios_base::failbit );

    // test whitespace
    if ( phoneNumber.at( 5 ) != ' ' )
        input.clear( std::ios_base::failbit );

    const std::string& areaCode = phoneNumber.substr( 1, 3 );
    const std::string& exchange = phoneNumber.substr( 6, 3 ); 
    const std::string& line     = phoneNumber.substr( 10, 4 );

    // area code number must not begin with 0 or 1
    if ( areaCode.at( 0 ) == '1' || areaCode.at( 0 ) == '0' )
        input.clear( std::ios_base::failbit );

    // middle area code number digit must be 0 or 1
    if ( ( areaCode.at( 1 ) - '0' ) > 1 )
        input.clear( std::ios_base::failbit );

    // exchange number must not begin with 0 or 1
    if ( exchange.at( 0 ) == '1' || exchange.at( 0 ) == '0' )
        input.clear( std::ios_base::failbit );

    // test dash
    if ( phoneNumber.at( 9 ) != '-' )
        input.clear( std::ios_base::failbit );

    number.m_areaCode = areaCode;
    number.m_exchange = exchange;
    number.m_line     = line;

    return input;
}
