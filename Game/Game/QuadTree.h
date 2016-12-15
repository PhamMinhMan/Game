#pragma once
#include "QuadTreeNode.h"

class QuadTree
{
public:
	QuadTreeNode* rootNode;
	void init(const char* quadtreePath, List<GObject*>* allObject);
	void update();
	QuadTree();
	~QuadTree();
};
