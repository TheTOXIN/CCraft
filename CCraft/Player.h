#pragma once

#include "iostream"
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Level.h"
#include "Chunck.h"

using namespace std;
using namespace sf;

enum state
{
	jump,
	none,
	left,
	right,
	down,
	up
};

class Player
{
public:
	int x;
	int y;
	int dx;
	int dy;
	int r;
	int d;
	int j;

	bool inSpace;
	bool onGround;

	state state;

	FloatRect rect;
	Texture texture;

	Chunck *chunck;
	Level *level;

	Sprite head;
	Sprite body;
	Sprite arm1;
	Sprite arm2;
	Sprite leg1;
	Sprite leg2;

	Player();
	Player(Chunck &chunck);

	void jump();
	void move();
	void none();
	void left();
	void right();
	void down();
	void up();

	void renderFront();
	void renderLeft();
	void renderRight();
	void renderBack();

	void animateJump();
	void animateLeft();
	void animateRight();
	void animateSit();

	void init();
	void update();
	void animate();
	void default();

	bool checkX();
	bool checkY();
};
