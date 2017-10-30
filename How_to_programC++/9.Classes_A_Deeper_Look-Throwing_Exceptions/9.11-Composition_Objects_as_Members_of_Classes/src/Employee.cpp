#include <iostream>
#include <string>
#include "Date.h"
#include "Employee.h"

Employee::Employee(const std::string& firstName, const std::string& lastName,
		const Date& birthDate, const Date& hireDate)
	: m_firstName(firstName), 
	  m_lastName(lastName), 
	  m_birthDate(birthDate),
	  m_hireDate(hireDate)
{
	std::cout << "Employee object constructor: "
		<< firstName << " " << lastName << std::endl;
}


// print Employee object
void Employee::print() const
{
	std::cout << m_firstName << " " << m_lastName;
	std::cout << " Hired: ";
	m_hireDate.print();
	std::cout << " Birthday: ";
	m_birthDate.print();
	std::cout << '\n';
}


// Employee destructor object
Employee::~Employee()
{
	std::cout << "Employee destructor called: "
		<< m_firstName << ", " << m_lastName << std::endl;
}
