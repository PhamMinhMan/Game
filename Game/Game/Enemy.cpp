#include "Enemy.h"

#include"Simon.h"

//bool Enemy::update()
//{
//	return false;
//}
//
//bool Enemy::draw()
//{
//	return false;
//}

void Enemy::onInterserct(GObject * other)
{
	if (other == SIMON->whip && SIMON->onAttack && SIMON->whip->curFrame==2)
	{
		this->alive = false;
	}
	if (other==SIMON)
	{
		SIMON->setAction(AS_LUI);
		SIMON->vy = -0.05;
		if (SIMON->xCenter() < xCenter())
			SIMON->vx = -0.1;
		else
			SIMON->vx = 0.1;

	}
}

Enemy::Enemy()
{
	objectFilter = CF_Enemy;
}


Enemy::~Enemy()
{
}
