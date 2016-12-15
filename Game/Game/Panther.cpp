#include "Panther.h"

Panther * Panther::instance = 0;
Panther * Panther::getInstance()
{
	if (instance==0)
	{
		instance = new Panther();
	}
	return instance;
}

bool Panther::update()
{
	if (!MovableObject::update())
		return false;
	return true;
}

bool Panther::draw()
{
	if (MovableObject::draw())
	{
		return true;
	}
	return false;
}

void Panther::onCollision(GObject * other, int nx, int ny)
{
	Enemy::onCollision(other, nx, ny);
	//if (other->objectFilter == CF_Ground && nx != 0)
	//{
	//	direction = (DIRECTION)nx;
	//}
	//if (other->objectFilter == CF_Ground && ny == -1)
	//{
	//	vy = -0.07;
	//	vx = 0.3*direction;
	//}
}

Panther::Panther()
{
}

Panther::~Panther()
{
}
