#include <iostream>

int main()
{
    bool booleanValue(true);

    std::cout << "booleanValue is " << booleanValue;
    std::cout << "\nbooleanValue (after using boolalpha) is "
        << std::boolalpha << booleanValue;

    std::cout << "\n\nSwitch booleanValue and use noboolalpha";

    std::cout << "\n\nbooleanValue is " << std::noboolalpha << booleanValue;
    std::cout << "\nbooleanValue (after using boolalpha) is "
        << std::boolalpha << booleanValue << std::endl;

    return 0;
}
