#include "Stair.h"
#include"Simon.h"
#include"Keyboard.h"

Stair::Stair()
{
	objectFilter = CF_Stair;
}

void Stair::onInterserct(GObject * other)
{
	if (!Keyboard::getInstance()->keyDown && !Keyboard::getInstance()->keyUp)
		return;

	if (id == ST_RightUp && other == SIMON && Keyboard::getInstance()->keyUp && !SIMON->onStair)
	{
		int xDestination = xCenter() - SIMON->width;
		int yDestination = bottom() + SIMON->height;
		SIMON->onStair = true;
		SIMON->initGoStair(xDestination, yDestination, xDestination - SIMON->x, this);
		SIMON->stairDirection = Right;

	}

	//
	if (id == ST_LeftUp && other == SIMON && Keyboard::getInstance()->keyUp && !SIMON->onStair)
	{
		int xDestination = xCenter();
		int yDestination = bottom() + SIMON->height;
		SIMON->onStair = true;
		SIMON->initGoStair(xDestination, yDestination, xDestination - SIMON->x, this);
		SIMON->stairDirection = Left;
		SIMON->direction = Left;
	}

	if (SIMON->onStair && other == SIMON && Keyboard::getInstance()->keyUp)
	{
		SIMON->goUp(this);
	}

	if (SIMON->onStair && other == SIMON && Keyboard::getInstance()->keyDown)
	{
		SIMON->goDown(this);
	}
}

void Stair::onCollision(GObject * other, int nx, int ny)
{

}

Stair::~Stair()
{
}
