#include "Player.h"
#include "Game.h"

Player::Player()
{
	
}

Player::Player(Chunck & chunck)
{
	this->chunck = &chunck;
	this->level = &chunck.levels[1][1];

	this->x = Game::w / 2 + Game::w * level->x;
	this->y = Game::h / 2 + Game::h * level->y;

	this->dx = 0;
	this->dy = 0;
	this->r = 0;
	this->j = 0;
	this->r_area = 4;
	this->c_block = 5;

	onGround = false;
	rect = FloatRect(x - 8, y, 32, 64);
	state = state::none;

	init();
	move();
	spawn();
}

bool Player::validClick(int cx, int cy)
{
	int s = sqrt(pow(cx - (this->x + 8), 2) + pow(cy - (this->y + 32), 2));
	return s <= this->r_area * Block::size;
}

void Player::spawn()
{
	while (checkY(false)) {
		this->y--;
		rect.top--;
	}
}

void Player::update()
{
	if (!onGround) dy = 3;

	move();

	y += dy;
	x += dx;
	
	rect.left = x - 8;
	rect.top = y;
	
	bool isX = checkX();
	if (isX) x -= dx;
	onGround = false;

	if (checkY(isX))
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
	//WARING FUCKING MAGIC
	//TODO x level
	level = &chunck->levels[((int)(rect.top) + 64) / Game::h][((int)(rect.left) + 32) / Game::w];
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
	d = 3;
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
	if (j < 16)
		dy = -3;
	else
		return;

	onGround = false;
}

void Player::left()
{
	renderLeft();
	animateLeft();
	
	dx = -3;
}

void Player::right()
{
	renderRight();
	animateRight();
	
	dx = 3;
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

	int tmpX = rect.left - Game::w * level->x;
	int tmpY = rect.top - Game::h * level->y;

	int i1 = (tmpY + 16) / Block::size;
	int i2 = (tmpY + 32) / Block::size;
	int i3 = (tmpY + 48) / Block::size;

	int j1 = (tmpX + 8) / Block::size;
	int j2 = (tmpX + 24) / Block::size;
	
	return level->blocks[i1][j1].isSolid || level->blocks[i2][j1].isSolid || level->blocks[i3][j1].isSolid
		    ||
		    level->blocks[i1][j2].isSolid || level->blocks[i2][j2].isSolid || level->blocks[i3][j2].isSolid;
}

bool Player::checkY(bool blya)
{
	//WARING FUCKING MAGIC

	int tmpX = rect.left - Game::w * level->x;
	int tmpY = rect.top - Game::h * level->y;

	int i = (tmpY + 64) / Block::size;
	int j1 = (tmpX + 8) / Block::size;
	int j2 = (tmpX + 24) / Block::size;

	bool b1 = level->blocks[i][j1].isSolid;
	bool b2 = level->blocks[i][j2].isSolid;

	if (blya) return (!b1 || b2) && (!b2 || b1);
	
	return b1 || b2;
}

void Player::init()
{
	texture.loadFromFile("res/steve_2.png");
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

	head.setTextureRect(IntRect(32/2, 32 / 2, 32 / 2, 32 / 2));
	body.setTextureRect(IntRect(80 / 2, 80 / 2, 32 / 2, 48 / 2));
	arm1.setTextureRect(IntRect(176 / 2, 80 / 2, 16 / 2, 48 / 2));
	arm2.setTextureRect(IntRect(208 / 2, 80 / 2, 16 / 2, 48 / 2));
	leg1.setTextureRect(IntRect(16 / 2, 80 / 2, 16 / 2, 48 / 2));
	leg2.setTextureRect(IntRect(48 / 2, 80 / 2, 16 / 2, 48 / 2));

	head.setPosition(x, y);
	body.setPosition(x, y + 32 / 2);
	arm1.setPosition(x, y + 32 / 2);
	arm2.setPosition(x + 32 / 2, y + 32 / 2);
	leg1.setPosition(x + 16 / 2, y + 32 / 2 + 48 / 2);
	leg2.setPosition(x + 16 / 2, y + 32 / 2 + 48 / 2);
}

void Player::renderLeft()
{
	head.setTextureRect(IntRect(64 / 2, 32 / 2, 32 / 2, 32 / 2));
	body.setTextureRect(IntRect(112 / 2, 80 / 2, 16 / 2, 48 / 2));
	arm2.setTextureRect(IntRect(160 / 2, 80 / 2, 16 / 2, 48 / 2));
	arm1.setTextureRect(IntRect(192 / 2, 80 / 2, 16 / 2, 48 / 2));
	leg2.setTextureRect(IntRect(0 / 2, 80 / 2, 16 / 2, 48 / 2));
	leg1.setTextureRect(IntRect(32 / 2, 80 / 2, 16 / 2, 48 / 2));

	head.setPosition(x, y);
	body.setPosition(x + 8 / 2, y + 32 / 2);
	arm1.setPosition(x + 24 / 2, y + 32 / 2);
	arm2.setPosition(x + 8 / 2, y + 32 / 2);
	leg1.setPosition(x + 24 / 2, y + 32 / 2 + 48 / 2);
	leg2.setPosition(x + 8 / 2, y + 32 / 2 + 48 / 2);
}

void Player::renderRight()
{
	head.setTextureRect(IntRect(0 / 2, 32 / 2, 32 / 2, 32 / 2));
	body.setTextureRect(IntRect(64 / 2, 80 / 2, 16 / 2, 48 / 2));
	arm1.setTextureRect(IntRect(160 / 2, 80 / 2, 16 / 2, 48 / 2));
	arm2.setTextureRect(IntRect(192 / 2, 80 / 2, 16 / 2, 48 / 2));
	leg1.setTextureRect(IntRect(0 / 2, 80 / 2, 16 / 2, 48 / 2));
	leg2.setTextureRect(IntRect(32 / 2, 80 / 2, 16 / 2, 48 / 2));

	head.setPosition(x, y);
	body.setPosition(x + 8 / 2, y + 32 / 2);
	arm2.setPosition(x + 8 / 2, y + 32 / 2);
	arm1.setPosition(x + 24 / 2, y + 32 / 2);
	leg2.setPosition(x + 8 / 2, y + 32 / 2 + 48 / 2);
	leg1.setPosition(x + 24 / 2, y + 32 / 2 + 48 / 2);
}

void Player::renderBack()
{
	head.setTextureRect(IntRect(96 / 2, 32 / 2, 32 / 2, 32 / 2));
	body.setTextureRect(IntRect(128 / 2, 80 / 2, 32 / 2, 48 / 2));
	arm2.setTextureRect(IntRect(160 / 2, 80 / 2, 16 / 2, 48 / 2));
	arm1.setTextureRect(IntRect(192 / 2, 80 / 2, 16 / 2, 48 / 2));
	leg2.setTextureRect(IntRect(0 / 2, 80 / 2, 16 / 2, 48 / 2));
	leg1.setTextureRect(IntRect(32 / 2, 80 / 2, 16 / 2, 48 / 2));

	head.setPosition(x, y);
	body.setPosition(x, y + 32 / 2);
	arm1.setPosition(x, y + 32 / 2);
	arm2.setPosition(x + 32 / 2, y + 32 / 2);
	leg1.setPosition(x + 16 / 2, y + 32 / 2 + 48 / 2);
	leg2.setPosition(x + 16 / 2, y + 32 / 2 + 48 / 2);
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
	head.setTextureRect(IntRect(32 / 2, 0, 32 / 2, 32 / 2));
	
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
	arm1.setOrigin(16 / 2, 0);
	arm2.setOrigin(0, 0);
	leg1.setOrigin(16 / 2, 0);
	leg2.setOrigin(0, 0);

	arm1.setRotation(0);
	arm2.setRotation(0);
	leg1.setRotation(0);
	leg2.setRotation(0);
}

void Player::moveNext()
{
	this->x = this->x + Level::w * Block::size;
	this->rect.left = this->rect.left + Level::w * Block::size;
}

void Player::movePrev()
{
	this->x = this->x - Level::w * Block::size;
	this->rect.left = this->rect.left - Level::w * Block::size;
}
