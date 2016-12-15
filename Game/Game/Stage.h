#pragma once
#include"RectF.h"
#include "Camera.h"
#include "Simon.h"
#include"List.h"
class Stage : public RectF
{
public:

	static Stage* curStage;
	static List<Stage*>* curListStage;

	static void changeToNextStage();
	static void changeToPreviousStage();

	int xCameraFromPreviousStage;
	int yCameraFromPreviousStage;

	int xCameraFromNextStage;
	int yCameraFromNextStage;


	int xSimonFromPreviousStage;
	int ySimonFromPreviousStage;

	int xSimonFromNextStage;
	int ySimonFromNextStage;

	void setLocationFromPreviousStage();
	void setLocationFromNextStage();

	int index;

	Stage();
	~Stage();
};

