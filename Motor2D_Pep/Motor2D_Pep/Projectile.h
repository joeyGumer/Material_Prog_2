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
	cPoint2D<float> point;
	cPoint2D<float> speed;
	

	//methods
	cPoint2D<float> GetCurrentPosition(const float time)const
	{
		cPoint2D<float> ret = point;
		
		ret.x += speed.x * time;
		ret.y += speed.y * time;

		return ret;
	}
};

#endif // !_PROJECTILE_H_
