#pragma once
#include <fstream>
#include"Texture.h"
#include"RectF.h"
using namespace std;
class TileMap
{
public:
	Texture tileSheet;
	int** matrix;
	int nRow;
	int nCol;

	int heightMap;

	TileMap(const char* matrixPath,const char* tileSheetPath);


	//ve 1 cai tile len man hinh
	void drawTile(int rowIndex,int colIndex, RectF* camera);

	//ve nhieu tile tu 
	void drawTiles(int rowBegin, int rowEnd, int colBegin, int colEnd, RectF* camera);

	// ve 1 loat tile theo camera
	void draw(RectF* camera);

	~TileMap();
};

