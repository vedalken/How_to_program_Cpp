#include <iostream>
#include "Point3d.h"
#include "Vector3d.h"

Point3d::Point3d(double x, double y, double z)
	: m_x(x), m_y(y), m_z(z)
{
}

void Point3d::print() const
{
	std::cout << "(" << m_x << ", " << m_y << ", " 
		<< m_z << ")" << std::endl;
}

void Point3d::moveByVector3d(const Vector3d &vec)
{
	m_x += vec.m_x;
	m_y += vec.m_y;
	m_z += vec.m_z;
}
