#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
public:
    Employee( const std::string&, const std::string& );
    ~Employee();
    const std::string& getFirstName() const;
    const std::string& getLastName()  const;

    // static member function
    static unsigned int getCount();
private:
    std::string m_firstName;
    std::string m_lastName;

    // number of objects instantiated
    static unsigned int count;
};

#endif
