#include "SweptAABB.h"



SweptAABB* SweptAABB::instance=0;


SweptAABB* SweptAABB::getInstance()
{
	if(instance==0)
		instance = new SweptAABB();
	return instance;
}

RectF SweptAABB::getSweptBroadphase(GObject* M)
{
	float x, y, w, h;
	x = M->dx > 0 ? M->x : M->x + M->dx;
	y = M->dy < 0 ? M->y : M->y + M->dy;
	w = abs(M->dx) + M->width;
	h = abs( M->dy) + M->height;
	RectF broadphasebox;
	broadphasebox.init(x, y, w, h);
	return broadphasebox;
}

bool SweptAABB::AABBCheck(RectF * M, RectF * S)
{
	return (M->bottom() < S->top() && M->top() > S->bottom()
		&& M->left() < S->right() && M->right() > S->left());
}

float SweptAABB::sweptAABB(GObject * M, GObject * S, int & normalx, int & normaly)
{
	normalx = 0.0f;
	normaly = 0.0f;
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	if (M->dx > 0.0f)
	{
		xInvEntry = S->x - (M->x + M->width);
		xInvExit = (S->x + S->width) - M->x;
	}
	else
	{
		xInvEntry = (S->x + S->width) - M->x;
		xInvExit = S->x - (M->x + M->width);
	}

	if (M->dy > 0.0f)
	{
		yInvEntry = S->y - (M->y + M->height);
		yInvExit = (S->y + S->height) - M->y;
	}
	else
	{
		yInvEntry = (S->y + S->height) - M->y;
		yInvExit = S->y - (M->y + M->height);
	}

	float xEntry, yEntry;
	float xExit, yExit;

	if (M->dx == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / M->dx;
		xExit = xInvExit / M->dx;
	}

	if (M->dy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / M->dy;
		yExit = yInvExit / M->dy;
	}

	float entryTime = MAX(xEntry, yEntry);
	float exitTime = MIN(xExit, yExit);

	//if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	if (entryTime > exitTime || xEntry > 1.0f || yEntry > 1.0f)
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}
	else
	{
		normalx = 0;
		normaly = 0;

		if (M->left() < S->right() && M->right() > S->left())
		{
			if (M->dy>0)
				normaly = -1;
			else
				normaly = 1;
			normalx = 0;
			return entryTime;
		}

		if (M->top() <  S->bottom() && M->bottom() >  S->top())
		{
			if (M->dx>0)
				normalx = -1;
			else
				normalx = 1;
			normaly = 0;
		}
		return entryTime;
	}
}

void SweptAABB::checkCollision(GObject * M, GObject * S)
{
	if (!M->alive || !S->alive)
		return;

	//tru de su dung thuat toan AABB
	//M->y = -M->y;
	//M->dy = -M->dy;

	//tinh broadphasebox
	RectF movBroadPhase = getSweptBroadphase(M);
	//kiem tra broadphase box co giao nhau voi S hay khong
	if (AABBCheck(&movBroadPhase, S))
	{
		if (AABBCheck(S, M))
		{
			//khoi phuc lai toa do ban dau
			M->onInterserct(S);
			S->onInterserct(M);
			return;
		}
		M->y = -M->y;
		S->y = -S->y;
		M->dy = -M->dy;
		//neu co thi co the xay ra va cham
		int nx, ny;
		//tinh sweptTime
		float sweptTime = sweptAABB(M, S, nx, ny);
		if (sweptTime < 1.0)
		{
			//chac chan co va cham
			
			//khoi phuc lai toa do ban dau

			M->y = -M->y;
			S->y = -S->y;
			M->dy = -M->dy;

			M->onCollision(S, nx, ny);
			S->onCollision(M, nx, ny);

			return;
		}

		M->y = -M->y;
		S->y = -S->y;
		M->dy = -M->dy;
	}
}

void SweptAABB::preventMove(GObject * M, GObject * S)
{
	if (M->top() > S->bottom() && M->bottom() < S->top() && M->dx != 0)
	{
		if (M->dx > 0)
			M->dx = S->left() - M->right();
		else
			M->dx = S->right() - M->left();
		M->biDoiVanToc = true;

		return;
	}

	if (M->left() < S->right() && M->right() > S->left() && M->dy != 0)
	{
		if (M->dy > 0)
			M->dy = S->bottom() - M->top();
		else
			M->dy = S->top() - M->bottom();
		M->biDoiVanToc = true;

		return;
	}

	M->coVaChamCheo = true;
}

