#include "Gate1.h"
#include"Simon.h"
#include"Keyboard.h"
#include"Stage.h"


void Gate1::onInterserct(GObject * other)
{
	if (Keyboard::getInstance()->keyChangeStage && other->direction==Right)
	{
		Stage::changeToNextStage();
	}
}

Gate1::Gate1()
{
	objectFilter = CF_Gate;
}


Gate1::~Gate1()
{
}
