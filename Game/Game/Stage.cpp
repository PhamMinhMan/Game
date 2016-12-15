#include "Stage.h"


Stage* Stage::curStage=0;
List<Stage*>* Stage::curListStage=0;


void Stage::changeToNextStage()
{
	if (curStage->index == curListStage->size()-1)
		return;


	curStage = curListStage->at(curStage->index + 1);
	curStage->setLocationFromPreviousStage();

}

void Stage::changeToPreviousStage()
{
	if (curStage->index == 0)
		return;


	curStage = curListStage->at(curStage->index - 1);
	curStage->setLocationFromNextStage();
}

void Stage::setLocationFromPreviousStage()
{
	SIMON->x = xSimonFromPreviousStage;
	SIMON->y = ySimonFromPreviousStage;
	
	CAMERA->x = xCameraFromPreviousStage;
	CAMERA->y = yCameraFromPreviousStage;
}

void Stage::setLocationFromNextStage()
{
	SIMON->x = xSimonFromNextStage;
	SIMON->y = ySimonFromNextStage;

	CAMERA->x = xCameraFromNextStage;
	CAMERA->y = yCameraFromNextStage;
}

Stage::Stage()
{
}


Stage::~Stage()
{
}
