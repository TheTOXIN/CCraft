#include "World.h"

World::World()
{
}

World::World(Player & player, Chunck & chunck)
{
	this->chunck = &chunck;
	this->player = &player;
}

void World::init()
{

}

void World::update()
{
	
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

		if (memory.find(index) == memory.end())
		{
			chunck->generate(World::right, index, i);
			memory.insert(pair<int, Level>(index, chunck->levels[i][World::right]));
		}
		else
		{
			Level lvl = memory.find(index)->second;
			chunck->levels[i][World::right] = lvl;
		}
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

		if (memory.find(index) == memory.end())
		{
			chunck->generate(World::left, index, i);
			memory.insert(pair<int, Level>(index, chunck->levels[i][World::left]));
		}
		else
		{
			Level lvl = memory.find(index)->second;
			chunck->levels[i][World::left] = lvl;
		}
	}
}
