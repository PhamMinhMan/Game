#pragma once
#include "GObject.h"

enum DOOR_UPDATE
{
	DA_CAMERA_RUN1,
	DA_OPEN_DOOR,
	DA_SIMON_RUN,
	DA_CLOSE_DOOR,
	DA_CAMERA_RUN2,
	DA_END
};

enum DOOR_ACTION
{
	DA_BEGIN,
	DA_OPEN,
	DA_CLOSE
};


class Door :
	public GObject
{
public:
	DOOR_UPDATE doorUpdate;
	static Door* curDoor;
	Door();
	bool update();
	void onInterserct(GObject* other);
	void setOldRect();
	~Door();
};

