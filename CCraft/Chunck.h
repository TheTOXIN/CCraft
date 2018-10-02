#pragma once

#include "iostream"
#include "Level.h"
#include "Memory.h"

using namespace std;

class Chunck
{
public:
	static const int w = 3;
	static const int h = 3;

	Chunck(Memory &memory);

	int count_lvl;

	Level levels[w][h];

	Memory *memory;

	void createBlock(int x, int y);
	void destroyBlock(int x, int y);

	Level* generate(int n, int i, int l);

	void init();
	void print();
};
