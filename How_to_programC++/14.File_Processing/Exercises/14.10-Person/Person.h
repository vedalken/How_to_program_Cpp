#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

class Person
{
	friend std::ostream& operator<<( std::ostream &, const Person & );
public:
	Person();
	~Person();

	void setId( int );
	int getId() const;

	void setLastName( const std::string& );
	std::string getLastName() const;

	void setFirstName( const std::string& );
	std::string getFirstName() const;

	void setAge( int );
	int getAge() const;
private:
	int m_id;
	char m_lastName[ 15 ];
	char m_firstName[ 10 ];
	int m_age;
};

#endif
