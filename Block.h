#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>

class Block : public sf::RectangleShape
{
public:
	Block(float = 0, float = 0);
	~Block();
	
	bool is_colision(float, float, float);

	sf::RectangleShape block;
	bool state;
};

#endif // BLOCK_H
