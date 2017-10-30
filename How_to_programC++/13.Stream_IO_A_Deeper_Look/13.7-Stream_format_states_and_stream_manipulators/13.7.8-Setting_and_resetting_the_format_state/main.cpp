#include <iostream>
int main()
{
    int integerValue = 1000;
    double doubleValue = 0.0543534;

    std::cout << "The value of the flags variable is: " << std::cout.flags()
        << "\nPrint int and double in original format:\n"
        << integerValue << '\t' << doubleValue << std::endl;

    std::ios_base::fmtflags origFormat = std::cout.flags();

    std::cout << std::showbase << std::oct << std::scientific;

    std::cout << "\nThe value of the flags variable is: " << std::cout.flags()
        << "\nPrint int and double in a new format:\n"
        << integerValue << '\t' << doubleValue << std::endl;

    std::cout.flags( origFormat );

    std::cout << "\nThe restored value of the flags variable is: " << std::cout.flags()
        << "\nPrint values in original format again:\n"
        << integerValue << '\t' << doubleValue << std::endl;

    return 0;
}
