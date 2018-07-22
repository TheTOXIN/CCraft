#include "Graphic.h"

Graphic::Graphic(World &world, Player &player, int w, int h)
{
	this->world = &world;
	this->player = &player;

	this->w = w;
	this->h = h;

	load();
}

void Graphic::draw(RenderWindow &window)
{
	///*

	for (int ci = 0; ci < world->h; ci++) 
	{
		for (int cj = 0; cj < world->w; cj++)
		{
			back.setPosition(cj * w, ci * h);
			window.draw(back);

			Chunck chunck = world->chuncks[0][0];
			for (int i = 0; i < chunck.h; i++)
			{
				for (int j = 0; j < chunck.w; j++)
				{
					int index = chunck.blocks[i][j].index;
					
					if (index != 0)
					{
						if (index == 54)
							textures.sprite.setColor(Color::Green);
						else
							textures.sprite.setColor(Color::White);

						textures.sprite.setTextureRect(IntRect(Block::size * ((index - 1) % 16), 32 * (int)((index - 1) / 16), Block::size, Block::size));
						textures.sprite.setPosition(j * Block::size + (w * cj), i * Block::size + magic + (h * ci));
						window.draw(textures.sprite);
					}
				}
			}
		}
	}
	//*/
	RectangleShape shape(Vector2f(player->rect.width, player->rect.height));
	shape.setPosition(player->rect.left, player->rect.top);
	//window.draw(shape);

	window.draw(player->head);
	window.draw(player->body);
	window.draw(player->arm1);
	window.draw(player->arm2);
	window.draw(player->leg1);
	window.draw(player->leg2);
}

void Graphic::load()
{	
	back.setSize(Vector2f(w, h));
	back.setFillColor(Color(100, 215, 250));

	logo.init("res/logo.png", 845, 200);
	logo.sprite.setPosition(w / 2 - logo.w / 2, 0);

	textures.init("res/textures.png", 512, 512);
}

