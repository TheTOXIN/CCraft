#pragma once

#include "iostream"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Camera.h"
#include "Chunck.h"
#include "World.h"

using namespace std;
using namespace sf;

class Control
{
public:
	Player *player;
	Camera *camera;
	Chunck *chunck;
	World *world;

	Control();
	Control(Camera &camera, Player &player, Chunck &chunck, World &world);

	bool hasClick;
	bool hasGenerate;

	void checkControl(RenderWindow &window);
	void controlCamera(RenderWindow &window);
	void controlWorld(RenderWindow &window);
	void controlKeyboardPlayer(RenderWindow &window);
	void controlClickPlayer(RenderWindow &window);
};

