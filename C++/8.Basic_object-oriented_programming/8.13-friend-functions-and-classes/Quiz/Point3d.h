#ifndef POINT3D_H
#define POINT3D_H

// forward declaration
class Vector3d;

class Point3d
{
private:
	double m_x;
	double m_y;
	double m_z;
public:
	Point3d(double = 0, double = 0, double = 0);
	void print() const;
	void moveByVector3d(const Vector3d &);
};

#endif
