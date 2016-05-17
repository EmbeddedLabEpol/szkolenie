#include "Block.h"
#include <math.h>

Block::Block(float x, float y):
sf::RectangleShape(sf::Vector2f(40, 20)),
state(true)
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
	//block params:
		
	const float l = this->getSize().x;
	const float h = this->getSize().y;
	const float x_left_block = this->getPosition().x;
	const float y_top_block = this->getPosition().y;
	const float x_right_block = x_left_block + l;
//	const float y_right_top_corner = y_left_top_corner;
//	const float x_left_bottom_corner = x_left_top_corner;
	const float y_bottom_block = y_top_block + h;
//	const float x_right_bottom_corner = x_left_top_corner + l;
//	const float y_right_bottom_corner = y_left_top_corner + h;
	
	//ball params:
	
	const float x_top = xc - r;
	const float y_top = yc;
	const float x_bottom = xc + r;
	const float y_bottom = yc;
	const float x_left = xc;
	const float y_left = yc - r;
	const float x_right = xc;
	const float y_right = yc + r;
	const float x_top_left = xc - r * std::sin(45.);
	const float y_top_left = yc - r * std::cos(45.);
	const float x_top_right = xc - r * std::sin(45.);
	const float y_top_right = yc + r * std::cos(45.);
	const float x_bottom_left = xc + r * std::sin(45.);
	const float y_bottom_left = yc - r * std::cos(45.);
	const float x_bottom_right = xc + r * std::sin(45.);
	const float y_bottom_right = yc + r * std::cos(45.);
	
	//conditions of colision:
	
//	wzgledem block:
//	
//	const bool left_top_corner_x = (x_left_top_corner) && (x_left_top_corner) && (x_left_top_corner) && (x_left_top_corner) && (x_left_top_corner) && (x_left_top_corner) && (x_left_top_corner) && (x_left_top_corner);
//	const bool left_top_corner_y = () && () && () && () && () && () && () && ();
//	const bool left_top_corner = () && () && () && () && () && () && () && ();
//	
//	const bool right_top_corner_x = () && () && () && () && () && () && () && ();
//	const bool right_top_corner_y = () && () && () && () && () && () && () && ();
//	const bool right_top_corner = () && () && () && () && () && () && () && ();
//	
//	const bool left_bottom_corner_x = () && () && () && () && () && () && () && ();
//	const bool left_bottom_corner_y = () && () && () && () && () && () && () && ();
//	const bool left_bottom_corner = () && () && () && () && () && () && () && ();
//	
//	const bool right_bottom_corner_x = () && () && () && () && () && () && () && ();
//	const bool right_bottom_corner_y = () && () && () && () && () && () && () && ();
//	const bool right_bottom_corner = () && () && () && () && () && () && () && (); 
	
	//wzgledem kola:
	
	const bool top_x = (x_top > x_left_block) && (x_top < x_right_block);
	const bool top_y = (y_top > y_top_block) && (y_top < y_bottom_block);
	const bool top = top_x && top_y;
	
	const bool bottom_x = (x_bottom > x_left_block) && (x_bottom < x_right_block);
	const bool bottom_y = (y_bottom > y_top_block) && (y_bottom < y_bottom_block);
	const bool bottom = bottom_x && bottom_y;
	
	const bool left_x = (x_left > x_left_block) && (x_left < x_right_block);
	const bool left_y = (y_left > y_top_block) && (y_left < y_bottom_block);
	const bool left = left_x && left_y;
	
	const bool right_x = (x_right > x_left_block) && (x_right < x_right_block);
	const bool right_y = (y_right > y_top_block) && (y_right < y_bottom_block);
	const bool right = right_x && right_y;
	
	const bool top_left_x = (x_top_left > x_left_block) && (x_top_left < x_right_block);
	const bool top_left_y = (y_top_left > y_top_block) && (y_top_left < y_bottom_block);
	const bool top_left = top_left_x && top_left_y;
	
	const bool top_right_x = (x_top_right > x_left_block) && (x_top_right < x_right_block);
	const bool top_right_y = (y_top_right > y_top_block) && (y_top_right < y_bottom_block);
	const bool top_right = top_right_x && top_right_y;
	
	const bool bottom_left_x = (x_bottom_left > x_left_block) && (x_bottom_left < x_right_block);
	const bool bottom_left_y = (y_bottom_left > y_top_block) && (y_bottom_left < y_bottom_block);
	const bool bottom_left = bottom_left_x && bottom_left_y;
	
	const bool bottom_right_x = (x_bottom_right > x_left_block) && (x_bottom_right < x_right_block);
	const bool bottom_right_y = (y_bottom_right > y_top_block) && (y_bottom_right < y_bottom_block);
	const bool bottom_right = bottom_right_x && bottom_right_y;
	
	//to zle:
	
//	const bool top = (xc - r) > xb;
//	const bool left = (yc - r) > yb;
//	
//	const bool bottom = (xc + r) < (xb + l);
//	const bool right = (yc + r) < (yb + h);
//			
//	const bool top_left_x = x_top_left > xb;
//	const bool top_left_y = y_top_left > yb;
//		
//	const bool top_right_x = x_top_right < (xb + l);
//	const bool top_right_y = y_top_right > yb;
//		
//	const bool bottom_left_x = x_bottom_left < xb;
//	const bool bottom_left_y = y_bottom_left > (yb + h);
//			
//	const bool bottom_right_x = x_bottom_right > (xb + l);
//	const bool bottom_right_y = y_bottom_right < (yb + h);
	
	//if (top && bottom && left && right && top_left_x && top_left_y && top_right_x && top_right_y && bottom_left_x && bottom_left_y && bottom_right_x && bottom_right_y)
	if(top || bottom || left || right || top_left || top_right || bottom_left || bottom_right)
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