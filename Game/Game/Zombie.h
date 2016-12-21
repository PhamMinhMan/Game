#pragma once
#include "Enemy.h"
class Zombie : public Enemy
{
public:
	bool update();
	bool draw();
	void onCollision(GObject* other, int nx, int ny);
	Zombie();
	~Zombie();
};

