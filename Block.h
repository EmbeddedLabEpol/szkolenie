#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>

class Block
{
public:
	Block(sf::Vector2f = sf::Vector2f(50, 50));
	~Block();
	
	void draw(sf::RenderWindow&);
	
private:
	sf::RectangleShape block;

};

#endif // BLOCK_H
