#include "Zombie.h"


Zombie * Zombie::instance = 0;
Zombie * Zombie::getInstance()
{
	if (instance ==0)
	{
		instance = new Zombie();
	}
	return instance;
}

bool Zombie::update()
{
	if (!MovableObject::update())
		return false;
	return true;
}

bool Zombie::draw()
{
	if (MovableObject::draw())
	{
		return true;
	}
	return false;
}

void Zombie::onCollision(GObject * other, int nx, int ny)
{
	Enemy::onCollision(other, nx, ny);
	if (other->objectFilter == CF_Ground && nx!=0)
	{
		vx = 0.3*nx;
		direction = (DIRECTION)nx;
	}
}

Zombie::Zombie()
{
	vx = 0.01;
}


Zombie::~Zombie()
{
}
