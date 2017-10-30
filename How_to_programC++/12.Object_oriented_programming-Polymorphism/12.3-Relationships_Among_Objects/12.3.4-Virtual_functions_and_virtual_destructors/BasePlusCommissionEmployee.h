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

        virtual ~BasePlusCommissionEmployee() {}

        void setBaseSalery(double);
        inline double getBaseSalery() const { return m_baseSalary; }

        virtual double earnings() const override;
        virtual void   print()    const override;

    private:
        double      m_baseSalary;
};

#endif

