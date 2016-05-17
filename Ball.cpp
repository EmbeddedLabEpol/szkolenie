#include "Ball.h"

Ball::Ball(double x, double y, int r): sf::CircleShape(r), speed(2.0), directionX(1), directionY(-1)
{	
	this->setOrigin(this->getRadius(), this->getRadius());
	this->setPosition(x, y);
	this->setFillColor(sf::Color::Blue);
	
	this->setOutlineThickness(5);
	this->setOutlineColor(sf::Color::Red);
	
	//sf::Texture texture;
	//texture.loadFromFile("../ruda.png");
	//this->setTexture(&texture);
}

Ball::~Ball()
{
	
}

void Ball::move() 
{
	this->setPosition(getX() + (directionX * speed), 
					  getY() + (directionY * speed));
}

double Ball::getX()
{
	return this->getPosition().x;
}

double Ball::getY()
{
	return this->getPosition().y;
}

void Ball::speedUp()
{	
	if(speed < 2)
		speed += 0.1;
}

void Ball::slowDown()
{	
	if(speed > 0)
		speed -= 0.1;
}

void Ball::bounce(int _directionX, int _directionY)
{
	directionX = _directionX;
	directionY = _directionY;
}

void Ball::checkColision(sf::RectangleShape shape)
{	
	bool b = false;
	sf::FloatRect rbound = shape.getGlobalBounds();
	b = rbound.intersects(this->getGlobalBounds());
	
	if(b) 
	{
		this->bounce(-directionX,-directionY);
	}
}

void Ball::checkColision(Block block)
{	
	if(block.is_colision(this->getPosition().x, this->getPosition().y, this->getRadius())) 
	{
		this->bounce(-directionX,-directionY);
	}
}
