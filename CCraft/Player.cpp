#include "Player.h"
#include "Game.h"

Player::Player()
{
	
}

Player::Player(World & world)
{
	this->world = &world;
	this->chunck = &world.chuncks[1][0];

	this->x = 600 + Game::w * chunck->x;
	this->y = 400 + Game::h * chunck->y;

	this->dx = 0;
	this->dy = 0;
	this->r = 0;
	this->j = 0;

	onGround = false;
	rect = FloatRect(x - 16, y, 64, 128);
	state = state::none;

	init();
	move();
}

void Player::update()
{
	if (!onGround) 
		dy = 2;

	move();

	y += dy;
	x += dx;
	
	rect.left = x - 16;
	rect.top = y;

	if (checkX())
		x -= dx;

	onGround = false;

	if (checkY())
	{
		onGround = true;
		dy = 0;
		j = 0;
	}

	//int cx = Game::w % ((int)(rect.left));
	//int cy = Game::h % ((int)(rect.top));
	//cout << "cx =" << Game::w << " % " << ((int)(rect.left)) << " = " << cx << endl;
	//cout << "cy =" << Game::h << " % " << ((int)(rect.top)) << " = " << cy << endl;
	//cout << "CHANCK:" << "x = " << cx << " " << "y = " << cy << endl;
	chunck = &world->chuncks[((int)(rect.top)) / Game::h][((int)(rect.left)) / Game::w];
}

void Player::move()
{	
	if (this->state == state::none)
		none();
	else if (this->state == state::left)
		left();
	else if (this->state == state::right)
		right();
	else if (this->state == state::down)
		down();
	else if (this->state == state::up)
		up();

	if (this->state == state::jump)
		jump();
}

void Player::none()
{
	r = 0;
	d = 1;
	dx = 0;
	renderFront();
}

void Player::jump()
{
	if (dx > 0)
		renderRight();
	else if (dx < 0)
		renderLeft();
	else
		renderFront();
	
	animateJump();

	j++;
	if (j < 32)
		dy = -3;
	else
		return;

	onGround = false;
}

void Player::left()
{
	renderLeft();
	animateLeft();
	
	dx = -1;
}

void Player::right()
{
	renderRight();
	animateRight();
	
	dx = 1;
}

void Player::down()
{
	renderFront();
	animateSit();
}

void Player::up()
{
	renderBack();
}

bool Player::checkX()
{
	//WARING FUCKING MAGIC

	int tmpX = rect.left - Game::w * chunck->x;
	int tmpY = rect.top - Game::h * chunck->y;

	int i1 = (tmpY + 32) / Block::size;
	int i2 = (tmpY + 64) / Block::size;
	int i3 = (tmpY + 96) / Block::size;

	int j1 = (tmpX + 16) / Block::size;
	int j2 = (tmpX + 48) / Block::size;

	
	return (chunck->blocks[i1][j1].isSolid || chunck->blocks[i2][j1].isSolid || chunck->blocks[i3][j1].isSolid
		    ||
		    chunck->blocks[i1][j2].isSolid || chunck->blocks[i2][j2].isSolid || chunck->blocks[i3][j2].isSolid);
		
	return true;
}

bool Player::checkY()
{
	//WARING FUCKING MAGIC

	int tmpX = rect.left - Game::w * chunck->x;
	int tmpY = rect.top - Game::h * chunck->y;

	int i = (tmpY + 112) / Block::size;
	int j1 = (tmpX + 16) / Block::size;
	int j2 = (tmpX + 48) / Block::size;

	return (chunck->blocks[i][j1].isSolid || (chunck->blocks[i][j2].isSolid));
}

void Player::init()
{
	texture.loadFromFile("res/steve.png");
	head.setTexture(texture);

	body.setTexture(texture);
	arm1.setTexture(texture);
	arm2.setTexture(texture);
	leg1.setTexture(texture);
	leg2.setTexture(texture);
}

void Player::renderFront()
{
	default();

	head.setTextureRect(IntRect(32, 32, 32, 32));
	body.setTextureRect(IntRect(80, 80, 32, 48));
	arm1.setTextureRect(IntRect(176, 80, 16, 48));
	arm2.setTextureRect(IntRect(208, 80, 16, 48));
	leg1.setTextureRect(IntRect(16, 80, 16, 48));
	leg2.setTextureRect(IntRect(48, 80, 16, 48));

	head.setPosition(x, y);
	body.setPosition(x, y + 32);
	arm1.setPosition(x, y + 32);
	arm2.setPosition(x + 32, y + 32);
	leg1.setPosition(x + 16, y + 32 + 48);
	leg2.setPosition(x + 16, y + 32 + 48);
}

void Player::renderLeft()
{
	head.setTextureRect(IntRect(64, 32, 32, 32));
	body.setTextureRect(IntRect(112, 80, 16, 48));
	arm2.setTextureRect(IntRect(160, 80, 16, 48));
	arm1.setTextureRect(IntRect(192, 80, 16, 48));
	leg2.setTextureRect(IntRect(0, 80, 16, 48));
	leg1.setTextureRect(IntRect(32, 80, 16, 48));

	head.setPosition(x, y);
	body.setPosition(x + 8, y + 32);
	arm1.setPosition(x + 24, y + 32);
	arm2.setPosition(x + 8, y + 32);
	leg1.setPosition(x + 24, y + 32 + 48);
	leg2.setPosition(x + 8, y + 32 + 48);
}

void Player::renderRight()
{
	head.setTextureRect(IntRect(0, 32, 32, 32));
	body.setTextureRect(IntRect(64, 80, 16, 48));
	arm1.setTextureRect(IntRect(160, 80, 16, 48));
	arm2.setTextureRect(IntRect(192, 80, 16, 48));
	leg1.setTextureRect(IntRect(0, 80, 16, 48));
	leg2.setTextureRect(IntRect(32, 80, 16, 48));

	head.setPosition(x, y);
	body.setPosition(x + 8, y + 32);
	arm2.setPosition(x + 8, y + 32);
	arm1.setPosition(x + 24, y + 32);
	leg2.setPosition(x + 8, y + 32 + 48);
	leg1.setPosition(x + 24, y + 32 + 48);
}

void Player::renderBack()
{
	head.setTextureRect(IntRect(96, 32, 32, 32));
	body.setTextureRect(IntRect(128, 80, 32, 48));
	arm2.setTextureRect(IntRect(160, 80, 16, 48));
	arm1.setTextureRect(IntRect(192, 80, 16, 48));
	leg2.setTextureRect(IntRect(0, 80, 16, 48));
	leg1.setTextureRect(IntRect(32, 80, 16, 48));

	head.setPosition(x, y);
	body.setPosition(x, y + 32);
	arm1.setPosition(x, y + 32);
	arm2.setPosition(x + 32, y + 32);
	leg1.setPosition(x + 16, y + 32 + 48);
	leg2.setPosition(x + 16, y + 32 + 48);
}

void Player::animateJump()
{
	animate();
	arm1.setRotation(r);
	arm2.setRotation(-r);
	leg1.setRotation(r);
	leg2.setRotation(-r);
}

void Player::animateLeft()
{
	animate();
	arm1.setRotation(-r);
	arm2.setRotation(r);
	leg1.setRotation(r);
	leg2.setRotation(-r);
}

void Player::animateRight()
{
	animate();
	arm1.setRotation(-r);
	arm2.setRotation(r);
	leg1.setRotation(r);
	leg2.setRotation(-r);
}

void Player::animateSit()
{
	head.setTextureRect(IntRect(32, 0, 32, 32));
	
	head.setPosition(x, y + 2);
	body.setPosition(x, y + 34);

	r += 1;
	if (r > 10)
		r = 10;

	arm1.setRotation(r);
	arm2.setRotation(-r);
}

void Player::animate()
{
	r += d;
	if (r > 30 || r < 0)
		d = -d;
}

void Player::default()
{
	arm1.setOrigin(16, 0);
	arm2.setOrigin(0, 0);
	leg1.setOrigin(16, 0);
	leg2.setOrigin(0, 0);

	arm1.setRotation(0);
	arm2.setRotation(0);
	leg1.setRotation(0);
	leg2.setRotation(0);
}