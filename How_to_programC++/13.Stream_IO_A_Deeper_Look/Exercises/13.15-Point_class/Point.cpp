#include "Point.h"

Point::Point( double x, double y )
    : m_x( x ),
      m_y( y )
{
}

Point::Point()
    : Point(0, 0)
{
}

std::ostream& operator<<( std::ostream& output, const Point& point )
{
    output << "(" << point.m_x << "," << point.m_y << ")";
    return output; 
}

std::istream& operator>>( std::istream& input, Point& point )
{
    double x, y;
    input >> x >> y;

    if ( (input.rdstate() & input.failbit) != 0 )
    {
        input.clear( std::ios_base::failbit );
        return input;
    }

    point.m_x = x;
    point.m_y = y;

    return input;
}
