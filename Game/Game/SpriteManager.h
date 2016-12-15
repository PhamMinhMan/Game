#pragma once
#include"Sprite.h"
//add
enum SPRITE_MANAGER
{
	SPR_ChangeStage =-6,
	SPR_Gate1 = -5,
	SPR_Fake,
	SPR_CandleLarge = -3,
	SPR_Stair,
	SPR_Ground,
	SPR_Zombie,
	SPR_Panther,
	SPR_Medusa_Head,
	SPR_Merman,
	SPR_Red_Bat,
	SPR_Spear_Guard,
	SPR_Bone_Pillar,
	SPR_Blue_Bat,
	SPR_Ghost,
	SPR_Door,
	SPR_Vampire_Bat,
	SPR_Medusa,
	SPR_SIMON,
	SPR_WHIP,
	SPR_CandleSmall,
	SPR_COUNT
};

class SpriteManager
{
public:
	static SpriteManager* instance;
	static SpriteManager* getInstance();
	int nSprite;
	Sprite* sprites;
	SpriteManager();
	~SpriteManager();
};

