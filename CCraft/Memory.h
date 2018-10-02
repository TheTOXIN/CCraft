#pragma once

#include "Level.h"
#include "map"

class Memory
{
public:
	Memory();

	map <int, Level> lvls;

	bool hasLvl(int index);
	void addLvl(Level *level, int index);
	void updateLvl(Level *level);
	Level& getLvl(int index);
};
