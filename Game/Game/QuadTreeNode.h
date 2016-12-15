#pragma once
#include "RectF.h"
#include "List.h"
#include "GObject.h"
class QuadTreeNode: public RectF
{
public:
	QuadTreeNode* tl;
	QuadTreeNode* tr;
	QuadTreeNode* bl;
	QuadTreeNode* br;
	List<GObject*> objects;
	int id;
	void findObjectToFillToCamera();
	QuadTreeNode(fstream& fs, List<GObject*>* allObject);
	~QuadTreeNode();
};

