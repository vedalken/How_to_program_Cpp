#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "Point3d.h"

class Vector3d
{
private:
	double m_x;
	double m_y;
	double m_z;
public:
	Vector3d(double = 0, double = 0, double = 0);
	void print() const;
	friend void Point3d::moveByVector3d(const Vector3d &);
};
#endif
