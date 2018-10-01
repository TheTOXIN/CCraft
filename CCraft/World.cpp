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
	}

	int index = chunck->levels[1][World::currnet].index + 1;

	if (memory.find(index) == memory.end()) 
	{
		cout << "NOT FOUND" << endl;
	}
	else
	{
		cout << "FOUND" << endl;
	}

	chunck->generate(World::right, index);
}

void World::updateNext()
{
	for (int i = 0; i < chunck->h; i++) {
		chunck->levels[i][World::right] = chunck->levels[i][World::currnet];
		chunck->levels[i][World::right].x = World::right;

		chunck->levels[i][World::currnet] = chunck->levels[i][World::left];
		chunck->levels[i][World::currnet].x = World::currnet;

		chunck->levels[i][World::left].generateClear();
	}

	int index = chunck->levels[1][World::currnet].index - 1;

	if (memory.find(index) == memory.end())
	{
		cout << "NOT FOUND" << endl;
	}
	else
	{
		cout << "FOUND" << endl;
	}

	chunck->generate(World::left, index);
}
