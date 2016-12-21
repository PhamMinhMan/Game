#include "Camera.h"
#include"Config.h"
#include"Simon.h"
#include "Stage.h"

#include"Vampire_Bat.h"


Camera * Camera::instance = 0;

Camera * Camera::getInstance()
{
	if (instance == 0)
		instance = new Camera();
	return instance;
}

void Camera::update()
{
	dx = 0;
	if (SIMON->x + SIMON->dx < x && SIMON->dx < 0)
	{
		SIMON->x = x;
		SIMON->dx = 0;
	}

	if (SIMON->right() + SIMON->dx > right() && SIMON->dx > 0)
	{
		SIMON->x = right() - SIMON->width;
		SIMON->dx = 0;
	}

	if ((SIMON->xCenter() + SIMON->dx > this->xCenter() && SIMON->dx > 0) ||
		(SIMON->xCenter() + SIMON->dx < this->xCenter() && SIMON->dx < 0))
	{
		dx = SIMON->dx;
	}


	if (x + dx < Stage::curStage->x && dx < 0)
	{
		x = Stage::curStage->x;
		dx = 0;
	}

	if (right() + dx > Stage::curStage->right() && dx > 0)
	{
		x = Stage::curStage->right() - width;
		dx = 0;
	}


	if (Vampire_Bat::instance->active)
		dx = 0;

	x += dx;
}

void Camera::convertToRenderPos(float x, float y, float & renderX, float & renderY)
{
	D3DXMATRIX mt;

	D3DXMatrixIdentity(&mt);

	mt._22 = -1.0f;
	mt._41 = -this->x;
	mt._42 = this->y;

	D3DXVECTOR4 render_pos;
	D3DXVECTOR3 position;

	position.x = x;
	position.y = y;

	D3DXVec3Transform(&render_pos, &position, &mt);

	renderX = render_pos.x;
	renderY = render_pos.y;

}

void Camera::remove()
{
	for (int  i = 0; i < objects.allObjects.size(); i++)
	{
		if (!SWEPT_AABB->AABBCheck(CAMERA, objects.allObjects[i])
			&& !SWEPT_AABB->AABBCheck(CAMERA, &objects.allObjects[i]->oldRect))
		{
			objects.allObjects[i]->restore();
			objects.removeObject(objects.allObjects[i]);
			i--;
		}
	}
}

Camera::Camera()
{
	//init(109, 1414, 225, 180);
	width = BACK_WIDTH;
	height = BACK_HEIGHT;
}


Camera::~Camera()
{
}
