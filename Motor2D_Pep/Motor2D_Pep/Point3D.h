#ifndef _POINT3D_H_
#define _POINT3D_H_

template <class TYPE>
class Point3D
{
public:
	Point3D operator + (const Point3D p)
	{
		Point3D ret;

		ret.x = x + p.x;
		ret.y = y + p.y;
		ret.z = z + p.z;

		return ret;
	}
	Point3D operator - (const Point3D p)
	{
		Point3D ret;

		ret.x = x - p.x;
		ret.y = y - p.y;
		ret.z = z - p.z;

		return ret;
	}

	const Point3D& operator += (const Point3D p)
	{
		x += p.x;
		y += p.y;
		z += p.z;

		return (*this);
	}
	const Point3D& operator -= (const Point3D p)
	{
		x -= p.x;
		y -= p.y;
		z -= p.z;

		return (*this);
	}

	bool operator == (const Point3D p)
	{
		return(x == p.x && y == p.y && z == p.z);
	}
	bool operator != (const Point3D p)
	{
		return(x != p.x || y != p.y || z != p.z);
	}

	bool IsZero() const
	{
		return(x == 0 && y == 0 && z == p.z);
	}

	void SetZero()
	{
		x = y = z = 0;
	}

	void Negate()
	{
		x = -x;
		y = -y;
		z = -z;
	}

	TYPE DistanceTo(const Point3D p) const
	{
		TYPE dX = p.x - x, dY = p.y - y, dZ = p.z - z;
		
		return sqrt((dX*dX) + (dY*dY) + (dZ*dZ));
	}
public: 
	TYPE x, y, z;

};
#endif _POINT3D_H_