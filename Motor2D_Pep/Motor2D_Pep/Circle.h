#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Point2D.h"

template <class TYPE>
class Circle
{
public:
	TYPE radius;
	Point2D<TYPE> center;

public:
	
	Circle(const TYPE& x, const TYPE& y, const TYPE& r)
	{
		radius = r;
		center.x = x;
		center.y = y;
	}

	TYPE GetArea()const
	{
		return 3.1415*radius*radius;
	}

	bool Intersects(const Circle& c) const
	{
		if (radius + c.radius > center.DistanceTo(c.center))
			return true;

		return false;
	}

};

#endif