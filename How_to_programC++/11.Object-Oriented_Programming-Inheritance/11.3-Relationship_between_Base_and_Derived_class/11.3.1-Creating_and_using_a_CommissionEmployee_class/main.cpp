#include <iostream>
#include <iomanip>
#include "CommissionEmployee.h"

int main()
{
    // initiate a commission object
    CommissionEmployee employee(
            "Sue", "Jones", "222-22-2222", 10000, .06);

    // set fix floating point precision
    std::cout << std::fixed << std::setprecision(2);

    // get commission employee data
    std::cout << "Employee information obtained by get function\n"
        << "\nFirst name: " << employee.getFirstName()
        << "\nLast name:  " << employee.getLastName()
        << "\nSocial security number: " << employee.getSocialSecurityNumber()
        << "\nGross sales: " << employee.getGrossSales()
        << "\nCommission rate: " << employee.getCommissionRate()
        << std::endl;

    employee.setGrossSales( 8000 ); // set gross sales
    employee.setCommissionRate( .1 ); // set commission rate

    std::cout << "\nUpdated employee information\n";
    employee.print();

    std::cout << "\nemployee's earnings: $" << employee.earnings() << std::endl;

    return 0;
}
