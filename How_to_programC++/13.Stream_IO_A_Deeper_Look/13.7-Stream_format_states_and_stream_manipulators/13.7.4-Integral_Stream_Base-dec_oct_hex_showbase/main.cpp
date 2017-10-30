#include <iostream>

int main()
{
    const int x = 100;

    std::cout << "Printing integers preceeded by their base:\n";
    std::cout << std::showbase;

    std::cout << x << std::endl;
    std::cout << std::oct << x << std::endl;
    std::cout << std::hex << x << std::endl;

    return 0;
}
