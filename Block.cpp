#include "Block.h"
#include <math.h>

Block::Block(float x, float y):
sf::RectangleShape(sf::Vector2f(40, 20)),
state(false)
{
	this->setPosition(x, y);
	this->setFillColor(sf::Color::Blue);
	this->setOutlineColor(sf::Color::Black);
	this->setOutlineThickness(5);
}

Block::~Block()
{
}

bool Block::is_colision(float xc, float yc, float r)
{
	const float xb = this->getPosition().x;
	const float yb = this->getPosition().y;
	const float l = this->getSize().x;
	const float h = this->getSize().y;
	
	const bool top = (xc + r) > xb;
	const bool left = (yc + r) > yb;
	
	const bool bottom = (xc - r) < (xb + l);
	const bool right = (yc - r) < (yb + h);
	
	const float x_top_left = xc - r * std::sin(45.);
	const float y_top_left = yc - r * std::cos(45.);
	
	const bool top_left_x = x_top_left > xb;
	const bool top_left_y = y_top_left > yb;
	
	const float x_top_right = xc + r * std::sin(45.);
	const float y_top_right = yc - r * std::cos(45.);
	
	const bool top_right_x = x_top_right < (xb + l);
	const bool top_right_y = y_top_right > yb;
	
	const float x_bottom_left = xc - r * std::sin(45.);
	const float y_bottom_left = yc + r * std::cos(45.);
	
	const bool bottom_left_x = x_bottom_left < xb;
	const bool bottom_left_y = y_bottom_left > (yb + h);
	
	const float x_bottom_right = xc + r * std::sin(45.);
	const float y_bottom_right = yc + r * std::cos(45.);
	
	const bool bottom_right_x = x_bottom_right > (xb + l);
	const bool bottom_right_y = y_bottom_right < (yb + h);
	
	if (top && bottom && left && right && top_left_x && top_left_y && top_right_x && top_right_y && bottom_left_x && bottom_left_y && bottom_right_x && bottom_right_y)
		return true;
	else
		return false;
}

void Block::set_state(float xc, float yc, float r)
{
	state = !is_colision(xc, yc, r);
}


float Block::get_size_x()
{
	return this->getSize().x + 5;
}

float Block::get_size_y()
{
	return this->getSize().y + 5;
}