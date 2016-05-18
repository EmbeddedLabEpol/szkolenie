#include "Blocks_Field.h"
#include <iostream>

Blocks_Field::Blocks_Field()
{
}

Blocks_Field::~Blocks_Field()
{
}

void Blocks_Field::create_matrix(const int width, float x, float y)
{
	Block tmp_b;
	
	const unsigned int columns_no = width/tmp_b.get_size_x();
	const unsigned int rows_no = 3;
	
	std::vector<Block> tmp_v;
		
	for(unsigned int c = 0; c < columns_no; ++c)
		tmp_v.push_back(* new Block);
		
	for(unsigned int r = 0; r < rows_no; ++r)
		blocks.push_back(tmp_v);
	
	const float first_position_x = x + (width - columns_no * tmp_b.get_size_x()) / 2;
	const float first_position_y = y + (width - columns_no * tmp_b.get_size_x()) / 2;
	
	for(unsigned int r = 0; r < rows_no; ++r)
		for(unsigned int c = 0; c < columns_no; ++c)
			blocks[r][c].setPosition(first_position_x + tmp_b.get_size_x() * c, first_position_y + tmp_b.get_size_y() * r);
			
	blocks_no = rows_no * columns_no;
}

void Blocks_Field::set_blocks_state(float xc, float yc, float r)
{
	for(unsigned int r = 0; r < blocks.size(); ++r)
		for(unsigned int c = 0; c < blocks[r].size(); ++c)
			if(blocks[r][c].state && blocks[r][c].is_colision(xc, yc, r))
				blocks[r][c].state = false;
}

void Blocks_Field::draw_field(sf::RenderWindow& window)
{
	for(unsigned int r = 0; r < blocks.size(); ++r)
		for(unsigned int c = 0; c < blocks[r].size(); ++c)
			if(blocks[r][c].state)
				window.draw(blocks[r][c]);
}

std::vector<Block> Blocks_Field::get_dawable_blocks()
{
	std::vector<Block> tmp_v;
	
	for(unsigned int r = 0; r < blocks.size(); ++r)
		for(unsigned int c = 0; c < blocks[r].size(); ++c)
			if(blocks[r][c].state)
				tmp_v.push_back(blocks[r][c]);
				
	return tmp_v;
}

void Blocks_Field::delete_matrix()
{
//	for(unsigned int r = 0; r < blocks.size(); ++r)
//		for(unsigned int c = 0; c < blocks[r].size(); ++c)
//			delete &blocks[r][c];
	
	blocks.clear();
	std::cout << blocks.size() << std::endl;
}
