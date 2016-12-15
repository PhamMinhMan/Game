#include "ObjectsFilter.h"
#include"GObject.h"
//add
void ObjectsFilter::addObject(GObject * obj)
{
	switch (obj->objectFilter)
	{
	case CF_Stair:
		stairObjects._Add(obj);
		break;
	case CF_Ground:
		groundObjects._Add(obj);
		break;
	case CF_Item:
		itemObjects._Add(obj);
		break;
	case CF_Enemy:
		enemyObjects._Add(obj);
		break;
	case CF_Gate:
		gateObjects._Add(obj);
		break;
	case CF_CandleLarge:
		candleObjects._Add(obj);
		break;
	case CF_CandleSmall:
		candleObjects._Add(obj);
		break;
	case CF_Panther:
		enemyObjects._Add(obj);
		break;
	case CF_ChangeStage:
		changeStageObjects._Add(obj);
		break;
	default:
		break;
	}
	allObjects._Add(obj);
}

void ObjectsFilter::removeObject(GObject * obj)
{
	switch (obj->objectFilter)
	{
	case CF_Ground:
		groundObjects._Remove(obj);
		break;
	case CF_Item:
		itemObjects._Remove(obj);
		break;
	case CF_Enemy:
		enemyObjects._Remove(obj);
		break;
	case CF_Gate:
		gateObjects._Remove(obj);
		break;
	case CF_CandleLarge:
		candleObjects._Remove(obj);
		break;
	case CF_CandleSmall:
		candleObjects._Remove(obj);
		break;
	case CF_Stair:
		stairObjects._Remove(obj);
		break;
	case CF_ChangeStage:
		changeStageObjects._Remove(obj);
		break;
	default:
		break;
	}
	allObjects._Remove(obj);
}

ObjectsFilter::ObjectsFilter()
{
}


ObjectsFilter::~ObjectsFilter()
{
}
