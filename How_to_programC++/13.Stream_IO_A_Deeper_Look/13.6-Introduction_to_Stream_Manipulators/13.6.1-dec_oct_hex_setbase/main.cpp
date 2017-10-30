#include <iostream>
#include <iomanip> // setbase

int main()
{
    int number;

    std::cout << "Enter a decimal number: ";
    std::cin >> number;

    // show hexadecimal number
    std::cout << number << " in hexadecimal is: " << std::hex
        << number << std::endl;

    // show octal number
    std::cout << std::dec << number << " in octal is: " << std::oct
        << number << std::endl;

    std::cout << std::setbase(10) << number << " in decimal is "
        << number << std::endl;

    return 0;
}
