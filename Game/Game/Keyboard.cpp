#include "Keyboard.h"

Keyboard* Keyboard::instance = 0;

Keyboard::Keyboard(HINSTANCE hInstance, HWND hWnd)
{
	m_hWnd = hWnd;
	m_hInstance = hInstance;
	DirectInput8Create(hInstance,DIRECTINPUT_VERSION,IID_IDirectInput8, (VOID**)&m_di, NULL		);
	m_di->CreateDevice(GUID_SysKeyboard, &m_keyboard, NULL);
	m_keyboard->SetDataFormat(&c_dfDIKeyboard);
	m_keyboard->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE);

	DIPROPDWORD dipdw;

	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = 1024; 

	m_keyboard->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	m_keyboard->Acquire();
	isKeyJumpDownPrevious = false;
}


Keyboard * Keyboard::getInstance()
{
	return instance;
}

void  Keyboard::initialize(HINSTANCE hInstance, HWND hWnd)
{
	instance = new Keyboard(hInstance, hWnd);
}

Keyboard::~Keyboard()
{
	release();
}


void Keyboard::pollKeyboard()
{
	m_keyboard->Poll();
	if (FAILED(m_keyboard->GetDeviceState(sizeof(m_keyEvents), (LPVOID)&m_keyEvents)))
	{
		//keyboard device lost, try to re-acquire
		m_keyboard->Acquire();
		m_keyboard->GetDeviceState(sizeof(m_keyEvents), (LPVOID)&m_keyEvents);
	}
	else
	{
		m_keyboard->GetDeviceState(sizeof(m_keyEvents), (LPVOID)&m_keyEvents);
	}

}

void Keyboard::updateKeyboard()
{
	m_keyboard->GetDeviceState(256, m_keyStates);//lay trang thai cac phim hien tai
	keyLeft = isKeyDown(DIK_LEFT);
	keyRight = isKeyDown(DIK_RIGHT);
	keyUp = isKeyDown(DIK_UP);
	keyDown = isKeyDown(DIK_DOWN);
	keyJump =  isKeyDown(DIK_X);
	keyAttack = isKeyDown(DIK_Z);
	keyChangeStage = isKeyDown(DIK_S);

	/*keyJump = keyJump && !isKeyJumpDownPrevious;
	isKeyJumpDownPrevious = keyJump;*/

	keyAttackPress = keyAttack && !isKeyAttackDownPrevious;
	isKeyAttackDownPrevious = keyAttack;

}
void Keyboard::release()
{
	if (m_keyboard )
	{
		m_keyboard->Unacquire();
		m_keyboard->Release();
		m_keyboard = NULL;
	}
	if (m_di)
	{
		m_di->Release();
		m_di = 0;
	}
}
bool Keyboard::isKeyDown(BYTE keyCode)
{
	return (m_keyStates[keyCode] & 0x80) > 0;
}

bool Keyboard::isKeyUp(BYTE keyCode)
{
	return !((m_keyStates[keyCode] & 0x80) > 0);
}

