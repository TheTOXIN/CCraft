#pragma once

#include "iostream"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Camera.h"
#include "Chunck.h"

using namespace std;
using namespace sf;

class Control
{
public:
	Player *player;
	Camera *camera;
	Chunck *chunck;

	Control();
	Control(Camera &camera, Player &player, Chunck &chunck);

	bool hasClick;

	void checkControl(RenderWindow &window);
	void controlCamera(RenderWindow &window);
	void controlKeyboardPlayer(RenderWindow &window);
	void controlClickPlayer(RenderWindow &window);
};

