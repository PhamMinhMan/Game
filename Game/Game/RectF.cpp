#include "RectF.h"



void RectF::init(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

int RectF::left()
{
	return x;
}

int RectF::right()
{
	return x+width;
}

int RectF::top()
{
	return y;
}

int RectF::bottom()
{
	return y-height;
}

float RectF::xCenter()
{
	return x + width / 2;
}

float RectF::yCenter()
{
	return y - height / 2;
}

RECT RectF::toRECT()// tra ra 1 kieu RECT cua window tu bien RectF
{
	RECT r;
	SetRect(&r, left(), right(), top(), bottom());
	return r;
}

RectF::RectF()
{
	dx = dy = vy = ay = vx = 0;
}


RectF::~RectF()
{
}
