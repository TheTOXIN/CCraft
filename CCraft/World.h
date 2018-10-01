#pragma once

#include "Player.h"
#include "Chunck.h"
#include "Level.h"
#include "map"

class World
{
public:
	World();
	World(Player &player, Chunck &chunck);

	static const int left = 0;
	static const int currnet = 1;
	static const int right = 2;

	map <int, Level> memory;

	Player *player;
	Chunck *chunck;

	void init();
	void update();
	void updateNext();
	void updatePrev();
};
