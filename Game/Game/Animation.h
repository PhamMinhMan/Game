#pragma once
#include<Windows.h>
#include"GameTime.h"
#include "RectF.h"
class Animation
{
public:
	RECT* rects;
	int nRect;//frame

	void update(int& curFrame,GameTime& delay);//next

	Animation();
	~Animation();
};

