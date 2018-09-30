#include "Block.h"

Block::Block()
{
	
}

Block::Block(int index)//TODO
{
	this->index = index;
	this->isSolid = index == 3 || index == 4 || index == 19 || index == 5 || index == 2;
}

void Block::init()
{
}
