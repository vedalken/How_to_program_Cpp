#include <iostream>

int main()
{
    double x = 0.00123457;
    double y = 1.946e9;

    std::cout << "Displayed in default format\n"
        << x << '\t' << y << std::endl;

    std::cout << "\nDisplayed in scientific format\n"
        << std::scientific << x << '\t' << y << std::endl;

    std::cout << "\nDisplayed in fixed format\n"
        << std::fixed << x << '\t' << y << std::endl;

    return 0;
}
