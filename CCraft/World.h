#pragma once

#include "Player.h"
#include "Chunck.h"
#include "Level.h"
#include "Memory.h"
#include "map"

class World
{
public:
	World();
	World(Player &player, Chunck &chunck, Memory &memory);

	static const int left = 0;
	static const int currnet = 1;
	static const int right = 2;

	Memory *memory;
	Player *player;
	Chunck *chunck;

	void init();
	void update();
	void updateNext();
	void updatePrev();
};
