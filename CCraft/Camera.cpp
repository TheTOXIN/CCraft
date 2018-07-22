#include "Camera.h"

Camera::Camera()
{
}

Camera::Camera(Player & player, int h, int w)
{
	this->w = w;
	this->h = h;
	this->player = &player;
	this->view = View();
	this->view.reset(FloatRect(0, 0, w, h));
}

View Camera::getView()
{
	return this->view;
}

void Camera::setView(View & view)
{
	this->view = view;
}

void Camera::update()
{
	int tmpX = player->x + 16;
	int tmpY = player->y + 64;

	this->view.setCenter(tmpX + this->x, tmpY + this->y);
}

void Camera::reset()
{
	this->view.reset(FloatRect(0, 0, w, h));
	this->x = 0;
	this->y = 0;
}

void Camera::moveLeft()
{
	this->x -= this->SPEED;
}

void Camera::moveRight()
{
	this->x += this->SPEED;
}

void Camera::moveUp()
{
	this->y -= this->SPEED;
}

void Camera::moveDown()
{
	this->y += this->SPEED;
}

void Camera::toReduce()
{
	this->view.zoom(1.005);
}

void Camera::toIncrease()
{
	this->view.zoom(0.995);
}
