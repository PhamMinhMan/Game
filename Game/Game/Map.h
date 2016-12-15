#pragma once
#include "TileMap.h"
#include"List.h"
#include"GObject.h"
#include"Stage.h"
#include "QuadTree.h"
class Map :
	public TileMap
{
public:

	List<GObject*> objects;
	List<Stage*> stages;
	void initStages(const char * stagePath);

	Map(const char* matrixPath,const char* tileSheetPath,const char* objectsPath, const char* quadtreePath, const char* stagePath);
	QuadTree* quadtree;
	void update();
	void draw();
	~Map();
};

