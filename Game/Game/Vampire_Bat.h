#pragma once
#include "Enemy.h"
#define VX_VAMPIRE_BAT 0.1;
#include"GameTime.h"

class Vampire_Bat :
	public Enemy
{
public:

	GameTime timeWait;
	GameTime timeActivity;

	static Vampire_Bat* instance;

	bool active;

	void setActive(bool active);


	Vampire_Bat();
	bool update();
	bool draw();
	void onCollision(GObject* other, int nx, int ny);
	~Vampire_Bat();
};

