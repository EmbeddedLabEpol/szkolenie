#include "Ball.h"

Ball::Ball(double x, double y, int r): sf::CircleShape(r), speed(10.0), directionX(-1), directionY(-1)
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
void Ball::bounceWall()
{
	/* if ball at most right of screen then reverse ball's x heading */
	if(((this->getPosition().x+this->getRadius() > 1024) || (this->getPosition().x-this->getRadius() < 0)))
	{
		directionX = -directionX;

	}

	/* check if ball's location at top or bottom of screen,if true reverse ball's y heading */
	if(((this->getPosition().y+this->getRadius() > 768) || (this->getPosition().y+this->getRadius() < 0))) 
	{
	   directionY = -directionY;
	}

}
void Ball::bounce(sf::RectangleShape shape)
{	
	if(this->getPosition().x > shape.getPosition().x) //lece z prawej
	{
		if(this->getPosition().y > shape.getPosition().y ) //lece z dolu
		{
			directionY = 1;
		} else	//lece z gory
		{
			directionY = -1;
		}
		
	}
	else // lece z lewej
	{
		if(this->getPosition().y > shape.getPosition().y ) //lece z dolu
		{
			directionY = 1;
		} else	//lece z gory
		{
			directionY = -1;
		}
	}
	
	//directionX = _directionX;
	//directionY = _directionY;
}

bool Ball::checkColision(sf::RectangleShape shape)
{	
	bool b = false;
	sf::FloatRect rbound = shape.getGlobalBounds();
	b = rbound.intersects(this->getGlobalBounds());
	
	if(b) 
	{
		this->bounce(shape);
	}
	
	return b;
}

void Ball::checkWallColision(sf::RectangleShape shape)
{
	bool b = false;
	sf::FloatRect rbound = shape.getGlobalBounds();
	b = rbound.intersects(this->getGlobalBounds());
	
	if(b) 
	{
		this->bounceWall();
	}
}

bool Ball::checkColision(Block block)
{	
	bool b = block.is_colision(this->getPosition().x, this->getPosition().y, this->getRadius());
	if(b) 
	{
		this->bounce(block);
	}
	return b;
}
