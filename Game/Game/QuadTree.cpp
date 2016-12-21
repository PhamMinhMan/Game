#include "QuadTree.h"

void QuadTree::init(const char * quadtreePath, List<GObject*>* allObject, int mapHeight)
{
	fstream fs(quadtreePath);
	rootNode = new QuadTreeNode(fs, allObject,mapHeight);
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
