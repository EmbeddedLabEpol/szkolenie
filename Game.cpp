#include "Game.h"
#include "Ball.h"
#include "Block.h"
#include "Menu.h"
#include "Paddle.h"
#include "GameWindow.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
Game::Game()
{
}

Game::~Game()
{
}
//void Game::generateBlocksFields(std::vector<Block>& blocks, int rows, int cols){
//
//    for(int x = 0; x < rows; ++x)
//      for(int y= 0; y < cols; ++y)
//		  if()
//			//blocks.emplace_back(x*60, y*40);
//}

int Game::run()
{
	
	//Block block;
	//std::vector<std::vector<Block>> blocks;
	Block tmp_b;
	
	const unsigned int columns_no = WIDTH/tmp_b.get_size_x();
	const unsigned int rows_no = 10;
	
	std::vector<Block> tmp_v;
	std::vector<std::vector<Block>> blocks;
		
	for(unsigned int c = 0; c < columns_no; ++c)
		tmp_v.push_back(* new Block);
		
	for(unsigned int r = 0; r < rows_no; ++r)
		blocks.push_back(tmp_v);
	
	const float first_position_x = (WIDTH - columns_no * tmp_b.get_size_x()) / 2;
	const float first_position_y = 0;
	
	for(unsigned int r = 0; r < rows_no; ++r)
		for(unsigned int c = 0; c < columns_no; ++c)
			blocks[r][c].setPosition(first_position_x + tmp_b.get_size_x() * c, first_position_y + tmp_b.get_size_y() * r);
	
//	Menu menu(WIDTH,HEIGHT);	
// create the window
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Arcanoid - nasza wypas wersja 1.0");

	sf::Clock clock; // starts the clock
	sf::Time elapsed = clock.getElapsedTime();
  
	unsigned int r = 30;

	sf::CircleShape circle(r);
	circle.setFillColor(sf::Color::Blue);
	circle.setOrigin(30, 30);
	
	float xc = 400;
	float yc = 300;
	
	circle.setPosition(xc, yc);
  

	while (window.isOpen()) {
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::MouseMoved) {
				//std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
				//std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
				xc = event.mouseMove.x;
				yc = event.mouseMove.y;
				circle.setPosition(xc, yc);
			}

			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
				
			if (event.type == sf::Event::MouseButtonPressed)
			{
				for(unsigned int r = 0; r < rows_no; ++r)
					for(unsigned int c = 0; c < columns_no; ++c)
					{
						std::cout << blocks[r][c].is_colision(xc, yc, r) << std::endl;
						
						if(blocks[r][c].state && blocks[r][c].is_colision(xc, yc, r))
							blocks[r][c].state = false;				
					}
					
					//blocks[0][0].state = false;
			}
		}


		// clear the window with black color
		window.clear(sf::Color::Black);


		elapsed = clock.getElapsedTime();

		if(elapsed.asMilliseconds() > 100) {
		

			clock.restart();
		}
		
		//generateBlocksFields(blocks, rows_no, columns_no);
		//for(auto& block : blocks) window.draw(block);
		//window.draw(block.block);
		
		for(unsigned int r = 0; r < rows_no; ++r)
			for(unsigned int c = 0; c < columns_no; ++c)
				if(blocks[r][c].state)
					window.draw(blocks[r][c]);
		 
		window.draw(circle);
		//menu.draw_menu(window);
		window.drawGUI();
		window.display();

	}
	return 0;
}
