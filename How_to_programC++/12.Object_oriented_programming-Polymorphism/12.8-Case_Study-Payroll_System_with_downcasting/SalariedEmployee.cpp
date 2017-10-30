#include <iostream>
#include <stdexcept>
#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee( const std::string& a_firstName,
    const std::string& a_lastName, const std::string& a_ssn, double a_weeklySalary)
    : Employee( a_firstName, a_lastName, a_ssn )
{
    setWeeklySalary( a_weeklySalary );
}

double SalariedEmployee::getWeeklySalary() const
{
    return m_weeklySalary;
}

void SalariedEmployee::setWeeklySalary( double a_weeklySalary )
{
    if ( a_weeklySalary >= 0.0 )
        m_weeklySalary = a_weeklySalary;
    else
        throw std::invalid_argument("Weekly salary must be >= 0.0");
}

double SalariedEmployee::earnings() const
{
    return getWeeklySalary();
}

void SalariedEmployee::print() const
{
    std::cout << "\nsalaried employee: ";
    Employee::print(); // reuse abstract base-class print function
    std::cout << "; weekly salary: " << getWeeklySalary();
}
