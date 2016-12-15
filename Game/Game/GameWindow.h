#pragma once
#include<Windows.h>
#include"Config.h"
class GameWindow
{
	HWND hWnd;
	static GameWindow* instance;
public:
	static GameWindow* getInstance();
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	void initHandleWindows(HINSTANCE hInstance, int nCmdShow);
	HWND getHandleWindow();
	GameWindow(void);
	~GameWindow(void);
};

