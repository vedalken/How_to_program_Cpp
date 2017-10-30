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

        virtual ~CommissionEmployee() {}

        void setFirstName(const std::string& );
        inline const std::string& getFirstName() const { return m_firstName; }

        void setLastName(const std::string& );
        inline const std::string& getLastName() const { return m_lastName; }

        void setSocialSecurityNumber(const std::string& );
        inline const std::string& getSocialSecurityNumber() const { return m_socialSecurityNumber; }

        void setGrossSales(double);
        inline double getGrossSales() const { return m_grossSales; }

        void setCommissionRate(double);
        inline double getCommissionRate() const { return m_commissionRate; }

        virtual double earnings() const;
        virtual void print() const;

    private:
        std::string m_firstName;
        std::string m_lastName;
        std::string m_socialSecurityNumber;
        double      m_grossSales;
        double      m_commissionRate;
};

#endif

