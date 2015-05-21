#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <math.h>
#define MAXd = 10000;

class Entity {
public:
	int x, y;       //position
	int hp;        //health points
	bool stunned;  //active?
}
//Passar la definicio de les funcions a un cpp
class EntityManager {
public:
	
	float Distance(Entity *u1, Entity *u2);
	
	Entity* GetEnemy()
	{
		float d;
		int life;
		float factor;
		float min = MAXd;
		Entity* enemy = NULL;

		for (int i = 0; i < num_enemies)
		{
			if (!Enemies[i].stunned)
			{
				d = Distance(&Enemies[i], &Player);
				life = abs(Enemies[i].hp, Player.hp);

				if (life == 0)
					factor = MAXd;
				
				factor = d / life;
			}
			if (factor<min)
			{
				min = factor;
				enemy = &Enemies[i]
			}
		}
		return enemy;
	}

	bool Surrender()
	{
		count = 0;

		for (int i = 0; i < num_enemies; i++)
		{
			if (!Enemies[i].stunned)
				count += Enemies[i].hp;
		}

		return (count >= 10 * Player.hp);
	}

private:
	
	Entity Player, *Enemies;
	int num_enemies;
}


#endif