#pragma once
#include<Windows.h>
class GameTime
{
protected:

public:

	static GameTime* instance;
	static GameTime* getInstance();


	DWORD startTime;
	DWORD tickPerFrame;
	DWORD deltaTime;
	GameTime(void);
	~GameTime(void);

	GameTime(DWORD tickPerFrame);
	bool atTime();
	void start();
};

