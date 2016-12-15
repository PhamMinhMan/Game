#pragma once
#include "Enemy.h"
class Panther : public Enemy
{
	static Panther* instance;
public:
	static Panther* getInstance();
	bool update();
	bool draw();
	void onCollision(GObject* other, int nx, int ny);
	Panther();
	~Panther();
};