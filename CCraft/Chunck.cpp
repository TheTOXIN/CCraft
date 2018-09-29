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
	generate();
}

void Chunck::generate()
{
	int left = 0;
	int current = 1;
	int right = 2;

	for (int i = 0; i < h; i++)
	{
		levels[i][current].generateLevel(i);
		levels[i][current].x = current;
		levels[i][current].y = i;
	}
}
