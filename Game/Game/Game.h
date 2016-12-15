#pragma once
#include"Texture.h"
#include "MovableObject.h"
#include"Sprite.h"
#include"Map.h"
class Game
{
public:
	static Game* instance;
	static Game* getInstance();
	
	Map* map;
	void init();
	void update();
	void draw();
	Game();
	~Game();
};

