#ifndef SALARIED_EMPLOYEE_H
#define SALARIED_EMPLOYEE_H

#include "Employee.h"

class SalariedEmployee : public Employee
{
    public:
        SalariedEmployee( const std::string& a_firstName, const std::string& a_lastName,
            const std::string& a_ssn, double a_weeklySalary = 0.0 );

        virtual ~SalariedEmployee() {}

        double getWeeklySalary() const;
        void setWeeklySalary( double );

        virtual double earnings() const override;
        virtual void print() const override;
    private:
        double m_weeklySalary;
};

#endif
