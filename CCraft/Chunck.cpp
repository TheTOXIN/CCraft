#include "Chunck.h"
#include "Game.h"

int checksX[4] = { 1, -1, 0, 0 };
int checksY[4] = { 0, 0, 1, -1 };

void Chunck::print()
{
	for (int ci = 0; ci < h; ci++)
	{
		for (int cj = 0; cj < w; cj++)
		{
			Level level = levels[ci][cj];
			cout << " " << level.x << ":" << level.y << "| i = " << level.index;
			//level.print();
		}
		cout << endl;
	}
	cout << "____________" << endl;
}

Chunck::Chunck(Memory &memory)
{
	this->count_lvl = 0;
	this->memory = &memory;

	init();
}

void Chunck::init()
{
	for (int i = 0; i < h; i++)
	{
		memory->addLvl(generate(World::left, -h + i, i), -h + i);
		memory->addLvl(generate(World::currnet, 0 + i, i), 0 + i);
		memory->addLvl(generate(World::right, h + i, i), h + i);
	}
}

Level* Chunck::generate(int number, int index, int lvl)
{
	levels[lvl][number].generateLevel(lvl);
	levels[lvl][number].x = number;
	levels[lvl][number].y = lvl;
	levels[lvl][number].index = index;
	
	this->count_lvl++;

	return &levels[lvl][number];
}

void Chunck::createBlock(int x, int y)
{
	Level *currentLevel = &levels[y / Game::h][x / Game::w];

	int setX = (x - Game::w * currentLevel->x) / Block::size;
	int setY = (y - Game::h * currentLevel->y) / Block::size;

	if (!(setX >= 0 && setY >= 0 && setX < currentLevel->w && setY < currentLevel->h)) return;

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

	memory->updateLvl(currentLevel);
}

void Chunck::destroyBlock(int x, int y)
{
	Level *currentLevel = &levels[y / Game::h][x / Game::w];

	int setX = (x - Game::w * currentLevel->x) / Block::size;
	int setY = (y - Game::h * currentLevel->y) / Block::size;

	if (!(setX >= 0 && setY >= 0 && setX < currentLevel->w && setY < currentLevel->h)) return;

	for (int i = 0; i < 4; i++) {
		int tmpX = setX + checksX[i];
		int tmpY = setY + checksY[i];

		if (currentLevel->blocks[tmpY][tmpX].index == Block::NONE || 
			(tmpY < 0 || tmpY >= currentLevel->h || tmpX < 0 || tmpX >= currentLevel->w)) {
			currentLevel->blocks[setY][setX] = Block::NONE;
			break;
		}
	}

	memory->updateLvl(currentLevel);
}
