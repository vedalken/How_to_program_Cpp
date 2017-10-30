#pragma once
#include <string>
#include <fstream>

class Email
{
public:
	Email( const std::string& a_fileName );
	~Email();

	void phishingScan() const;
private:
	mutable std::ifstream m_data;
};
