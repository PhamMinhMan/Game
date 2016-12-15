#pragma once
#include "MovableObject.h"
class BigFire : public MovableObject
{
	static BigFire* instance;
public:
	static BigFire* getInstance();
	bool update();
	bool draw();
	BigFire();
	~BigFire();
};

