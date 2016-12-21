#pragma once
#include "QuadTreeNode.h"

class QuadTree
{
public:
	QuadTreeNode* rootNode;
	void init(const char* quadtreePath, List<GObject*>* allObject,int mapHeight);
	void update();
	QuadTree();
	~QuadTree();
};
