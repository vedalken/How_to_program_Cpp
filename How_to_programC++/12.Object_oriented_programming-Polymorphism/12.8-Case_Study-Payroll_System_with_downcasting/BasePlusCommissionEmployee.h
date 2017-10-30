#ifndef BASE_PLUS_COMMISSION_EMPLOYEE_H
#define BASE_PLUS_COMMISSION_EMPLOYEE_H

#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee
{
    public:
        BasePlusCommissionEmployee( const std::string& a_firstName,
            const std::string& a_lastName, const std::string& a_ssn,
            double a_grossSales = 0.0, double a_commissionRate = 0.0,
            double a_baseSalary = 0.0);

        virtual ~BasePlusCommissionEmployee() {}

        double getBaseSalary() const;
        void setBaseSalary( double );

        virtual double earnings() const override;
        virtual void print() const override;
    private:
        double m_baseSalary; // base salary per week
};

#endif
