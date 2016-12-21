#include "GameTime.h"


GameTime * GameTime::instance = 0;
GameTime * GameTime::getInstance()
{
	if (instance == 0)
		instance = new GameTime();
	return instance;
}

GameTime::GameTime(void)
{
	onTime = false;
}

void GameTime::start()
{
	startTime = GetTickCount();
	onTime = true;
}

GameTime::GameTime(DWORD tickPerFrame)
{
	onTime = false;
	this->tickPerFrame = tickPerFrame;
}

void GameTime::init(DWORD tickPerFrame)
{
	onTime = false;
	this->tickPerFrame = tickPerFrame;
}


bool GameTime::atTime()
{

	DWORD now = GetTickCount();
	deltaTime = now - startTime;

	if(deltaTime>=tickPerFrame)
	{
		startTime = GetTickCount();
		onTime = false;
		return true;
	}

	return false;
}

void GameTime::update()
{
	DWORD now = GetTickCount();
	deltaTime = now - startTime;
	if (deltaTime >= tickPerFrame)
	{
		startTime = GetTickCount();
		onTime = false;
	}
}

GameTime::~GameTime(void)
{
}


