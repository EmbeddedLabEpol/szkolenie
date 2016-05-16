#include "Ball.h"
#include <iostream>

Ball::Ball(int i): sf::CircleShape(i)
{	
	sf::Texture texture;
	if (!texture.loadFromFile("../ruda.png"))
	{
		 std::cout << "error" << std::endl;
	}
	//this->setFillColor(sf::Color::White);
	this->setPosition(200,200);
	
	this->setTexture(&texture);
	this->setTextureRect(sf::IntRect(10, 10, 100, 100));

	
}

Ball::~Ball()
{
}

void Ball::color()
{
	//this->setFillColor(sf::Color::Black);
}

