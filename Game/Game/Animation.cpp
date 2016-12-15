#include "Animation.h"



void Animation::update(int& curFrame, GameTime& delay)
{
	//if (delay.atTime())
	//{
		curFrame++;
		if (curFrame == nRect)
			curFrame = 0;
	//}
}

Animation::Animation()
{
}


Animation::~Animation()
{
}
