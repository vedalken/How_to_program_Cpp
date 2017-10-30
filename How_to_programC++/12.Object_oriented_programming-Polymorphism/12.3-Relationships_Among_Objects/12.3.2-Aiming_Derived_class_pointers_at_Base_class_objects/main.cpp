#include "BasePlusCommissionEmployee.h"

int main()
{
    // create base-class object
    CommissionEmployee commissionEmployee(
            "Sue", "Jones", "222-22-2222", 10000, .06);

    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr __attribute__((unused))
        = nullptr;

    // aim derived-class pointer at base-class object
    // Compiler error: a CommissionEmployee is not a BasePlusCommissionEmployee
    //basePlusCommissionEmployeePtr = &commissionEmployee;

    return 0;
}
