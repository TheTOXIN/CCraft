#pragma once

#include "iostream"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Camera.h"

using namespace std;
using namespace sf;

class Control
{
public:
	Player *player;
	Camera *camera;

	Control();
	Control(Camera &camera, Player &player);

	void checkControl(RenderWindow &window);
	void controlCamera(RenderWindow &window);
	void controlPlayer(RenderWindow &window);
};

