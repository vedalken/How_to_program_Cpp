#pragma once
#include <string>
#include <fstream>
#include <vector>

class PhishingScanner
{
public:
	PhishingScanner( const std::string a_databaseName = "database.dat" );
	~PhishingScanner();

	bool scan( std::ifstream &a_data );
	void report() const;
private:
	bool _initReportDatabase();

	mutable std::ifstream m_database;
	std::vector<int> m_reportDatabase;
};
