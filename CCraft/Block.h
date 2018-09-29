#pragma once

#include "iostream"
#include <SFML/Graphics.hpp>
#include "Object.h"

using namespace std;
using namespace sf;

class Block
{
public:
	Block();
	Block(int index);

	void init();

	static const int size = 32;

	int index;

	int x;
	int y;
	int z;

	bool isSolid;

	static const int STONE = 2;
	static const int DIRT = 3;
	static const int GRASS = 4;
	static const int BEDROCK = 18;
	static const int GRAV = 20;
	static const int WOOD = 21;
	static const int LEAVE = 54;
	static const int LAVA = 240;

	static const int RUDA_DIMOND = 51;
	static const int RUDA_GOLD = 33;
	static const int RUDA_IRON = 34;
	static const int RUDA_RED = 52;
	static const int RUDA_UGOL = 35;
};

