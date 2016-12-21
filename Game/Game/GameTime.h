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

	bool onTime;

	GameTime(void);
	~GameTime(void);
	GameTime(DWORD tickPerFrame);
	void init(DWORD tickPerFrame);
	bool atTime();
	void update();
	void start();
};

