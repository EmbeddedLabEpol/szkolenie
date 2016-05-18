#include "Ball.h"

Ball::Ball(double x, double y, int r, double s = 10.0): sf::CircleShape(r), speed(s), directionX(-1), directionY(-1)
{	
	this->setOrigin(this->getRadius(), this->getRadius());
	this->setPosition(x, y);
	this->setFillColor(sf::Color::Green);
	
	this->setOutlineThickness(1);
	this->setOutlineColor(sf::Color::Red);
	
	sf::Texture texture;
	texture.loadFromFile("../ruda.png");
	this->setTexture(&texture);
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
	if(speed < 20)
		speed += 1;
}

void Ball::slowDown()
{	
	if(speed > 0)
		speed -= 1;
}

void Ball::setSpeed(double s)
{
	if(s > 0 && s < 20)
		this->speed = s;
}

void Ball::bouncePaddle(int side)
{
	switch(side) {
	case 1:
		directionX = -directionX;
		directionY = -directionY;
		break;
	case 2:
		directionY = -directionY;
		break;
	case 3:
		directionX = -directionX;
		directionY = -directionY;
		break;
	default:
		break;

	}
}
void Ball::bounceWall(sf::FloatRect rect)
{
	
	if(((this->getPosition().x + this->getRadius() + 10 > (rect.left + rect.width)) || 
		(this->getPosition().x - this->getRadius()  -10 < rect.left)))
	{
		directionX = -directionX;
	}

	if(((this->getPosition().y + this->getRadius() + 10 > (rect.top + rect.height)) || 
		(this->getPosition().y - this->getRadius() - 10< rect.top))) 
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

void Ball::checkWallColision(sf::FloatRect rect)
{
	bool b = false;
	//sf::FloatRect rbound = shape.getGlobalBounds();
	b = rect.intersects(this->getGlobalBounds());

	if(b) 
	{
		this->bounceWall(rect);
	}
}

bool Ball::checkColision(Block &block)
{	
	//sf::FloatRect rbound = block.getGlobalBounds();
	//bool b = rbound.intersects(this->getGlobalBounds());
	bool b = block.is_colision(this->getPosition().x, this->getPosition().y, this->getRadius());
	if(b) 
	{
		std::cout << "colision" << std::endl;
		this->bounce(block);
		block.state = false;
		std::cout<<block.state<<std::endl;
	}
	return b;
}
