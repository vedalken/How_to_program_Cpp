#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
    friend std::ostream& operator<<( std::ostream & , const Point & );
    friend std::istream& operator>>( std::istream & , Point & );
    public:
        Point();
        Point(double, double);
    private:
        double m_x;
        double m_y;
};

#endif
