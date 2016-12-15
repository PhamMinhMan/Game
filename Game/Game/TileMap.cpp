#include "TileMap.h"



TileMap::TileMap(const char* matrixPath, const char* tileSheetPath)
{
	fstream fs(matrixPath);

	fs >> nRow;
	nCol = nRow;


	matrix = new int*[nRow];
	//khoi tao gia tri ban dau cho matrix
	for (int i = 0; i < nRow; i++)
	{
		matrix[i] = new int[nCol];
		for (int j = 0; j < nCol; j++)
		{
			fs >> matrix[i][j];
		}
	}

	tileSheet.Init(tileSheetPath, D3DCOLOR_XRGB(123, 123, 123));
}


void TileMap::drawTile(int rowIndex, int colIndex, RectF * camera)
{
	int indexInTileSheet = matrix[rowIndex][colIndex];

	int xTileInScreen, yTileInScreen;

	xTileInScreen = colIndex * 16 - camera->x;
	yTileInScreen = rowIndex * 16 - camera->y;

	RECT rectIndex;

	SetRect(&rectIndex, indexInTileSheet * 16, 0, indexInTileSheet * 16 + 16, 16);

	tileSheet.Draw(xTileInScreen, yTileInScreen, &rectIndex);

}

void TileMap::drawTiles(int rowBegin, int rowEnd, int colBegin, int colEnd, RectF * camera)
{

	if (colBegin<0 || colEnd> nCol - 1 || colBegin>colEnd || rowBegin<0 || rowEnd> nRow - 1 || rowBegin>rowEnd)
		return;


	for (int rowIndex = rowBegin; rowIndex <= rowEnd; rowIndex++)
	{
		for (int colIndex = colBegin; colIndex <= colEnd; colIndex++)
		{
			drawTile(rowIndex, colIndex, camera);
		}
	}
}

void TileMap::draw(RectF * camera)
{
	int cBegin, cEnd, rBegin, rEnd;

	cBegin = camera->left() / 16;
	cEnd = camera->right() / 16;

	rBegin = camera->top() / 16;
	rEnd = camera->bottom() / 16;

	drawTiles(rBegin, rEnd, cBegin, cEnd, camera);
}

TileMap::~TileMap()
{
}
