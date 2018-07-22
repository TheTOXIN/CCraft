#pragma once

#include "iostream"
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "World.h"
#include "Player.h"

using namespace std;
using namespace sf;

class Graphic
{
public:
	const static int magic = 16;

	int w;
	int h;

	World *world;
	Player *player;

	RectangleShape back;
	Object textures;
	Object logo;

	Graphic(World &world, Player &player, int w, int h);

	void load();
	void draw(RenderWindow &window);
};

