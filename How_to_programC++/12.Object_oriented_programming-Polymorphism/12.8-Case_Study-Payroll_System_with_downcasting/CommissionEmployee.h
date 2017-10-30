#ifndef COMMISSION_EMPLOYEE_H
#define COMMISSION_EMPLOYEE_H

#include "Employee.h"

class CommissionEmployee : public Employee
{
    public:
        CommissionEmployee( const std::string& a_firstName,
            const std::string& a_lastName, const std::string& a_ssn,
            double a_grossSales = 0.0, double a_commissionRate = 0.0 );

        virtual ~CommissionEmployee() {}

        double getGrossSales() const;
        void setGrossSales( double );

        double getCommissionRate() const;
        void setCommissionRate( double );

        virtual double earnings() const override;
        virtual void print() const override;
    private:
        double m_grossSales;
        double m_commissionRate;
};

#endif
