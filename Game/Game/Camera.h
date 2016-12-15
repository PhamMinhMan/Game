#pragma once
#include "RectF.h"
#include "ObjectsFilter.h"
class Camera :
	public RectF
{
public:
	static Camera* instance;
	static Camera* getInstance();
	void update();
	ObjectsFilter objects;
	void remove();
	Camera();
	~Camera();
};

