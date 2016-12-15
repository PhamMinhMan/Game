#pragma once
#include "GObject.h"
class MovableObject : public GObject
{
public:
	virtual bool update();
	virtual bool draw();
	
	MovableObject();
	~MovableObject();
};

