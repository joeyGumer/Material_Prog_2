/*
Class point2D
*/

#ifndef _POINT2D_H_
#define _POINT2D_H_

template <class TYPE>
class cPoint2D
{
public:

	TYPE x, y;

	/*
	operators
	*/
	//gives a new result
	cPoint2D operator + (const cPoint2D& p)
	{
		cPoint2D ret;

		ret.x = x + p.x
		ret.y = y + p.y

		return ret;
	}
	cPoint2D operator - (const cPoint2D& p)
	{
		cPoint2D ret;

		ret.x = x - p.x
		ret.y = y - p.y

		return ret;
	}
	
	//modifies the actual point
	const cPoint2D& operator += (const cPoint2D& p)
	{
		x += p.x;
		y += p.y;

		return(*this);

	}
	const cPoint2D& operator -= (const cPoint2D& p)
	{
		x -= p.x;
		y -= p.y;

		return(*this);
	}
	
	//compares
	bool operator == (const cPoint2D& p)
	{
		return (x == p.x && y == p.y);
	}
	bool operator != (const cPoint2D& p)
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

	TYPE DistanceTo(const cPoint2D& p) const
	{
		TYPE dX = x - p.x;
		TYPE dY = y - p.y;

		return sqrt((dX*dX) + (dY*dY));
	}
};

#endif