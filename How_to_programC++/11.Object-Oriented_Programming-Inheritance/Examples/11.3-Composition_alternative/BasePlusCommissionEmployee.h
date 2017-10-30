// Commission employee class definition
#ifndef BASE_PLUS_COMMISSION_EMPLOYEE_H
#define BASE_PLUS_COMMISSION_EMPLOYEE_H

#include <string>
#include "CommissionEmployee.h"

class BasePlusCommissionEmployee
{
    public:
        BasePlusCommissionEmployee(
            const std::string& a_firstName,
            const std::string& a_lastName,
            const std::string& a_ssn,
            double a_sales = 0.0,
            double a_rate = 0.0,
            double a_salary = 0.0);

        void setBaseSalery(double);
        inline double getBaseSalery() const { return m_baseSalary; }

        double earnings() const;
        void print() const;

    private:
        double             m_baseSalary;
        CommissionEmployee m_commissionEmployee;
};

#endif

