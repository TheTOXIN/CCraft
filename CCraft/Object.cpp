#include "Object.h"

Object::Object()
{
}

Object::Object(string path, int w, int h)
{
	this->init(path, w, h);
}

void Object::init(string path, int w, int h)
{
	this->texture.loadFromFile(path);
	this->sprite.setTexture(this->texture);
	this->h = h;
	this->w = w;
}

