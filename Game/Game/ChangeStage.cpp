#include "ChangeStage.h"
#include"Stage.h"
#include"Simon.h"


void ChangeStage::onInterserct(GObject * other)
{
	if (SIMON->dy > 0 && id == -206 && SIMON->onStair && bottom()> SIMON->bottom())
	{
		SIMON->x = x - 16;
		SIMON->y = bottom() + 24 - SIMON->height;
		SIMON->dx = 0;
		SIMON->dy = 0;
		CAMERA->y = bottom();
		SIMON->curFrame = 0;
		SIMON->atDestination();
	}


	if (SIMON->dy < 0 && id == -106 && SIMON->onStair && bottom()< SIMON->bottom())
	{
		SIMON->x = x;
		SIMON->y = top() - 8 - SIMON->height;
		SIMON->dx = 0;
		SIMON->dy = 0;
		CAMERA->y = bottom() - CAMERA->height;
		SIMON->curFrame = 0;
		SIMON->atDestination();
	}
}

void ChangeStage::onCollision(GObject * other, int nx, int ny)
{
	if (ny == -1)
		SweptAABB::getInstance()->preventMove(other, this);
}

ChangeStage::ChangeStage()
{
	objectFilter = CF_ChangeStage;
}


ChangeStage::~ChangeStage()
{
}
