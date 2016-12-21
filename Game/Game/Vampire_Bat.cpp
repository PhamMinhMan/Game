#include "Vampire_Bat.h"


Vampire_Bat* Vampire_Bat::instance = 0;

void Vampire_Bat::setActive(bool active)
{
	this->active = active;
	if(active)
		timeWait.start();
}

Vampire_Bat::Vampire_Bat()
{
	ay = 0;
	active = false;
	vx = 0;
	timeWait.init(3000);
	timeActivity.init(2000);
}

bool Vampire_Bat::update()
{
	if (!active)
		return false;
	if (!MovableObject::update())
		return false;


	if (right() + dx >= CAMERA->right() || left() + dx <= CAMERA->left())
	{
		dx = 0;
		vx = -vx;
	}

	if (timeWait.onTime && timeWait.atTime())
	{
		vx = VX_VAMPIRE_BAT;
		timeActivity.start();
	}

	if (timeActivity.onTime && timeActivity.atTime())
	{
		timeWait.start();
		vx = 0;
	}

	return true;
}

bool Vampire_Bat::draw()
{
	if (!alive)
		return false;
	if (sprite == 0)
		return false;

	int frameWidth = (sprite->animations[curAnimation].rects[curFrame].right - sprite->animations[curAnimation].rects[curFrame].left);
	int frameHeight = (sprite->animations[curAnimation].rects[curFrame].bottom - sprite->animations[curAnimation].rects[curFrame].top);

	int xView = x - CAMERA->x;
	int yView = y - CAMERA->y - (height - frameHeight) / 2;

	int truc = xView +
		(sprite->animations[curAnimation].rects[curFrame].right - sprite->animations[curAnimation].rects[curFrame].left) / 2;
	xView-= (width - frameWidth) / 2;
	
	D3DXMATRIX mat;
	if (direction != sprite->image->defautDirection)
	{
		/*(-1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		2 * truc, 0, 0, 1)*/
		D3DXMatrixIdentity(&mat);
		mat._11 = -1;
		mat._41 = 2 * truc;
		Graphics::getInstance()->GetSprite()->SetTransform(&mat);
	}
	sprite->draw(xView, yView, curAnimation, curFrame);

	if (direction != sprite->image->defautDirection)
	{
		D3DXMatrixIdentity(&mat);
		Graphics::getInstance()->GetSprite()->SetTransform(&mat);
	}
	return true;
}

void Vampire_Bat::onCollision(GObject * other, int nx, int ny)
{
}


Vampire_Bat::~Vampire_Bat()
{
}
