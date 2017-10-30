#include <iostream>
#include <stdexcept>
#include "BasePlusCommissionEmployee.h"

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
        const std::string& a_firstName,
        const std::string& a_lastName,
        const std::string& a_ssn,
        double a_sales,
        double a_rate,
        double a_salary)
{
    setFirstName(a_firstName);
    setLastName(a_lastName);
    setSocialSecurityNumber(a_ssn);
    setGrossSales(a_sales);
    setCommissionRate(a_rate);
    setBaseSalery(a_salary);
}

void BasePlusCommissionEmployee::setFirstName(const std::string& a_firstName)
{
    m_firstName = a_firstName; // should validate
}

const std::string& BasePlusCommissionEmployee::getFirstName() const
{
    return m_firstName;
}

void BasePlusCommissionEmployee::setLastName(const std::string& a_lastName)
{
    m_lastName = a_lastName; // should validate
}

const std::string& BasePlusCommissionEmployee::getLastName() const
{
    return m_lastName;
}

void BasePlusCommissionEmployee::setSocialSecurityNumber(const std::string& a_ssn)
{
    m_socialSecurityNumber = a_ssn; // should validate
}

const std::string& BasePlusCommissionEmployee::getSocialSecurityNumber() const
{
    return m_socialSecurityNumber;
}

void BasePlusCommissionEmployee::setGrossSales(double a_sales)
{
    if ( a_sales >= 0.0 )
        m_grossSales = a_sales;
    else
        throw std::invalid_argument("Gross sales must be >= 0.0");
}

double BasePlusCommissionEmployee::getGrossSales() const
{
    return m_grossSales;
}

void BasePlusCommissionEmployee::setCommissionRate(double a_rate)
{
    if (a_rate > 0.0 && a_rate < 1.0)
        m_commissionRate = a_rate;
    else
        throw std::invalid_argument("Commission rate must be within (0.0, 1.0)");
}

double BasePlusCommissionEmployee::getCommissionRate() const
{
    return m_commissionRate;
}

void BasePlusCommissionEmployee::setBaseSalery(double a_salary)
{
    if (a_salary >= 0.0)
        m_baseSalary = a_salary;
    else
        throw std::invalid_argument("Base salery must be >= 0.0");
}

double BasePlusCommissionEmployee::getBaseSalery() const
{
    return m_baseSalary;
}

double BasePlusCommissionEmployee::earnings() const
{
    return m_baseSalary + (m_grossSales * m_commissionRate);
}

void BasePlusCommissionEmployee::print() const
{
    std::cout << "commission employee: " << m_firstName << ' ' << m_lastName
        << "\nsocial security number: " << m_socialSecurityNumber
        << "\ngross sales: " << m_grossSales
        << "\ncommission rate: " << m_commissionRate
        << "\nbase salary: " << m_baseSalary;
}
