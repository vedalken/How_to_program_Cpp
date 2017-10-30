#include <iostream>
#include <iomanip>

int main()
{
    int intVal = 12345;
    double doubleVal = 1.2345;

    for (int i = 10; i > 0; --i)
        std::cout << std::setw( i ) << intVal << std::setw( i ) << doubleVal << std::endl;

    return 0;
}
