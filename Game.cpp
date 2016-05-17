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
#include "Blocks_Field.h"

Game::Game()
{
}

Game::~Game()
{
}
 
void Game::generateBlocksFields(std::vector<Block>& blocks, int rows, int cols)
{

	for(int x = 0; x < rows; ++x)
		for(int y= 0; y < cols; ++y)
			blocks.emplace_back(x*60+5, y*40+5);
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

	std::vector<Block> blocks;
	generateBlocksFields(blocks, 5 , 5);

	//std::vector<std::vector<Block>> blocks;
	
 	 
 
// create the window
	GameWindow window(WIDTH, HEIGHT, "Arcanoid - nasza wypas wersja 2.0");
	
	float width = window.getPlayableField().width;
	float x = window.getPlayableField().left;
	float y = window.getPlayableField().top;
	
	Blocks_Field b;
	b.create_matrix(width, x, y);

	//////////////////////////////////// MENU ///////////////////////////////////////
	Menu menu(WIDTH,HEIGHT);
	if (menu.run_menu(window)== false){
		return 0;
	}
	//////////////////////////////////// END MENU ///////////////////////////////////


	sf::Clock clock; // starts the clock
	sf::Time elapsed = clock.getElapsedTime();
 
  
	unsigned int r = 15;

	 
	
	float xc = 440;
	float yc = 220;
	
 
 
	
	Ball ball{xc, yc, r};
  
 

	while (window.isOpen()) {
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {
 
		
			
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
				
			if (event.type == sf::Event::MouseButtonPressed)
			{
				
					
					//blocks[0][0].state = false;
			}
		}


		// clear the window with black color
		window.clear(sf::Color::Black);
		elapsed = clock.getElapsedTime();

		//if(elapsed.asMilliseconds() > 100) {


			//clock.restart();
		//}
		b.set_blocks_state(ball.getPosition().x, ball.getPosition().y, ball.getRadius());
		ball.move();
		ball.checkWallColision(window.getPlayableField());
		
		std::vector<Block> tmp_vb = b.get_dawable_blocks();
		
		for(unsigned int i = 0; i < tmp_vb.size(); ++i)
				ball.checkColision(tmp_vb[i]);
		
 
		b.draw_field(window);
		
		window.draw(ball);
		window.drawGUI(); 
		window.display();

	}
	return 0;
}
