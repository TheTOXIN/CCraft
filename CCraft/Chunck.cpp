#include "Chunck.h"
#include "Game.h"

void Chunck::print()
{
	for (int ci = 0; ci < h; ci++)
	{
		for (int cj = 0; cj < w; cj++)
		{
			Level chunck = levels[ci][cj];
			cout << "CHUNCK = " << chunck.x << ":" << chunck.y << endl;
			chunck.print();
		}
	}
}

Chunck::Chunck()
{
	generate();
}

void Chunck::generate()
{
	int left = 0;
	int current = 1;
	int right = 2;

	for (int i = 0; i < h; i++)
	{
		levels[i][current].generateLevel(i);
		levels[i][current].x = current;
		levels[i][current].y = i;
	}

	for (int i = 0; i < h; i++)
	{
		levels[i][left].generateLevel(i);
		levels[i][left].x = left;
		levels[i][left].y = i;
	}

	for (int i = 0; i < h; i++)
	{
		levels[i][right].generateLevel(i);
		levels[i][right].x = right;
		levels[i][right].y = i;
	}
}

void Chunck::createBlock(int x, int y)
{
	Level *currentLevel = &levels[y / Game::h][x / Game::w];

	int setX = (x - Game::w * currentLevel->x) / Block::size;
	int setY = (y - Game::h * currentLevel->y) / Block::size;

	if (!(setX >= 0 && setY >= 0 && setX < currentLevel->w && setY < currentLevel->h)) return;

	int checksX[4] = { 1, -1, 0, 0 };
	int checksY[4] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; i++) {
		int tmpX = setX + checksX[i];
		int tmpY = setY + checksY[i];

		if (tmpX >= 0 && setY >= 0 && tmpX < currentLevel->w && setY < currentLevel->h) {
			if (currentLevel->blocks[tmpY][tmpX].index != Block::NONE) {
				if (currentLevel->blocks[setY][setX].index == Block::NONE) {
					currentLevel->blocks[setY][setX] = Block::BOARD;
					break;
				}
			}
		}
	}
}

void Chunck::destroyBlock(int x, int y)
{
	Level *currentLevel = &levels[y / Game::h][x / Game::w];

	int setX = (x - Game::w * currentLevel->x) / Block::size;
	int setY = (y - Game::h * currentLevel->y) / Block::size;

	if (!(setX >= 0 && setY >= 0 && setX < currentLevel->w && setY < currentLevel->h)) return;

	currentLevel->blocks[setY][setX] = Block::NONE;
}
