#include "Game.h"

Game::Game()
{
	cout << "CCraft ver-0.3" << endl;
}

void Game::start()
{
	Image icon;
	icon.loadFromFile("res/icon.png");

	RenderWindow window(VideoMode(w, h), "CCraft");
	window.setIcon(32, 32, icon.getPixelsPtr());

	Chunck chunck;
	Player player(chunck);
	Camera camera(player, h, w);
	Control control(camera, player);
	Graphic graphic(chunck, player, w, h);
	Clock clock;

	while (window.isOpen())
	{
		tick += clock.getElapsedTime().asMicroseconds();
		clock.restart();

		if (tick > temp)
		{
			control.checkControl(window);

			player.update();
			camera.update();

			tick = 0;
		}

		window.setView(camera.getView());
		window.clear();
		graphic.draw(window);
		window.display();
	}
}
