#include <iostream>
#include <stdexcept>
#include "CommissionEmployee.h"

CommissionEmployee::CommissionEmployee( const std::string& a_firstName,
    const std::string& a_lastName, const std::string& a_ssn,
    double a_grossSales, double a_commissionRate)
    : Employee( a_firstName, a_lastName, a_ssn )
{
    setGrossSales( a_grossSales );
    setCommissionRate( a_commissionRate );
}

double CommissionEmployee::getGrossSales() const
{
    return m_grossSales;
}

void CommissionEmployee::setGrossSales( double a_grossSales )
{
    if ( a_grossSales >= 0.0 )
        m_grossSales = a_grossSales;
    else
        throw std::invalid_argument("Gross sales must be >= 0.0");
}

double CommissionEmployee::getCommissionRate() const
{
    return m_commissionRate;
}

void CommissionEmployee::setCommissionRate( double a_commissionRate )
{
    if ( a_commissionRate > 0.0 && a_commissionRate < 1.0)
        m_commissionRate = a_commissionRate;
    else
        throw std::invalid_argument("Commission rate must be > 0.0 and < 1.0");
}

double CommissionEmployee::earnings() const
{
    return getCommissionRate() *getGrossSales() ;
}

void CommissionEmployee::print() const
{
    std::cout << "\ncommission employee: ";
    Employee::print(); // abstract base-class call print function
    std::cout << "; gross sales: " << getGrossSales()
        << "; commission rate: " << getCommissionRate();
}
