#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h"

class Employee
{
public:
	Employee(const std::string& first, const std::string& last,
			const Date& birth, const Date& hire);
	void print() const;
	~Employee();
private:
	std::string m_firstName;
	std::string m_lastName;
	const Date m_birthDate;
	const Date m_hireDate;
};

#endif
