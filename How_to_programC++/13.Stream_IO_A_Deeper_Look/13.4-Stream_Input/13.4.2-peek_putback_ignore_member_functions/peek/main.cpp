#include <iostream>

int main()
{
    std::cout << "Please enter your first or last name: ";
    std::cin >> std::ws; // remove white spaces

    char nameInitial = std::cin.peek();

    if ( nameInitial == EOF )
    {
        std::cout << "\nExiting..." << std::endl;
        return 1;
    }

    std::cout << nameInitial << std::endl;

    return 0;
}
