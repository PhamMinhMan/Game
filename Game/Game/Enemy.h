#pragma once
#include "MovableObject.h"
class Enemy :
	public MovableObject
{
public:
	/*bool update();
	bool draw();*/
	virtual void onInterserct(GObject* other);
	Enemy();
	~Enemy();
};
