// Commission employee class definition
#ifndef BASE_PLUS_COMMISSION_EMPLOYEE_H
#define BASE_PLUS_COMMISSION_EMPLOYEE_H

#include <string>
#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee
{
    public:
        BasePlusCommissionEmployee(const std::string&, const std::string&, const std::string&,
            double = 0.0, double = 0.0, double = 0.0);

        void setBaseSalery(double);
        double getBaseSalery() const;

        double earnings() const;
        void print() const;

    private:
        double      m_baseSalary;
};

#endif

