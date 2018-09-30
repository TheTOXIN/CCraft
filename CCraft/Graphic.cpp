#include "Graphic.h"

Graphic::Graphic(Chunck &chunck, Player &player, int w, int h)
{
	this->chunck = &chunck;
	this->player = &player;

	this->w = w;
	this->h = h;

	load();
}

void Graphic::draw(RenderWindow &window)
{
	for (int ci = 0; ci < chunck->h; ci++) 
	{
		for (int cj = 0; cj < chunck->w; cj++)
		{
			back.setPosition(cj * w, ci * h);
			window.draw(back);

			Level level = chunck->levels[ci][cj];
			for (int i = 0; i < level.h; i++)
			{
				for (int j = 0; j < level.w; j++)
				{
					int index = level.blocks[i][j].index;
					
					if (index != 0)
					{
						if (index == 54)
							textures.sprite.setColor(Color::Green);
						else
							textures.sprite.setColor(Color::White);

						textures.sprite.setTextureRect(IntRect(Block::size * ((index - 1) % 16), 32 * (int)((index - 1) / 16), Block::size, Block::size));
						textures.sprite.setPosition(j * Block::size + (w * cj), i * Block::size + (h * ci));
						window.draw(textures.sprite);
					}
				}
			}
		}
	}
	
	//RectangleShape shape(Vector2f(player->rect.width, player->rect.height));
	//shape.setPosition(player->rect.left, player->rect.top);
	//window.draw(shape);

	Vector2f mouse_pos = window.mapPixelToCoords(Mouse::getPosition(window));
	cursor.sprite.setPosition(mouse_pos.x - 16, mouse_pos.y - 16);
	window.draw(cursor.sprite);

	window.draw(player->head);
	window.draw(player->body);
	window.draw(player->arm1);
	window.draw(player->arm2);
	window.draw(player->leg1);
	window.draw(player->leg2);
}

void Graphic::renderWorld(RenderWindow & window, World & world)
{
}

void Graphic::renderChunck(RenderWindow & window, Chunck & chunk)
{
}

void Graphic::renderLevel(RenderWindow & window, Level & level)
{
}

void Graphic::renderBlock(RenderWindow & window, Block & block)
{
}

void Graphic::renderPlayer(RenderWindow & window, Player & player)
{
}

void Graphic::load()
{	
	back.setSize(Vector2f(w, h));
	back.setFillColor(Color(100, 215, 250));

	logo.init("res/logo.png", 845, 200);
	logo.sprite.setPosition(w / 2 - logo.w / 2, 0);

	textures.init("res/textures.png", 512, 512);

	cursor.init("res/cursor.png", 32, 32);
}

