#pragma once

#include "iostream"
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Block.h"
#include "Item.h"
#include "Player.h"
#include "World.h"
#include "Graphic.h"
#include "Audio.h"
#include "Control.h"
#include "Camera.h"
#include "Chunck.h"

using namespace std;
using namespace sf;

class Game//TODO refactoring
{
public:
	static const int h = 720;
	static const int w = 1280;

	float temp = 5000;
	float tick = 0;

	Game();

	void start();
};