#include "Block.h"

Block::Block()
{
}

Block::Block(int index)
{
	this->index = index;
	this->isSolid = index == 3 || index == 4 || index == 19;
}
