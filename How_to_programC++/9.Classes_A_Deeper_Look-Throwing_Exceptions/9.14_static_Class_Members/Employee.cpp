#include "Employee.h"
#include <iostream>
#include <string>

// define and initialize static data member at global namespace scope
unsigned int Employee::count = 0;

// define static member function that returns number fo Employee
// objects instantiated
unsigned int Employee::getCount()
{
    return count;
}

Employee::Employee( const std::string& firstName, const std::string& lastName)
    : m_firstName(firstName),
      m_lastName(lastName)
{
    // increment static count of employee
    ++count;

    std::cout << "Employee constructor for " << m_firstName << ' '
        << m_lastName << " called." << std::endl;
}

Employee::~Employee()
{
    std::cout << "~Employee called for " << m_firstName << ' '
        << m_lastName << std::endl;

    // decrement static count of employee   
    --count;
}

const std::string& Employee::getFirstName() const
{
    return m_firstName;
}

const std::string& Employee::getLastName() const
{
    return m_lastName;
}
