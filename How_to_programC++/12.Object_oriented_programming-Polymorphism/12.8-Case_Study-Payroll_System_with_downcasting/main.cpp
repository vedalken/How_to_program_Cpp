#include <iostream>
#include <vector>
#include <iomanip>
#include <typeinfo>
#include "SalariedEmployee.h"
#include "BasePlusCommissionEmployee.h"

    int main()
    {
        std::cout << std::fixed << std::setprecision(2);

        // create vector of three base-class pointers
        std::vector<Employee *> employees( 3 );

        employees[ 0 ] = new SalariedEmployee(
            "John", "Smith", "1111-11-1111", 800 );
        employees[ 1 ] = new CommissionEmployee(
            "Sue", "Jones", "3333-33-3333", 10000, .06 );
        employees[ 2 ] = new BasePlusCommissionEmployee(
            "Bob", "Lewis", "4444-44-4444", 5000, .04, 300 );

        // polymorphically process each element in vector employees
        for ( Employee * employeePtr : employees )
        {
            employeePtr->print();
            std::cout << '\n';
            
            try {
                // attempt to downcast pointer
                BasePlusCommissionEmployee * derivedPtr = 
                    dynamic_cast< BasePlusCommissionEmployee * >( employeePtr );

                // determine if casting succeeded
                if ( derivedPtr != nullptr ) // true for "is a" relationship
                {
                    double oldBaseSalary = derivedPtr->getBaseSalary();
                    std::cout << "old base salary is " << oldBaseSalary;

                    // add 10 procent to base salary
                    derivedPtr->setBaseSalary( 1.10 * oldBaseSalary );

                    std::cout << "\nnew base salary with 10% increase is: " 
                        << derivedPtr->getBaseSalary() << std::endl;
                }

                std::cout << "earned $" << employeePtr->earnings() << "\n\n";
            }
            catch (const std::bad_cast &bc) {
                std::cerr << "bad_cast caught: " << bc.what() << std::endl;
            }
        }

        // release object pointer to by vector's elements
        for ( const Employee *employeePtr : employees )
        {
            // output class name
            std::cout << "deleting object of " 
                << typeid( *employeePtr ).name() << '\n';
            
            delete employeePtr;
        }

        return 0;
    }
