#pragma once

#include "Block.h"

class Chunck
{
public:
	static const int w = 40;
	static const int h = 22;

	int x;
	int y;

	Block blocks[h][w];

	Chunck();

	void generate();
	void generateTest();

	void print();
};
