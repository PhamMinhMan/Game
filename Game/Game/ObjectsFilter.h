#pragma once
#include "List.h"

class GObject;
class ObjectsFilter
{
public:
	//add
	List<GObject*> allObjects;
	List<GObject*> enemyObjects;
	List<GObject*> groundObjects;
	List<GObject*> itemObjects;
	List<GObject*> gateObjects;
	List<GObject*> candleObjects;
	List<GObject*> stairObjects;
	List<GObject*> changeStageObjects;
	List<GObject*> activeVampireBatObjects;
	

	void addObject(GObject* obj);

	void removeObject(GObject* obj);

	ObjectsFilter();
	~ObjectsFilter();
};

