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

	static const int size = 32;
	int index;
	int x;
	int y;
	int z;
	bool isSolid;
};

