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
	
//	Menu menu(WIDTH,HEIGHT);	
// create the window
	GameWindow window(WIDTH, HEIGHT, "Arcanoid - nasza wypas wersja 1.0");
	
	float width = window.getPlayableField().width;
	float x = window.getPlayableField().left;
	float y = window.getPlayableField().top;
	
	Blocks_Field b;
	b.create_matrix(width, x, y);

	sf::Clock clock; // starts the clock
	sf::Time elapsed = clock.getElapsedTime();
  
	unsigned int r = 30;

	sf::CircleShape circle(r);
	circle.setFillColor(sf::Color::Blue);
	circle.setOrigin(30, 30);
	
	float xc = 400;
	float yc = 300;
	
	circle.setPosition(xc, yc);
	
	Ball ball{xc, yc, r};
  

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
				
					b.set_blocks_state(xc, yc, r);
					//blocks[0][0].state = false;
			}
		}


		// clear the window with black color
		window.clear(sf::Color::Black);


		elapsed = clock.getElapsedTime();

		if(elapsed.asMilliseconds() > 100) {
		

			clock.restart();
		}
		
		ball.move();
		ball.checkWallColision(window.getPlayableField());
		
		std::vector<Block> tmp_vb = b.get_dawable_blocks();
		
		for(unsigned int i = 0; i < tmp_vb.size(); ++i)
				ball.checkColision(tmp_vb[i]);
		
		//generateBlocksFields(blocks, rows_no, columns_no);
		//for(auto& block : blocks) window.draw(block);
		//window.draw(block.block);
		
		b.draw_field(window);
		
		window.draw(ball);
		window.draw(circle);
		//menu.draw_menu(window);
		window.drawGUI();
		window.display();

	}
	return 0;
}
