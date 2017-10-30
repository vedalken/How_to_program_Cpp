#include <iostream>
#include "Point3d.h"
#include "Vector3d.h"

int main()
{
	Vector3d vec(2.0,1.0,0.0);
	Point3d point(1.0,1.0,0.0);

	std::cout << "Point: ";
	point.print();
	point.moveByVector3d(vec);
	std::cout << "Move point by vector: ";
	vec.print();
	std::cout << "New point: ";
	point.print();

	return 0;
}
