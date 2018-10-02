#include "Memory.h"

Memory::Memory()
{
}

bool Memory::hasLvl(int index)
{
	return !(lvls.find(index) == lvls.end());
}

void Memory::addLvl(Level *level, int index)
{
	lvls.insert(pair<int, Level>(index, *level));
}

void Memory::updateLvl(Level * level)
{
	if (hasLvl(level->index)) lvls[level->index] = *level;
}

Level & Memory::getLvl(int index)
{
	return lvls.find(index)->second;
}
