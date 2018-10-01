#include "Chunck.h"
#include "Game.h"

void Chunck::print()
{
	for (int ci = 0; ci < h; ci++)
	{
		for (int cj = 0; cj < w; cj++)
		{
			Level level = levels[ci][cj];
			cout << "LEVEL = " << level.x << ":" << level.y << endl;
			level.print();
		}
	}
}

Chunck::Chunck()
{
	this->count_chunck = 0;

	generate(World::left, count_chunck - 1);
	generate(World::currnet, count_chunck);
	generate(World::right, count_chunck + 1);
}

void Chunck::generate(int number, int index)
{
	for (int i = 0; i < h; i++)
	{
		levels[i][number].generateLevel(i);
		levels[i][number].x = number;
		levels[i][number].y = i;
		levels[i][number].index = index;
	}

	this->count_chunck++;
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

	int checksX[4] = { 1, -1, 0, 0 };
	int checksY[4] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; i++) {
		int tmpX = setX + checksX[i];
		int tmpY = setY + checksY[i];

		if (currentLevel->blocks[tmpY][tmpX].index == Block::NONE || 
			(tmpY < 0 || tmpY >= currentLevel->h || tmpX < 0 || tmpX >= currentLevel->w)) {
			currentLevel->blocks[setY][setX] = Block::NONE;
			break;
		}
	}
}
