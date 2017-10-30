#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H
#include <iostream>
#include <string>

class PhoneNumber
{
    friend std::ostream& operator<<( std::ostream &, const PhoneNumber &);
    friend std::istream& operator>>( std::istream &, PhoneNumber &);
    private:
        std::string m_areaCode;
        std::string m_exchange;
        std::string m_line;
};

#endif
