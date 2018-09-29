#include "iostream"
#include "Game.h"
#include "time.h"

using namespace std;

int main()
{
	srand(time(NULL));

	Game game;
	game.start();
	
	return 1;
}