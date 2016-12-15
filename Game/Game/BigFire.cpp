#include "BigFire.h"

BigFire * BigFire::instance = 0;
BigFire * BigFire::getInstance()
{
	if (instance == 0)
		instance = new BigFire();
	return instance;
}

bool BigFire::update()
{
	if (!MovableObject::update())
		return false;
	return true;
}

bool BigFire::draw()
{
	if (MovableObject::draw())
	{
		return true;
	}
	return false;
}

BigFire::BigFire()
{
	objectFilter = CF_CandleLarge;
	ay = 0;
}

BigFire::~BigFire()
{
}
