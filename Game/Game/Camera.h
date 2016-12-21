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

	void convertToRenderPos(float x, float y, float& renderX, float& renderY);

	void remove();
	Camera();
	~Camera();
};

