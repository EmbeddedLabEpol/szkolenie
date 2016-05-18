#include "Ball.h"

Ball::Ball(double x, double y, int r, double s = 10.0): sf::CircleShape(r), speed(s), directionX(-1), directionY(-1)
{	
	this->setOrigin(this->getRadius(), this->getRadius());
	this->setPosition(x, y);
	this->setFillColor(sf::Color::Green);
	
	this->setOutlineThickness(1);
	this->setOutlineColor(sf::Color::Red);
	
	//sf::Texture texture;
	//texture.loadFromFile("../ruda.png");
	//setTexture(&texture);
	/*f::Texture lifeTexture;
	if (!lifeTexture.loadFromFile("../joint.png"))
	{
		// error...
	}
	//lifeIcon.setSize(sf::Vector2f(80,60));
	
	this->setTexture(&lifeTexture);*/
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
		speed += 5;
}

void Ball::slowDown()
{	
	if(speed > 0)
		speed -= 5;
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


	if(this->getPosition().y + this->getRadius() + 10 > (rect.top + rect.height))

	{
	   directionY = -directionY;
	   this->setPosition(512,700);
		dead = true;
	}
	
	if(this->getPosition().y - this->getRadius() - 10< rect.top)
	{
		directionY = -directionY;
		
	}

}
void Ball::bounce(sf::RectangleShape shape)
{	
	sf::FloatRect fs = shape.getGlobalBounds();
	int x1 = fs.left;
	int x2 = fs.left + fs.width;
	int y1 = fs.top;
	int y2 = fs.top + fs.height;
	
	//bool poziom = false;
	//bool pion = false;
	
	if(this->getPosition().x > x1 && this->getPosition().x < x2)
	{
		directionY = -directionY;
	}
		//poziom = true;
	if(this->getPosition().y > y1 && this->getPosition().y < y2)
	{
		directionX = -directionX;
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
