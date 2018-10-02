#include "Game.h"
#include "World.h"

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
	window.setMouseCursorVisible(false);

	Memory memory;
	Chunck chunck(memory);
	Player player(chunck);
	World world(player, chunck, memory);
	Camera camera(player, h / 2, w / 2);
	Control control(camera, player, chunck, world);
	Graphic graphic(chunck, player, w, h);//only world
	Clock clock;

	while (window.isOpen())
	{
		tick += clock.getElapsedTime().asMicroseconds();
		clock.restart();

		if (tick > temp)
		{
			control.checkControl(window);

			player.update();
			world.update();
			camera.update();

			tick = 0;
		}

		window.setView(camera.getView());
 		window.clear();
		graphic.draw(window);
		window.display();
	}
}
