#ifndef __ENEMY_OSCILATOR_H__
#define __ENEMY_OSCILATOR_H__

#include "Enemy.h"

class Enemy_Oscilator : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up=true;
	int original_y = SCREEN_HEIGHT/2;
	Animation Oscilator;

public:

	Enemy_Oscilator(int x, POWERUP_TYPE pu_t);
	void Move();
};

#endif // __ENEMY_OSCILATOR_H__
