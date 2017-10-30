#pragma once

#include <iostream>
#include <string>
#include <vector>

class PermutMatrix
{
	friend std::ostream& operator<<( std::ostream&, const PermutMatrix & );
public:
	PermutMatrix(int rows, int cols);
	~PermutMatrix();
	PermutMatrix& operator=( const PermutMatrix & );
	void init( const std::string& );
private:
	int m_rows;
	int m_cols;
	std::vector<std::vector<std::string>> m_mat;
};
