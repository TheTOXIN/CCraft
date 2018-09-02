#pragma once

#include "iostream"
#include "Level.h"

using namespace std;

class Chunck
{
public:
	static const int w = 3;
	static const int h = 3;

	Level levels[w][h];

	Chunck();

	void render();
	void print();
};
