#include "QuadTreeNode.h"
#include "Camera.h"


void QuadTreeNode::findObjectToFillToCamera()
{
	if (!SWEPT_AABB->AABBCheck(CAMERA, this))
		return;
	if (tl!=NULL)
	{
		tl->findObjectToFillToCamera();
		tr->findObjectToFillToCamera();
		bl->findObjectToFillToCamera();
		br->findObjectToFillToCamera();
	}
	else
	{ 
		if (objects.size() > 0) 
		{
			for each (auto obj in objects)
			{
				CAMERA->objects.addObject(obj);
			}
		}
	}
}

QuadTreeNode::QuadTreeNode(fstream & fs, List<GObject*>* allObject, int mapHeight)
{
	fs >> id >> x >> y >> width >> height;
	y = mapHeight - y;
	int nNode, nObject;
	int indexInObjects;
	fs >> nNode >> nObject;
	if (nNode==4)
	{
		tl = new QuadTreeNode(fs, allObject,mapHeight);
		tr = new QuadTreeNode(fs, allObject,mapHeight);
		bl = new QuadTreeNode(fs, allObject,mapHeight);
		br = new QuadTreeNode(fs, allObject,mapHeight);
	}
	else 
	{
		tl = tr = bl = br = NULL;
		if (nObject>0)
		{
			for (int i = 0; i < nObject; i++)
			{
				fs >> indexInObjects;
				objects._Add(allObject->at(indexInObjects));
			}
		}
	}
}

QuadTreeNode::~QuadTreeNode()
{
}
