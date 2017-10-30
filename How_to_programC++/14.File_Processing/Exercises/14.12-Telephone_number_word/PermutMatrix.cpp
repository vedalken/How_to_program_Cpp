#include <stdexcept>
#include "PermutMatrix.h"

PermutMatrix::PermutMatrix(int rows, int cols)
	: m_rows(rows),
	  m_cols(cols),
	  m_mat{}
{
}

PermutMatrix::~PermutMatrix()
{
}

PermutMatrix& PermutMatrix::operator=( const PermutMatrix &mat )
{
	if (mat.m_rows <= 0 || mat.m_cols <= 0 )
		throw std::out_of_range("Rows or columns are not positive");

	// prevent self-assignment
	if ( this != &mat )
	{	
		if (mat.m_rows != m_rows) m_rows = mat.m_rows;
		if (mat.m_cols != m_cols) m_cols = mat.m_rows;

		for (int row = 0; row < m_rows; ++row)
		{
			for (int col = 0; col < m_cols; ++col)
				m_mat[row][col] = mat.m_mat[row][col];
		}
	}

	return *this;
}

void PermutMatrix::init( const std::string &init )
{
	for (int row = 0; row < m_rows; ++row)
	{
		std::vector<std::string> tmp;
		for (int col = 0; col < m_cols; ++col)
			tmp.push_back( init );

		m_mat.push_back(tmp);
	}

}

std::ostream& operator<<( std::ostream& output, const PermutMatrix& mat)
{
	for (int row = 0; row < mat.m_rows; ++row)
	{
		for (int col = 0; col < mat.m_cols; ++col) {
			output << mat.m_mat[row][col] << ' ';
		}
		output << '\n';
	}

	return output;
}
