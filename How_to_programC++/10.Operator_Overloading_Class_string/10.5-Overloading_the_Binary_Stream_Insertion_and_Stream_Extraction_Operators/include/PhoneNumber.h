#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <ostream>
#include <istream>
#include <string>

class PhoneNumber
{
        friend std::ostream &operator<<( std::ostream &, const PhoneNumber & );
        friend std::istream &operator>>( std::istream &, PhoneNumber & );
    public:
        std::ostream &operator<<( std::ostream & );
        std::istream &operator>>( std::istream & );
    private:
        std::string _areaCode; // 3-digit area code
        std::string _exchange; // 3-digit exchange
        std::string _line;     // 4-digit line
};

#endif
