#include <iostream>
#include <string>
#include "String.h"

String::String()
    : str_{}
{
}

String::String( const String& s )
    : str_{ s.str_ }
{
}

String::String( const std::string& s )
    : str_{ s }
{
}

String::operator const char*() const
{
    std::cout << "String object conversion operator to const char*" << std::endl;

    return str_.c_str();
}
