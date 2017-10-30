#include <iomanip>
#include <stdexcept>
#include "Person.h"

Person::Person()
	: m_id(0),
	  m_lastName("unassigned"),
	  m_firstName(""),
	  m_age(0)
{
}

Person::~Person()
{
}

void Person::setId( int id )
{
	if ( id < 0 ) {
		throw std::out_of_range("Id is negative");
	}

	m_id = id;
}

int Person::getId() const
{
	return m_id;
}

void Person::setLastName( const std::string& lastName )
{
	size_t length = lastName.size();
	size_t len = sizeof( m_lastName );
	length = (length < len ? length : len - 1 );
	lastName.copy( m_lastName, length );
	m_lastName[ length ] = '\0';
}

std::string Person::getLastName() const
{
	return m_lastName;
}

void Person::setFirstName( const std::string& firstName )
{
	size_t length = firstName.size();
	size_t len = sizeof( m_firstName );
	length = (length < len ? length : len - 1 );
	firstName.copy( m_firstName, length );
	m_firstName[ length ] = '\0';
}

std::string Person::getFirstName() const
{
	return m_firstName;
}

void Person::setAge( int age )
{
	if ( age <= 0 ) {
		throw std::out_of_range("Age is zero or negative");
	}

	m_age = age;
}

int Person::getAge() const
{
	return m_age;
}

std::ostream& operator<<( std::ostream& output, const Person &p )
{
	output << std::setw(5) << p.getId()
	       << std::setw(10) << p.getFirstName()
	       << std::setw(15) << p.getLastName()
	       << std::setw(4) << p.getAge();

	return output;
}
