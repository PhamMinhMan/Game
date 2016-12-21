#include "Door.h"
#include"Simon.h"
#include"Stage.h"
Door* Door::curDoor = 0;


Door::Door()
{
	height = 48;
	objectFilter = CF_Gate;
	direction = Left;
	doorUpdate = DA_END;
}

bool Door::update()
{
	switch (doorUpdate)
	{
	case DA_CAMERA_RUN1:
		CAMERA->x++;
		if (CAMERA->xCenter() > xCenter())
		{
			doorUpdate = DA_OPEN_DOOR;
			setAction(DA_OPEN);
		}
		break;
	case DA_OPEN_DOOR:
		GObject::update();/////////////////////////////////////
		if (curFrame == 0)
		{
			doorUpdate = DA_SIMON_RUN;
			curFrame = sprite->animations[curAnimation].nRect-1;
			SIMON->setAction(AS_DI);
		}
		break;
	case DA_SIMON_RUN:
		SIMON->x++;
		SIMON->updateAnimation();
		if (SIMON->right() > CAMERA->x + CAMERA->width * 3 / 4)
		{
			doorUpdate = DA_CLOSE_DOOR;
			setAction(DA_CLOSE);
		}
		break;
	case DA_CLOSE_DOOR:
		GObject::update();
		if (curFrame == 0)
		{
			doorUpdate = DA_CAMERA_RUN2;
			curFrame = sprite->animations[curAnimation].nRect - 1;
			SIMON->setAction(AS_DUNG);
		}
		break;
	case DA_CAMERA_RUN2:
		CAMERA->x++;
		if (CAMERA->left() > Stage::curStage->left())
		{
			doorUpdate = DA_END;
		}
		break;
	case DA_END:
		curDoor = 0;
		break;
	default:
		break;
	}
	return false;
}

void Door::onInterserct(GObject * other)
{
	if (other == SIMON)
	{
		doorUpdate = DA_CAMERA_RUN1;
		if(curDoor==0)
			Stage::curStage = Stage::curListStage->at(Stage::curStage->index + 1);
		curDoor = this;
		SIMON->y = bottom() + SIMON->height;
		SIMON->vy = 0;
		SIMON->dy = 0;
	}
}

void Door::setOldRect()
{
	GObject::setOldRect();
	height = 48;
	oldRect.height = 48;
}


Door::~Door()
{
}
