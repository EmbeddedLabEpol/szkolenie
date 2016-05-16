#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>

class Block : public sf::RectangleShape
{
public:
	Block(sf::Vector2f = sf::Vector2f(50, 50));
	~Block();
	
	//void draw(sf::RenderWindow&);
	bool is_colision(float, float, float);
	
private:
	sf::RectangleShape block;
};

#endif // BLOCK_H
