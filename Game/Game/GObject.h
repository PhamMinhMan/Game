#pragma once
#include"Texture.h"
#include"RectF.h"
#include"Sprite.h"
#include"Keyboard.h"
#include"GameTime.h"
#include"Camera.h"
#include"SpriteManager.h"
#include"SweptAABB.h"

class GObject : public RectF
{
public:

	bool alive;
	int curFrame;
	GameTime delay;
	int curAnimation;
	Sprite* sprite;
	int id; // id trong map
	DIRECTION direction;
	COLLISION_FILTER objectFilter;
	bool pauseAnimation;

	virtual bool update();
	virtual bool draw();
	virtual void updateLocation();

	virtual void onCollision(GObject* other, int nx, int ny);
	virtual void onInterserct(GObject* other);

	void updateAnimation();

	virtual void setAction(int action);

	virtual void onEndAnimation();

	bool coVaChamCheo;
	bool biDoiVanToc;
	RectF oldRect;
	virtual void setOldRect();
	void restore();// khoi phuc vi tri ban dau
	GObject();
	~GObject();
};

