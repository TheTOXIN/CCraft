#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

class Camera
{
public:
	View view;
	Player *player;

	const int SPEED = 5;

	int w;
	int h;

	int x;
	int y;

	Camera();
	Camera(Player & player, int h, int w);

	View getView();
	void setView(View & view);

	void update();
	void reset();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void toReduce();
	void toIncrease();
};
