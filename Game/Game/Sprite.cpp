#include "Sprite.h"



void Sprite::init(char * imagepath, char * animationpath)
{
	fstream fs(animationpath);
	int r, g, b;
	fs >> r >> g >> b;

	fs >> nAnimation;
	int id;
	animations = new Animation[nAnimation];
	int x, y, w, h;

	for (int i = 0; i < nAnimation; i++)
	{
		fs >> id;
		fs >> animations[i].nRect;
		animations[i].rects = new RECT[animations[i].nRect];

		for (int j = 0; j < animations[i].nRect; j++)
		{
			fs >> x >> y >> w >> h;
			animations[i].rects[j].left = x;
			animations[i].rects[j].right = x + w;
			animations[i].rects[j].top = y;
			animations[i].rects[j].bottom = y + h;
		}
	}

	image = new Texture();
	image->Init(imagepath, D3DCOLOR_XRGB(r, g, b));
		
}

void Sprite::update(int curAnimation,int& curFrame, GameTime& delay)
{
	animations[curAnimation].update(curFrame, delay);//next
}

void Sprite::draw(int x, int y, int curAnimation, int curFrame)
{
	image->Draw(x, y, &animations[curAnimation].rects[curFrame]);
}

void Sprite::DrawFlipX(int x, int y, float xCenter, float yCenter, int curAnimation, int curFrame)
{
	image->DrawFlipX(x, y, xCenter, yCenter, &animations[curAnimation].rects[curFrame]);
}

Sprite::Sprite()
{
}


Sprite::~Sprite()
{
}
