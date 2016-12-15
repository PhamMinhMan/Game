#pragma once
#include"Graphics.h"


class Texture
{
private:
	LPDIRECT3DTEXTURE9 m_image;
public:
	int Width, Height;
	DIRECTION defautDirection;

	Texture(const char* filepath, D3DCOLOR transColor);
	////tao texture
	// filepath: duong dan file hinh anh
	// transColor: mau can trong suot
	Texture() { defautDirection = Left; }
	void Init(const char* filepath, D3DCOLOR transColor);

	////ham ve
	// x,y
	// r vung muon ve

	void Draw(int x, int y, RECT *r);
	void DrawFlipX(int x, int y, float xCenter, float yCenter, RECT *r);
	~Texture();
};

