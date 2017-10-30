#include <iostream>
#include <iomanip>
#include "BasePlusCommissionEmployee.h"

int main()
{
    // create base-class object
    CommissionEmployee commissionEmployee(
            "Sue", "Jones", "222-22-2222", 10000, .06);

    // create base-class pointer
    CommissionEmployee *commissionEmployeePtr = nullptr;

    // create derived-class object
    BasePlusCommissionEmployee basePlusCommissionEmployee(
            "Bob", "Lewis", "333-33-3333", 5000, .04, 300);

    // create derived-class pointer
    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = nullptr;

    // set fix floating point precision format
    std::cout << std::fixed << std::setprecision(2);

    // output base-class and derived-class object
    std::cout << "Print base-class and derived-class objects:\n\n";
    commissionEmployee.print();
    std::cout << "\n\n";
    basePlusCommissionEmployee.print();

    // aim base-class pointer at base-class object and print
    commissionEmployeePtr = &commissionEmployee;
    std::cout << "\n\n\nCalling print() with base-class pointer to base-class object\n\n";
    commissionEmployeePtr->print();

    // aim derived-class pointer at derived-class object and print
    basePlusCommissionEmployeePtr = &basePlusCommissionEmployee;
    std::cout << "\n\n\nCalling print() with derived-class pointer to derived-class object\n\n";
    basePlusCommissionEmployeePtr->print();

    // aim base-class pointer at derived-class object and print
    // Is allowed since derived class is a base class
    commissionEmployeePtr = &basePlusCommissionEmployee;
    std::cout << "\n\n\nCalling print() with base-class pointer to derived-class object\n\n";
    commissionEmployeePtr->print(); // invokes base-class print()

    std::cout << '\n';

    return 0;
}
