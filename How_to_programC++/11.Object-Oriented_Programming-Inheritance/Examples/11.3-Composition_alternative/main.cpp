#include <iostream>
#include <iomanip>
#include "BasePlusCommissionEmployee.h"

int main()
{
    // initiate a commission object
    BasePlusCommissionEmployee employee(
            "Bob", "Lewies", "333-33-3333", 5000, .04, 300);

    // set fix floating point precision
    std::cout << std::fixed << std::setprecision(2);
    employee.print();

    employee.setBaseSalery( 1000 ); // set base salary

    std::cout << "\n\nUpdated employee information\n";
    employee.print();

    std::cout << "\nemployee's earnings: $" << employee.earnings() << std::endl;

    return 0;
}
