#pragma once

#include"MovableObject.h"
#include "Stair.h"
#include "Whip.h"


class Simon : public MovableObject
{
	static Simon* instance;
public:
	Whip* whip;
	static Simon* getInstance();
	bool update();
	bool draw();

	bool onGround;

#pragma region Stair

	bool onStair;
	void updateStair();


	bool onGoing;
	void updateGoing();

	int xDestination, yDestination;
	Stair* stair;

	//khoi tao chay
	void initGoStair(int xDestination, int yDestination, float duration, Stair* stair);
	//chay toi dich
	void atDestination();

	void onEndAnimation();


	void goUp(Stair* stair);
	void goDown(Stair* stair);
	void onCollision(GObject* other, int nx, int ny);

	DIRECTION stairDirection;


#pragma endregion


#pragma region Attack

	bool onAttack;

#pragma endregion


	Simon();
	~Simon();
};

