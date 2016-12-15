#pragma once
#include<Windows.h>
class RectF
{
public:

	void init(float x, float y, float width, float height);

	float x, y, width, height;
	float dx, dy, vx, vy, ay;

	int left();
	int right();
	int top();
	int bottom();

	float xCenter();
	float yCenter();

	RECT toRECT();

	RectF();
	~RectF();
};

