#include <iostream>
#include <stdexcept>
#include "BasePlusCommissionEmployee.h"

BasePlusCommissionEmployee::BasePlusCommissionEmployee( const std::string& a_firstName,
    const std::string& a_lastName, const std::string& a_ssn, double a_grossSales,
    double a_commissionRate, double a_baseSalary)
    : CommissionEmployee( a_firstName, a_lastName, a_ssn, a_grossSales, a_commissionRate )
{
    setBaseSalary( a_baseSalary );
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
    return m_baseSalary;
}

void BasePlusCommissionEmployee::setBaseSalary( double a_baseSalary )
{
    if ( a_baseSalary >= 0.0 )
        m_baseSalary = a_baseSalary;
    else
        throw std::invalid_argument("Base salary must be >= 0.0");
}

double BasePlusCommissionEmployee::earnings() const
{
    return CommissionEmployee::earnings() + getBaseSalary();
}

void BasePlusCommissionEmployee::print() const
{
    std::cout << "\nbase-salarized: ";
    CommissionEmployee::print();
    std::cout << "; base salary: " << getBaseSalary();
}
