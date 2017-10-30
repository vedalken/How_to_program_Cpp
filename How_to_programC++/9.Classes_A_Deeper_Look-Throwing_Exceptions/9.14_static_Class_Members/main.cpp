#include <iostream>
#include "Employee.h"

int main()
{
    std::cout << "Number of employees before instantiation on any objects is "
        << Employee::getCount() << std::endl;

    // create and destroy local scoped variable
    {
        Employee e1("Susan", "Baker");
        Employee e2("Mark",  "Jones");

        std::cout << "Number of employees after instantiation on any objects is "
            << Employee::getCount() << std::endl;

        std::cout << "\n\nEmployee 1: " << e1.getFirstName() << ' ' << e1.getLastName()
            << "\nEmployee 2: " << e2.getFirstName() << ' ' << e2.getLastName() 
            << "\n\n";
    }

    // no object exists
    std::cout << "Number of employees after object deletion is " 
        << Employee::getCount() << std::endl;

    return 0;
}
