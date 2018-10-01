#pragma once

#include "iostream"
#include "Level.h"

using namespace std;

class Chunck
{
public:
	static const int w = 3;
	static const int h = 3;

	int count_lvl;

	Level levels[w][h];

	Chunck();

	void createBlock(int x, int y);
	void destroyBlock(int x, int y);

	void init();
	void generate(int n, int i, int l);
	void print();
};
