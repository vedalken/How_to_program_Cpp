#include <iostream>
#include <vector>
#include <iomanip>
#include "SalariedEmployee.h"
#include "BasePlusCommissionEmployee.h"

void virtualViaPointer( const Employee * const );
void virtualViaRef( const Employee & );

int main()
{
    std::cout << std::fixed << std::setprecision(2);

    SalariedEmployee salariedEmployee(
        "John", "Smith", "1111-11-1111", 800 );
    CommissionEmployee commissionEmployee(
        "Sue", "Jones", "3333-33-3333", 10000, .06 );
    BasePlusCommissionEmployee basePlusCommissionEmployee(
        "Bob", "Lewis", "4444-44-4444", 5000, .04, 300 );

    std::cout << "Employees processed individually using static binding:\n\n";

    // output each Employee's information using static bindings
    salariedEmployee.print();
    std::cout << "\nearned: $" << salariedEmployee.earnings() << "\n\n";
    commissionEmployee.print();
    std::cout << "\nearned: $" << commissionEmployee.earnings() << "\n\n";
    basePlusCommissionEmployee.print();
    std::cout << "\nearned: $" << basePlusCommissionEmployee.earnings() << "\n\n";

    // create vector of three base-class pointers
    std::vector< Employee * > employees( 3 );

    // initialize vector with pointers to Employee
    employees[ 0 ] = &salariedEmployee;
    employees[ 1 ] = &commissionEmployee;
    employees[ 2 ] = &basePlusCommissionEmployee;

    std::cout << "Employees processed polimorphically via dynamic binding:\n\n";

    std::cout << "Virtual function calls made off base-class pointers:\n\n";

    for ( const Employee *employeePtr : employees )
        virtualViaPointer( employeePtr );

    std::cout << "Virtual function calls made off base-class references:\n\n";

    for ( const Employee* employeeRef : employees )
        virtualViaRef( *employeeRef );


    return 0;
}

// dynamic binding
void virtualViaPointer( const Employee * const a_employeePtr )
{
    a_employeePtr->print();
    std::cout << "\nearned $" << a_employeePtr->earnings() << "\n\n";
}

// static binding
void virtualViaRef( const Employee& a_employeeRef )
{
    a_employeeRef.print();
    std::cout << "\nearned $" << a_employeeRef.earnings() << "\n\n";
}
