#include "Control.h"

Control::Control()
{
}

Control::Control(Camera & camera, Player & player)
{
	this->camera = &camera;
	this->player = &player;
}

void Control::checkControl(RenderWindow & window)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
		if (event.type == Event::KeyReleased)
			player->state = state::none;
	}

	controlPlayer(window);
	controlCamera(window);
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

void Control::controlPlayer(RenderWindow &window)
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
