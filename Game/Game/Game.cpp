#include "Game.h"
#include"SpriteManager.h"
#include"Simon.h"
#include "Zombie.h"
#include"Camera.h"
#include"SweptAABB.h"

Game* Game::instance=0;

Game* Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}

void Game::init()
{
	map = new Map("Data\\Map\\Map1\\matrix.txt", 
		"Data\\Map\\Map1\\tileSheet.png",
		"Data\\Map\\Map1\\allobject.txt",
		"Data\\Map\\Map1\\quadtree.txt",
		"Data\\Map\\Map1\\stages.txt");

}
void Game::update()
{

	map->update();

	//for each (auto obj in map->objects)
	//{
	//	obj->update();
	//	SWEPT_AABB->checkCollision(SIMON, obj);
	//}

}

void Game::draw()
{
	
	map->draw();
	/*for each (auto obj in map->objects)
	{
		obj->draw();
	}*/
	SIMON->draw();
//	Zombie::getInstance()->draw();

}

Game::Game()
{
}


Game::~Game()
{
}
