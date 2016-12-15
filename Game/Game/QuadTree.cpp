#include "QuadTree.h"

void QuadTree::init(const char * quadtreePath, List<GObject*>* allObject)
{
	fstream fs(quadtreePath);
	rootNode = new QuadTreeNode(fs, allObject);
}

void QuadTree::update()
{
	//lay doi tuong cu ra khoi camera
	CAMERA->remove();

	//fill nhung object nam trong node cat camera
	rootNode->findObjectToFillToCamera();
}

QuadTree::QuadTree()
{
}

QuadTree::~QuadTree()
{
}
