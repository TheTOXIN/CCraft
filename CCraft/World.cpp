#include "World.h"

void World::print()
{
	for (int ci = 0; ci < h; ci++)
	{
		for (int cj = 0; cj < w; cj++)
		{
			Chunck chunck = chuncks[ci][cj];
			cout << "CHUNCK = " << chunck.x << ":" << chunck.y << endl;
			chunck.print();
		}
	}
}

World::World()
{
	render();
}

void World::render()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			chuncks[i][j].generateTest();
			chuncks[i][j].x = j;
			chuncks[i][j].y = i;
		}
	}
}
