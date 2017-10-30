#ifndef PHONE_H
#define PHONE_H
#include <iostream>
#include <string>

class Phone
{
	friend std::istream& operator>>( std::istream &, Phone & );
	friend std::ostream& operator<<( std::ostream &, const Phone & );
public:
	Phone();
	Phone( const std::string & );
	~Phone();
	bool setNumber( const std::string & );
	const std::string& getNumber() const;

	// word generator
	void wordGenerator() const;
private:
	std::string m_number;
};

#endif
