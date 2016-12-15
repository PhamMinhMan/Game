#pragma once
#include "MovableObject.h"

struct Point
{
	int X, Y;

	void init(int x, int y)
	{
		X = x;
		Y = y;
	}
	Point(int x, int y)
	{
		this->X = x;
		this->Y = y;
	}
	Point()
	{
	}
};

class Whip :
	public MovableObject
{
public:

	static Point* whipLocations;

	static Point* getWhipLocations();

	static Point getCurPoint();

	bool draw();

	Whip();
	~Whip();
};
