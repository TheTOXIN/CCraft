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
	
	int r_area;

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

	bool validClick(int cx, int cy);
	void spawn();

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

	void moveNext();
	void movePrev();

	bool checkX();
	bool checkY();
};
