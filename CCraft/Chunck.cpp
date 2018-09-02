#include "Chunck.h"

void Chunck::print()
{
	for (int ci = 0; ci < h; ci++)
	{
		for (int cj = 0; cj < w; cj++)
		{
			Level chunck = levels[ci][cj];
			cout << "CHUNCK = " << chunck.x << ":" << chunck.y << endl;
			chunck.print();
		}
	}
}

Chunck::Chunck()
{
	render();
}

void Chunck::render()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			levels[i][j].generateTest();
			levels[i][j].x = j;
			levels[i][j].y = i;
		}
	}
}
