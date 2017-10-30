#include <iostream>

int main()
{
    std::cout << "Before using showpoint:"
        << "\n9.9900 prints as: " << 9.9900
        << "\n9.9000 prints as: " << 9.9000
        << "\n9.0000 prints as: " << 9.0000
        << std::endl;

    std::cout << std::showpoint
        << "\nAfter using showpoint:"
        << "\n9.9900 prints as: " << 9.9900
        << "\n9.9000 prints as: " << 9.9000
        << "\n9.0000 prints as: " << 9.0000
        << std::endl;

    std::cout << std::noshowpoint
        << "\nAfter reset showpoint with noshowpoint:"
        << "\n9.9900 prints as: " << 9.9900
        << "\n9.9000 prints as: " << 9.9000
        << "\n9.0000 prints as: " << 9.0000
        << std::endl;

    return 0;
}
