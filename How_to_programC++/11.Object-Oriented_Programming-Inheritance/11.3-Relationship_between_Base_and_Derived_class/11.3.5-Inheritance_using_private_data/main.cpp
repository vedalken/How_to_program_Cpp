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

    // get commission employee data
    std::cout << "Employee information obtained by get function\n"
        << "\nFirst name: " << employee.getFirstName()
        << "\nLast name:  " << employee.getLastName()
        << "\nSocial security number: " << employee.getSocialSecurityNumber()
        << "\nGross sales: " << employee.getGrossSales()
        << "\nCommission rate: " << employee.getCommissionRate()
        << "\nBase salary: " << employee.getBaseSalery()
        << std::endl;

    employee.setBaseSalery( 1000 ); // set base salary

    std::cout << "\nUpdated employee information\n";
    employee.print();

    std::cout << "\nemployee's earnings: $" << employee.earnings() << std::endl;

    return 0;
}
