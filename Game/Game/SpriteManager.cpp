#include "SpriteManager.h"


SpriteManager* SpriteManager::instance=0;


SpriteManager * SpriteManager::getInstance()
{
	if (instance == 0)
		instance = new SpriteManager();
	return instance;
}
//add
SpriteManager::SpriteManager()
{
	sprites = new Sprite[SPR_COUNT];
	sprites[SPR_Zombie].init("Data\\enemies.png", "Data\\Enemies.ani");
	sprites[SPR_Panther].init("Data\\enemies.png", "Data\\Panther.ani");
	sprites[SPR_SIMON].init("Data\\simon.png", "Data\\Simon_Sprites.ani");
	sprites[SPR_CandleLarge].init("Data\\Objects_effects.png", "Data\\Fire.ani");
	sprites[SPR_CandleSmall].init("Data\\Objects_effects.png", "Data\\Candle_Small.ani");
	sprites[SPR_Door].init("Data\\Door.png","Data\\Door.ani");
	sprites[SPR_WHIP].init("Data\\whip2.png", "Data\\whip1.ani");
	sprites[SPR_Vampire_Bat].init("Data\\Bosses.png", "Data\\Vampire_Bat.ani");

}


SpriteManager::~SpriteManager()
{
}
