#include "GameWindow.h"

GameWindow::GameWindow(void)
{
}


GameWindow::~GameWindow(void)
{
}

GameWindow* GameWindow::instance = 0;
GameWindow* GameWindow::getInstance()
{
	if (instance == 0)
		instance = new GameWindow();
	return instance;
}


void GameWindow::initHandleWindows(HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(wcex));

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszClassName = "CastleVania";
	RegisterClassEx(&wcex);
	HWND hWnd = CreateWindow("CastleVania", "Game", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 500, 500, 0, 0, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	this->hWnd = hWnd;
}

HWND GameWindow::getHandleWindow()
{
	return hWnd;
}

LRESULT GameWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
