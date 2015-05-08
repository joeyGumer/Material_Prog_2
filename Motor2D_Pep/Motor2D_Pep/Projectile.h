/*
Class Projectile
*/

#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "Point2D.h"

class Projectile
{
public:
	//attributes
	Point2D<float> point;
	Point2D<float> speed;
	

	//methods
	Point2D<float> GetCurrentPosition(const float time)const
	{
		Point2D<float> ret = point;
		
		ret.x += speed.x * time;
		ret.y += speed.y * time;

		return ret;
	}
};

#endif // !_PROJECTILE_H_
