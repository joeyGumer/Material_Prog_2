/*
Class point2D
*/

#ifndef _POINT2D_H_
#define _POINT2D_H_

template <class TYPE>
class Point2D
{
public:

	TYPE x, y;

public:
	
	/*
	operators
	*/
	//gives a new result
	Point2D operator + (const Point2D& p)
	{
		Point2D ret;

		ret.x = x + p.x
		ret.y = y + p.y

		return ret;
	}
	Point2D operator - (const Point2D& p)
	{
		Point2D ret;

		ret.x = x - p.x
		ret.y = y - p.y

		return ret;
	}
	
	//modifies the actual point
	const Point2D& operator += (const Point2D& p)
	{
		x += p.x;
		y += p.y;

		return(*this);

	}
	const Point2D& operator -= (const Point2D& p)
	{
		x -= p.x;
		y -= p.y;

		return(*this);
	}
	
	//compares
	bool operator == (const Point2D& p)
	{
		return (x == p.x && y == p.y);
	}
	bool operator != (const Point2D& p)
	{
		return (x != p.x || y != p.y);
	}

	/*
	util methods
	*/

	bool IsZero() const
	{
		return (x == 0 || y == 0);
	}

	void SetZero()
	{
		x = 0;
		y = 0;
	}

	void Negate()
	{
		x = -x;
		y = -y;
	}

	TYPE DistanceTo(const Point2D& p) const
	{
		TYPE dX = x - p.x;
		TYPE dY = y - p.y;

		return sqrt((dX*dX) + (dY*dY));
	}
};

#endif //!_POINT2D