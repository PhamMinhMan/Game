#pragma once
#include"GObject.h"
class ChangeStage : public GObject
{
public:

	void onInterserct(GObject* other);

	void onCollision(GObject* other, int nx, int ny);


	ChangeStage();
	~ChangeStage();
};

