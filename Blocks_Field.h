#ifndef BLOCKS_FIELD_H
#define BLOCKS_FIELD_H

#include "Block.h" // Base class: Block

class Blocks_Field : private Block
{
public:
	Blocks_Field();
	~Blocks_Field();
	
	void create_matrix(const int);
	void set_blocks_state(float, float, float);
	void draw_field(sf::RenderWindow&);
	
private:
	std::vector<std::vector<Block>> blocks;

};

#endif // BLOCKS_FIELD_H
