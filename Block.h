#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>

class Block : public sf::RectangleShape
{
public:
	Block(float = 0, float = 0);
	~Block();
	
	bool is_colision(float, float, float);
	float get_size_x();
	float get_size_y();
	void set_state(float, float, float);

	//sf::RectangleShape block;
	bool state;
	
	bool up_speed = false;
	bool down_speed = false;
	bool up_size = false;
	bool down_size = false;
};

#endif // BLOCK_H
