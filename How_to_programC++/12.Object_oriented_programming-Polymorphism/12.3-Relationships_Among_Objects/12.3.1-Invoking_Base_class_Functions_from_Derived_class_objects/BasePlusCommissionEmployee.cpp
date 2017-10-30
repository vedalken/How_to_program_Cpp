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
    // explicity call base-class constructor
    : CommissionEmployee(a_firstName, a_lastName, a_ssn, a_sales, a_rate)
{
    setBaseSalery(a_salary);
}

void BasePlusCommissionEmployee::setBaseSalery(double a_salary)
{
    if (a_salary >= 0.0)
        m_baseSalary = a_salary;
    else
        throw std::invalid_argument("Base salery must be >= 0.0");
}

double BasePlusCommissionEmployee::earnings() const
{
    return m_baseSalary + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const
{
    std::cout << "base-salaried: ";

    // invoke CommissionEmployee's print function
    CommissionEmployee::print();

    std::cout << "\nbase salary: " << getBaseSalery();
}
