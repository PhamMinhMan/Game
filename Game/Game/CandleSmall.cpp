#include "CandleSmall.h"


CandleSmall * CandleSmall::instance = 0;
CandleSmall * CandleSmall::getInstance()
{
	if (instance==0)
	{
		instance = new CandleSmall();
	}
	return instance;
}

bool CandleSmall::update()
{
	if (!MovableObject::update())
		return false;
	return true;
}

bool CandleSmall::draw()
{
	if (MovableObject::draw())
	{
		return true;
	}
	return false;
}

CandleSmall::CandleSmall()
{
	objectFilter = CF_CandleSmall;
	ay = 0;
}


CandleSmall::~CandleSmall()
{
}
