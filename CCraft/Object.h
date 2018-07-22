#pragma once

#include "iostream"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Object
{
public:
	int w;
	int h;

	Object();
	Object(string path, int w, int h);

	Texture texture;
	Sprite sprite;

	void init(string path, int w, int h);
};
