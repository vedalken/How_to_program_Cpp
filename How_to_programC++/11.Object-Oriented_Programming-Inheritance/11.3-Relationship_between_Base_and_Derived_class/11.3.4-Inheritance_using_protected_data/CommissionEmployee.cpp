#include <iostream>
#include <stdexcept>
#include "CommissionEmployee.h"

CommissionEmployee::CommissionEmployee(
        const std::string& a_firstName,
        const std::string& a_lastName,
        const std::string& a_ssn,
        double a_sales,
        double a_rate)
{
    m_firstName = a_firstName;
    m_lastName = a_lastName;
    setSocialSecurityNumber(a_ssn);
    setGrossSales(a_sales);
    setCommissionRate(a_rate);
}

void CommissionEmployee::setFirstName(const std::string& a_firstName)
{
    m_firstName = a_firstName; // should validate
}

void CommissionEmployee::setLastName(const std::string& a_lastName)
{
    m_lastName = a_lastName; // should validate
}

void CommissionEmployee::setSocialSecurityNumber(const std::string& a_ssn)
{
    m_socialSecurityNumber = a_ssn; // should validate
}

void CommissionEmployee::setGrossSales(double a_sales)
{
    if ( a_sales >= 0.0 )
        m_grossSales = a_sales;
    else
        throw std::invalid_argument("Gross sales must be >= 0.0");
}

void CommissionEmployee::setCommissionRate(double a_rate)
{
    if (a_rate > 0.0 && a_rate < 1.0)
        m_commissionRate = a_rate;
    else
        throw std::invalid_argument("Commission rate must be within (0.0, 1.0)");
}

double CommissionEmployee::earnings() const
{
    return m_grossSales * m_commissionRate;
}

void CommissionEmployee::print() const
{
    std::cout << "commission employee: " << m_firstName << ' ' << m_lastName
        << "\nsocial security number: " << m_socialSecurityNumber
        << "\ngross sales: " << m_grossSales
        << "\ncommission rate: " << m_commissionRate;
}
