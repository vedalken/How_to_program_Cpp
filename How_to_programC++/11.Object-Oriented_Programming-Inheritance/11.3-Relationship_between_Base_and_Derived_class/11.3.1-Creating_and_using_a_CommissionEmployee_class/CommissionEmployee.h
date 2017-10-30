// Commission employee class definition
#ifndef COMMISSION_EMPLOYEE_H
#define COMMISSION_EMPLOYEE_H

#include <string>

class CommissionEmployee
{
    public:
        CommissionEmployee(const std::string&, 
                           const std::string&,
                           const std::string&,
                           double = 0.0,
                           double = 0.0);

        void setFirstName(const std::string& );
        const std::string& getFirstName() const;

        void setLastName(const std::string& );
        const std::string& getLastName() const;

        void setSocialSecurityNumber(const std::string& );
        const std::string& getSocialSecurityNumber() const;

        void setGrossSales(double);
        double getGrossSales() const;

        void setCommissionRate(double);
        double getCommissionRate() const;

        double earnings() const;
        void print() const;

    private:
        std::string m_firstName;
        std::string m_lastName;
        std::string m_socialSecurityNumber;
        double      m_grossSales;
        double      m_commissionRate;
};

#endif

