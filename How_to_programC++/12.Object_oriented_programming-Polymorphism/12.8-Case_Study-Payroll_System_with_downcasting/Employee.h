#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
    public:
        Employee(const std::string& a_firstName, const std::string& a_lastName,
                 const std::string& a_ssn);

        virtual ~Employee() {}

        const std::string& getFirstName() const;
        void setFirstName( const std::string& );

        const std::string& getLastName() const;
        void setLastName( const std::string& );

        const std::string& getSsn() const;
        void setSsn( const std::string& );

        virtual double earnings() const = 0;
        virtual void print() const;

    private:
        std::string m_firstName;
        std::string m_lastName;
        std::string m_ssn; // social security number     
};

#endif
