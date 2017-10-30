#include <iomanip>
#include "PhoneNumber.h"

// Overloaded stream insertion operator
// cannot be a member function if we would like to invoke it with
// cout << PhoneNumber;
std::ostream &operator<<( std::ostream &output, const PhoneNumber &number )
{
    output << "(" << number._areaCode << ") "
        << number._exchange << "-" << number._line;
    return output;
}

// Overloaded stream extraction operator
// cannot be a member function if we would like to invoke it with
// cin >> somePhoneNumber
std::istream &operator>>( std::istream &input, PhoneNumber &number )
{
    input.ignore(); // skip (
    input >> std::setw(3) >> number._areaCode; // input area code
    input.ignore(2); // skip ( and white space
    input >> std::setw(3) >> number._exchange; // input exchange code
    input.ignore(); // skip - (dash)
    input >> std::setw(4) >> number._line; // input line
    return input;
}

// Overloaded stream insertion operator (strange usage!)
std::ostream &PhoneNumber::operator<<( std::ostream &output )
{
    output << "(" << _areaCode << ") " << _exchange << "-" << _line;
    return output;
}

// Overloaded stream extraction operator (strange usage!)
std::istream &PhoneNumber::operator>>( std::istream &input )
{
    input.ignore();
    input >> std::setw(3) >> _areaCode;
    input.ignore(2);
    input >> std::setw(3) >> _exchange;
    input.ignore();
    input >> std::setw(4) >> _line;
    return input;
}
