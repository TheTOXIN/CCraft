#include "Level.h"
#include "math.h"

Level::Level()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			Block block(0);
			blocks[i][j] = block;
		}
	}
}

void Level::generate()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			Block block(208);
			blocks[i][j] = block;
		}
	}
}

void Level::generateTest()
{
	int map[h][w] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 3 },
		{ 0, 0, 0, 0, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3 },
		{ 0, 0, 0, 54, 54, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 3, 3 },
		{ 0, 0, 54, 54, 21, 54, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3 },
		{ 4, 0, 0, 54, 21, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 3, 3, 35, 3 },
		{ 3, 4, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 3, 3, 3, 2, 2, 35 },
		{ 3, 3, 4, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61, 0, 0, 19, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 2, 2, 2 },
		{ 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 19, 19, 208, 208, 208, 19, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
	};

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = map[i][j];//yeah magic
			Block block(index);
			blocks[i][j] = block;
		}
	}
}

void Level::generateLevel(int n)
{
	switch (n)
	{
	case 0: generateFirst(); break;
	case 1: generateSecond(); break;
	case 2: generateThird(); break;
	default: break;
	}
}

void Level::generateFirst()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			//SKY
		}
	}
}

void Level::generateSecond()
{
	int move_layer = 3;
	int start_pos = h / 2 + move_layer;

	//generate dirt by half level
	for (int i = start_pos; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			Block block(Block::DIRT);
			blocks[i][j] = block;
		}
	}

	int chance_tree = 10;
	int max_len_grass = 5;
	int max_len_stone = 3;
	int chance_flat = 1;
	int prev_len = max_len_grass;

	//generate layer grass and trees
	for (int i = 0; i < w; i++)
	{
		int len = prev_len;

		if (rand() % chance_flat == 0)
			len = rand() % max_len_grass;
		if (rand() % chance_flat == 0)
			len = abs(prev_len - len);

		int pos = start_pos - len;
		prev_len = len;

		Block blockGrass(Block::GRASS);
		blocks[pos][i] = blockGrass;

		int chance = rand() % chance_tree;
		if (chance == 0) generateTree(i, pos - 1);

		for (int j = pos + 1; j < start_pos; j++) {
			Block blockDirt(Block::DIRT);
			blocks[j][i] = blockDirt;
		}

		int pos_stone = h - rand() % max_len_stone;
		for (int j = pos_stone; j < h; j++) {
			Block blockDirt(Block::STONE);
			blocks[j][i] = blockDirt;
		}
	}
}

void Level::generateThird()
{
	//generate full level stone
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			Block block(Block::STONE);
			blocks[i][j] = block;
		}
	}
	
	int max_len = 5;
	//generate layer bedrock
	for (int i = 0; i < w; i++)
	{
		int len = rand() % max_len + 1;
		int pos = h - len;

		for (int j = pos; j < h; j++) {
			Block blockDirt(Block::BEDROCK);
			blocks[j][i] = blockDirt;
		}
	}
	
	const int count_ruds = 5;
	const int chace_spawn = 1;

	int ruds[count_ruds] = {
		Block::RUDA_UGOL, Block::RUDA_IRON, Block::RUDA_RED, Block::RUDA_GOLD, Block::RUDA_DIMOND
	};

	for (int i = 0; i < w; i++) {
		if (chace_spawn == 0) continue;

		int rare_rud = (rand() % count_ruds) + 1;
		int chance_rud = rand() % (rare_rud + 1);

		if (chance_rud == 0) {
			//cout << "r = " << rare_rud << " i = " << ruds[rare_rud - 1] << " p = " << i << endl;
			generateRes(rare_rud, ruds[rare_rud - 1], i);
		}
	}
}

void Level::generateRes(int rare, int index, int pos)
{
	int add_count = 2;
	int max_rare = 5;
	int max_spawn = 3;

	int deep = h / (max_rare - rare + 1) - rand() % max_spawn;
	int count = rand() % (max_rare - rare + 1) + add_count;
	
	Block block = Block(index);
	blocks[deep][pos] = block;

	int counter = 0;
	
	do
	{
		int x = pos + rand() % max_spawn;
		int y = deep + rand() % max_spawn;

		if (x <= w && x >= 0 && y <= h && y >= 0) {//Hmmm
			Block block = Block(index);
			blocks[y][x] = block;
			//cout << "X=" << x << " Y=" << y << "I=" << index << endl;
			counter++;
		}

	} while (counter < count);
}

void Level::generateTree(int tx, int ty)
{
	const int tree_h = 6;
	const int tree_w = 5;

	int move_to_centre = 2;

	int TREE[tree_h][tree_w] = {
		{ 0,  0,  54, 0,  0  },
		{ 0,  54, 54, 54, 0  },
		{ 54, 54, 21, 54, 54 },
		{ 0,  54, 21, 54, 0  },
		{ 0,  0,  21, 0,  0  },
		{ 0,  0,  21, 0,  0  }
	};

	for (int i = 0; i < tree_h; i++) {
		for (int j = 0; j < tree_w; j++) {
			if (TREE[i][j] != 0) {
				int dx = j + tx - move_to_centre;
				int dy = i + ty - tree_h + 1;

				if (dx <= w && dx >= 0 && dy <= h && dy >= 0) {//Hmmm
					Block block = Block(TREE[i][j]);
					blocks[dy][dx] = block;
				}
			}
		}
	}
}

void Level::print()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = blocks[i][j].index;
			cout << index << " ";
		}
		cout << endl;
	}
}
