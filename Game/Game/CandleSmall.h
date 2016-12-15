#pragma once
#include "MovableObject.h"
class CandleSmall :
	public MovableObject
{
	static CandleSmall* instance;
public:
	static CandleSmall* getInstance();
	bool update();
	bool draw();
	CandleSmall();
	~CandleSmall();
};

