#pragma once

#include "Block.h"

class Level
{
public:
	static const int w = 40;
	static const int h = 22;

	int x;//надо проверить это
	int y;//координаты в пределах чанка

	Block blocks[h][w];

	Level();

	void generate();
	void generateTest();
	void generateLevel(int n);
	void generateRes(int rare, int index, int pos);
	void generateTree(int tx, int ty);

	void generateFirst();
	void generateSecond();
	void generateThird();

	void print();
};
