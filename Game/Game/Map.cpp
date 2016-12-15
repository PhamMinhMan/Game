#pragma once
#include "Map.h"
#include"Zombie.h"
#include"BigFire.h"
#include"Gate1.h"
#include"Door.h"
#include "CandleSmall.h"
#include "Panther.h"
#include"ChangeStage.h"

void Map::initStages(const char * stagePath)
{
	Stage* stage;
	fstream fs(stagePath);
	int nStage;
	fs >> nStage;
	for (int i = 0; i < nStage; i++)
	{
		stage = new Stage();
		fs >> stage->x;
		fs >> stage->y;
		fs >> stage->width;
		fs >> stage->height;

		fs >> stage->xCameraFromPreviousStage;
		fs >> stage->yCameraFromPreviousStage;
		fs >> stage->xCameraFromNextStage;
		fs >> stage->yCameraFromNextStage;

		fs >> stage->xSimonFromPreviousStage;
		fs >> stage->ySimonFromPreviousStage;
		fs >> stage->xSimonFromNextStage;
		fs >> stage->ySimonFromNextStage;

		stage->index = i;

		stages._Add(stage);
	}

	Stage::curListStage = &stages;
	Stage::curStage = stages[0];

	stages[0]->setLocationFromPreviousStage();
}

Map::Map(const char* matrixPath, const char* tileSheetPath, 
	const char* objectsPath, const char* quadtreePath, const char* stagePath):
	TileMap(matrixPath,tileSheetPath)
{
	int nObject, id, x, y, width, height;;
	fstream fs(objectsPath);

	fs >> nObject;

	GObject* obj;
	//add
	for (int i = 0; i < nObject; i++)
	{
		fs >> id >> x >> y >> width >> height;
		switch (id%100)
		{
		case SPR_Zombie:
			obj = new Zombie();
			break;
		case SPR_CandleLarge:
			obj = new BigFire();
			break;
		case SPR_CandleSmall:
			obj = new CandleSmall();
			break;
		case SPR_Gate1:
			obj = new Gate1();
			break;
		case SPR_Door:
			obj = new Door();
			break;
		case SPR_Panther:
			obj = new Panther();
			break;
		case SPR_Stair:
			obj = new Stair();
			break;
		case SPR_ChangeStage:
			obj = new ChangeStage();
			break;
		default:
			obj = new GObject();
			break;
		}
		
		if (id == -101)
		{
			x += 8;
		}

		obj->id = id;
		//add
		if(id >= 0|| id ==-3 ||id==-4)
			obj->sprite = &SpriteManager::getInstance()->sprites[id%100];
		obj->x = x;
		obj->y = y;
		obj->width = width;
		obj->height = height;

		obj->setOldRect();

		objects._Add(obj);
	}

	quadtree = new QuadTree();
	quadtree->init(quadtreePath, &objects);

	initStages(stagePath);
}


void Map::update()
{
	quadtree->update();// tim doi tuong de do vo camera

	if (Door::curDoor != 0)
	{
		Door::curDoor->update();
		return;
	}


	SIMON->update();

	//for each (auto obj in CAMERA->objects.allObjects)
	for (int i=0;i<CAMERA->objects.allObjects.size();i++)
	{
		CAMERA->objects.allObjects[i]->update();
	}

	for each (auto stair in CAMERA->objects.stairObjects)
	{
		SWEPT_AABB->checkCollision(SIMON, stair);
	}

	///	va cham giua simon, cac enemy voi ground
	for each (auto obj in CAMERA->objects.groundObjects)
	{
		SWEPT_AABB->checkCollision(SIMON, obj);
		for each (auto enemy in CAMERA->objects.enemyObjects)
		{
			SWEPT_AABB->checkCollision(enemy, obj);
		}
	}
	///
	for each (auto enemy in CAMERA->objects.enemyObjects)
	{
		SWEPT_AABB->checkCollision(SIMON, enemy);
		SWEPT_AABB->checkCollision(SIMON->whip, enemy);
	}

	for each (auto object in CAMERA->objects.gateObjects)
	{
		SWEPT_AABB->checkCollision(SIMON, object);
	}

	for each (auto candle in CAMERA->objects.candleObjects)
	{
		SWEPT_AABB->checkCollision(SIMON, candle);
	}

	for each (auto changeStage in CAMERA->objects.changeStageObjects)
	{
		SWEPT_AABB->checkCollision(SIMON, changeStage);
	}


	for each (auto obj in CAMERA->objects.allObjects)
	{
		obj->updateLocation();
	}

	SIMON->updateLocation();
	CAMERA->update();

}

void Map::draw()
{
	TileMap::draw(CAMERA);
	for each (auto obj in CAMERA->objects.allObjects)
	{
		obj->draw();
	}
}

Map::~Map()
{
}
