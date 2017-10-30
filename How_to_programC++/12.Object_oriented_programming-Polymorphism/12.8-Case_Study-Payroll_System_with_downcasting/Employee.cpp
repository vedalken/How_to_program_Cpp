#include <iostream>
#include "Employee.h"

Employee::Employee(
        const std::string& a_firstName,
        const std::string& a_lastName,
        const std::string& a_ssn )
    : m_firstName( a_firstName ),
      m_lastName( a_lastName ),
      m_ssn( a_ssn )
{
}

const std::string& Employee::getFirstName() const
{
    return m_firstName;
}

void Employee::setFirstName( const std::string& a_firstName )
{
    m_firstName = a_firstName;
}

const std::string& Employee::getLastName() const
{
    return m_lastName;
}

void Employee::setLastName( const std::string& a_lastName )
{
    m_lastName = a_lastName;
}

const std::string& Employee::getSsn() const
{
    return m_ssn;
}

void Employee::setSsn( const std::string& a_ssn )
{
    m_ssn = a_ssn;
}

void Employee::print() const
{
    std::cout << getFirstName() << ' ' << getLastName()
        << "\nsocial security number: " << getSsn();
}
