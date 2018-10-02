#include "World.h"

World::World()
{
}

World::World(Player & player, Chunck & chunck, Memory & memory)
{
	this->chunck = &chunck;
	this->player = &player;
	this->memory = &memory;
}

void World::init()
{

}

void World::update()
{
	int x = player->level->x;
	int y = player->level->y;

	if (player->level->x == World::left) {
		updateNext();
		player->moveNext();
	} 

	if (player->level->x == World::right) {
		updatePrev();
		player->movePrev();
	}
}

void World::updatePrev()
{
	for (int i = 0; i < chunck->h; i++) {
		chunck->levels[i][World::left] = chunck->levels[i][World::currnet];
		chunck->levels[i][World::left].x = World::left;

		chunck->levels[i][World::currnet] = chunck->levels[i][World::right];
		chunck->levels[i][World::currnet].x = World::currnet;

		chunck->levels[i][World::right].generateClear();
	
		int index = chunck->levels[i][World::currnet].index + Chunck::h;

		if (memory->hasLvl(index))
			chunck->levels[i][World::right] = memory->getLvl(index);
		else
			memory->addLvl(chunck->generate(World::right, index, i), index);
	}
}

void World::updateNext()
{
	for (int i = 0; i < chunck->h; i++) {
		chunck->levels[i][World::right] = chunck->levels[i][World::currnet];
		chunck->levels[i][World::right].x = World::right;

		chunck->levels[i][World::currnet] = chunck->levels[i][World::left];
		chunck->levels[i][World::currnet].x = World::currnet;

		chunck->levels[i][World::left].generateClear();

		int index = chunck->levels[i][World::currnet].index - Chunck::h;

		if (memory->hasLvl(index))
			chunck->levels[i][World::left] = memory->getLvl(index);
		else
			memory->addLvl(chunck->generate(World::left, index, i), index);
	}
}
