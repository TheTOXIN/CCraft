#pragma once

#include "iostream"
#include "Chunck.h"

using namespace std;

class World
{
public:
	static const int w = 3;
	static const int h = 3;

	Chunck chuncks[w][h];

	World();

	void render();
	void print();
};
