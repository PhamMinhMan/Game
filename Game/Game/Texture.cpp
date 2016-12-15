#include "Texture.h"


Texture::Texture(const char* filepath, D3DCOLOR transColor)
{
	Init(filepath, transColor);
}

void Texture::Init(const char* filepath, D3DCOLOR transColor)
{
	HRESULT result;
	D3DXIMAGE_INFO info;
	result = D3DXGetImageInfoFromFile(filepath, &info);
	Width = info.Width;
	Height = info.Height;
	if (result != D3D_OK)
		return;

	result = D3DXCreateTextureFromFileEx(
		Graphics::getInstance()->GetDevice(),
		filepath,
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transColor,
		&info,
		NULL,
		&m_image);

	if (result != D3D_OK)
		return;
}


void Texture::Draw(int x, int y, RECT *r)
{
	Graphics::getInstance()->GetSprite()->Draw(m_image,
		r,
		0,
		&D3DXVECTOR3(x, y, 0),
		D3DCOLOR_XRGB(255, 255, 255));
}

void Texture::DrawFlipX(int x, int y, float xCenter, float yCenter, RECT * r)
{
	Graphics::getInstance()->GetSprite()->Draw(
		m_image,										//Textture
		r,												//SrcRect
		&D3DXVECTOR3(xCenter, yCenter, 0),				//Center
		&D3DXVECTOR3(x, y, 0),							//Position
		D3DCOLOR_XRGB(255, 255, 255));
}




Texture::~Texture()
{
	if (m_image)
	{
		m_image->Release();
		m_image = 0;
	}

}
