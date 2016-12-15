#pragma once
#include"GObject.h"

enum STAIR_TYPE
{
	ST_Normal=-2,
	ST_RightUp = -102,
	ST_LeftDown= -302,
	ST_LeftDownPrevent = -202,
	ST_LeftUp = -502,
	ST_RightDown = -702,
	ST_RightDownPrevent = -602
};

class Stair : public GObject
{
public:
	Stair();
	void onInterserct(GObject* other);
	void onCollision(GObject* other, int nx, int ny);
	~Stair();
};

