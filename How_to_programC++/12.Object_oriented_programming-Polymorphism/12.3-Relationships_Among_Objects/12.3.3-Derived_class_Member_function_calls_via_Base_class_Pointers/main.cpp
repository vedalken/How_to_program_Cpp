#include "BasePlusCommissionEmployee.h"

int main()
{
    // create base-class object
    BasePlusCommissionEmployee basePlusCommissionEmployee(
            "Bob", "Lewis", "333-33-3333", 5000, .04, 300);

    CommissionEmployee *commissionEmployeePtr = nullptr;

    // aim base-class pointer at derived-class object
    commissionEmployeePtr = &basePlusCommissionEmployee;

    // invoke base-class member functions on derived-class
    std::string firstName = commissionEmployeePtr->getFirstName();
    std::string lastName  = commissionEmployeePtr->getLastName();
    std::string ssn       = commissionEmployeePtr->getSocialSecurityNumber();
    double grossSales __attribute((unused)) = commissionEmployeePtr->getGrossSales();
    double commissionRate __attribute((unused)) = commissionEmployeePtr->getCommissionRate();

    // Compiler error: 
    // attempt to invoke derived-class-only member functions on derived-class object
    // through base-class pointer (disallowed)
    //double baseSalary = commissionEmployeePtr->getBaseSalary();
    //commissionEmployeePtr->setBaseSalary( 500 );

    return 0;
}
