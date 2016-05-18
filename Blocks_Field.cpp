#include "Blocks_Field.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

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
	const unsigned int rows_no = 2;
	
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
	
	srand (time(NULL));
	
	int random_row1 = rand() % (rows_no - 1)  + 0;
	int random_column1 = rand() % (columns_no - 1)  + 0;
	blocks[random_row1][random_column1].up_speed = true;
	blocks[random_row1][random_column1].setFillColor(sf::Color::Red);
	
	int random_row2 = rand() % (rows_no - 1) + 0;
	int random_column2 = rand() % (columns_no - 1)  + 0;
	blocks[random_row2][random_column2].down_speed = true;
	blocks[random_row2][random_column2].setFillColor(sf::Color::Red);
	
	int random_row3 = rand() % (rows_no - 1)  + 0;
	int random_column3 = rand() % (columns_no - 1)  + 0;
	blocks[random_row3][random_column3].up_size = true;
	blocks[random_row3][random_column3].setFillColor(sf::Color::Red);
	
	int random_row4 = rand() % (rows_no - 1) + 0;
	int random_column4 = rand() % (columns_no - 1)  + 0;
	blocks[random_row4][random_column4].down_size = true;
	blocks[random_row4][random_column4].setFillColor(sf::Color::Red);
	
	int random_row5 = rand() % (rows_no - 1)  + 0;
	int random_column5 = rand() % (columns_no - 1)  + 0;
	blocks[random_row5][random_column5].up_paddle_size = true;
	blocks[random_row5][random_column5].setFillColor(sf::Color::Red);
	
	int random_row6 = rand() % (rows_no - 1) + 0;
	int random_column6 = rand() % (columns_no - 1)  + 0;
	blocks[random_row6][random_column6].down_paddle_size = true;
	blocks[random_row6][random_column6].setFillColor(sf::Color::Red);
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
}
