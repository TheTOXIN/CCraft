#include "Control.h"
#include "Math.h"

Control::Control()
{
}

Control::Control(Camera & camera, Player & player, Chunck &chunck, World &world)
{
	this->camera = &camera;
	this->player = &player;
	this->chunck = &chunck;
	this->world = &world;
}

void Control::checkControl(RenderWindow & window)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
		if (event.type == Event::KeyReleased) {
			player->state = state::none;
			this->hasGenerate = false;
		}
		if (event.type == Event::MouseButtonReleased)
			this->hasClick = false;
		if (event.type == Event::MouseWheelScrolled)
			player->c_block += event.mouseWheelScroll.delta;
	}

	controlKeyboardPlayer(window);
	controlClickPlayer(window);
	controlCamera(window);
	controlWorld(window);
}

void Control::controlCamera(RenderWindow & window)
{
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		this->camera->moveUp();
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		this->camera->moveDown();
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		this->camera->moveRight();
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		this->camera->moveLeft();
	}

	if (Keyboard::isKeyPressed(Keyboard::RShift))
		this->camera->toIncrease();
	else if (Keyboard::isKeyPressed(Keyboard::RControl))
		this->camera->toReduce();

	if (Keyboard::isKeyPressed(Keyboard::RAlt))
		this->camera->reset();
}

void Control::controlWorld(RenderWindow & window)
{
	if (Keyboard::isKeyPressed(Keyboard::Q) && !hasGenerate) {
		world->updatePrev();
		this->hasGenerate = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::E) && !hasGenerate) {
		world->updateNext();
		this->hasGenerate = true;
	}
}

void Control::controlKeyboardPlayer(RenderWindow &window)
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		player->state = state::up;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		player->state = state::down;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player->state = state::right;
	} 
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player->state = state::left;
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		player->state = state::jump;
	}
}

void Control::controlClickPlayer(RenderWindow & window)
{
	Vector2f mouse_pos = window.mapPixelToCoords(Mouse::getPosition(window));

	int x = mouse_pos.x;
	int y = mouse_pos.y;

	if (Mouse::isButtonPressed(Mouse::Right) && !hasClick)
	{
		if (!player->validClick(x, y)) return;
		chunck->createBlock(x, y, player->c_block);
		this->hasClick = true;
	}

	if (Mouse::isButtonPressed(Mouse::Left) && !hasClick)
	{
		if (!player->validClick(x, y)) return;
		chunck->destroyBlock(x, y);
		this->hasClick = true;
	}
}
