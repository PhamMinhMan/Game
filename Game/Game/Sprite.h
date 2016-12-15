#pragma once
#include "Animation.h"
#include"Texture.h"
#include<fstream>
using namespace std;
class Sprite
{
public:
	Animation* animations;
	Texture* image;
	int nAnimation;
	void init(char* imagepath, char* animationpath);
	void update(int curAnimation,int& curFrame, GameTime& delay);// cap nhat animation
	void draw(int x,int y,int curAnimation,int curFrame);
	void DrawFlipX(int x, int y, float xCenter, float yCenter, int curAnimation, int curFrame);
	Sprite();
	~Sprite();
};

