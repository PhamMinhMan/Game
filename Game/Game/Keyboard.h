#pragma once
#include <dinput.h>
class Keyboard
{
private:
	HWND m_hWnd;
	HINSTANCE m_hInstance;
	LPDIRECTINPUT8 m_di;      
	LPDIRECTINPUTDEVICE8 m_keyboard;
	DIDEVICEOBJECTDATA m_keyEvents[256];
	BYTE m_keyStates[256];	
	Keyboard(HINSTANCE hInstance, HWND hWnd);
	static Keyboard* instance;
public:
	static Keyboard* getInstance();
	static void initialize(HINSTANCE hInstance, HWND hWnd);
	~Keyboard();
	void updateKeyboard();
	void pollKeyboard();
	bool isKeyDown(BYTE keyCode);
	bool isKeyUp(BYTE keyCode);
	void release();

	bool keyUp, keyRight, keyLeft, keyDown, keyJump, keyAttack;
	bool keyJumpPress, isKeyJumpDownPrevious;
	bool keyAttackPress, isKeyAttackDownPrevious;
	bool keyChangeStage;
};


