#include "Whip.h"
#include"Simon.h"

Point * Whip::whipLocations = 0;

Point * Whip::getWhipLocations()
{
	if (whipLocations == 0)
	{
		whipLocations = new Point[3];
		whipLocations[0].init(24, 7);
		whipLocations[1].init(17, 5);
		whipLocations[2].init(0, 14);
	}
	return whipLocations;
}

Point Whip::getCurPoint()
{
	return getWhipLocations()[SIMON->curFrame];
}

bool Whip::draw()
{
	curFrame = Simon::getInstance()->curFrame;
	Point curPoint = getCurPoint();
	x = Simon::getInstance()->x + curPoint.X;
	y = Simon::getInstance()->y + curPoint.Y;
	if (curFrame == 2)
	{
		x -= width;
		y -= height;
	}

	 MovableObject::draw();

	if (SIMON->direction == Right)
	{
		x += (width + SIMON->width);
	}

	return true;

}

Whip::Whip()
{
	sprite = &SpriteManager::getInstance()->sprites[SPR_WHIP];
	direction = Left;

	width = sprite->animations[curAnimation].rects[2].right - sprite->animations[curAnimation].rects[2].left;
	height = sprite->animations[curAnimation].rects[2].bottom - sprite->animations[curAnimation].rects[2].top;

}

Whip::~Whip()
{
}
