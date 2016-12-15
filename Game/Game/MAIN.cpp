#include<Windows.h>
#include"GameWindow.h"
#include"Graphics.h"
#include"Game.h"
#include"Keyboard.h"
#include<string>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//khoi tao cua so
	GameWindow::getInstance()->initHandleWindows(hInstance, nCmdShow);

	Keyboard::getInstance()->initialize(hInstance, GameWindow::getInstance()->getHandleWindow());
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	GameTime::getInstance()->tickPerFrame = 10;
	GameTime::getInstance()->start();

	GAME->init();

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			if (GameTime::getInstance()->atTime())
			{
				Keyboard::getInstance()->pollKeyboard();
				Keyboard::getInstance()->updateKeyboard();
				GAME->update();
				Graphics::getInstance()->BeginGraphics();
				GAME->draw();
				// nhung cau lenh ve hinh len backbuffer
				Graphics::getInstance()->EndGraphics();
				Graphics::getInstance()->PresentBackBuffer();// ve backbuffer len man hinh
			}
			else
			{
				Sleep(GameTime::getInstance()->tickPerFrame);
			}
		}
	}
	return nCmdShow;
}
