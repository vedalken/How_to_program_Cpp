#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::getline( std::cin, str );

    // width twice the string lenght
    std::cout.width( str.length() * 2 );
    std::cout.fill('#');
    std::cout << str << std::endl;

    return 0;
}
