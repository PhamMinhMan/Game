#pragma once
#include "Enemy.h"
class Zombie : public Enemy
{
	static Zombie* instance;
public:
	static Zombie* getInstance();
	bool update();
	bool draw();
	void onCollision(GObject* other, int nx, int ny);
	Zombie();
	~Zombie();
};

