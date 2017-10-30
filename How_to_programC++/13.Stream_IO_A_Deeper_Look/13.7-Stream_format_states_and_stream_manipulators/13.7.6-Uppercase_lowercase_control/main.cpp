#include <iostream>
using namespace std;

int main()
{
    std::cout << "Printing uppercase letters in scientific notation\n"
        << "exponents and hexadecimal values:\n";

    std::cout << std::uppercase << 4.345e10 << std::endl
        << std::hex << std::showbase << 123456789 << std::endl;

    std::cout << std::nouppercase;
    std::cout << std::showbase << std::dec << 123456789 << '\t' 
        << std::oct << 123456789 << std::endl;

    return 0;
}
