#ifndef BLOCKS_FIELD_H
#define BLOCKS_FIELD_H

#include "Block.h" // Base class: Block

class Blocks_Field : public Block
{
public:
	Blocks_Field();
	~Blocks_Field();
	
	void create_matrix(const int, float, float);
	void set_blocks_state(float, float, float);
	void draw_field(sf::RenderWindow&);
	std::vector<Block> get_dawable_blocks();
	int blocks_no;
	void delete_matrix();
	void set_circuit();
//private:
	std::vector<std::vector<Block>> blocks;

};

#endif // BLOCKS_FIELD_H
