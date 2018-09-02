#pragma once

#include "iostream"
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "World.h"
#include "Chunck.h"
#include "Player.h"

using namespace std;
using namespace sf;

class Graphic
{
public:
	const static int magic = 16;

	int w;
	int h;

	Chunck *chunck;
	Player *player;

	RectangleShape back;
	Object textures;
	Object logo;

	Graphic(Chunck &chunck, Player &player, int w, int h);

	void load();
	void draw(RenderWindow &window);

	void renderWorld(RenderWindow &window, World &world);
	void renderChunck(RenderWindow &window, Chunck &chunk);
	void renderLevel(RenderWindow &window, Level &level);
	void renderBlock(RenderWindow &window, Block &block);
	void renderPlayer(RenderWindow &window, Player &player);
};

