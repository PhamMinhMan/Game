#pragma once

#include"RectF.h"
#include"GObject.h"

#define MAX(a,b) a>b? a: b
#define MIN(a,b) a>b? b: a

class SweptAABB
{
	static SweptAABB* instance;
public:
	static SweptAABB* getInstance();

	//Bao gom object va dx dy cua no
	RectF getSweptBroadphase(GObject* M);

	//kiem tra 2 hinh co giao nhau hay khong
	bool AABBCheck(RectF* M, RectF* S);

	//kiem tra va cham
	float sweptAABB(GObject* M, GObject* S, int& normalX, int& normalY);


	//kiem tra va cham va xu ly va cham
	void checkCollision(GObject*M, GObject*S);

	//chan va cham 4 huong
	void preventMove(GObject* M, GObject* S);


};

