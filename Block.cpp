#include "Block.h"

Block::Block(sf::Vector2f v):
block(v)
{
}

Block::~Block()
{
}

void Block::draw(sf::RenderWindow& w)
{
	w.draw(block);
}