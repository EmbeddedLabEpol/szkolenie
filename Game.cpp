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


void Game::generateBlocksFields(std::vector<Block>& blocks, int rows, int cols){


    for(int x = 1; x < rows; ++x)
      //for(int y= 3; y < cols+2; ++y)
		blocks.emplace_back(x*100+5, 500);
}

int Game::run()
{	
	Ball ball{500,700,30};
	
	
	//Block block;
	std::vector<Block> blocks;
	generateBlocksFields(blocks, 10 , 2);
	//Menu menu(WIDTH,HEIGHT);	

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
		// window.clear(sf::Color::Yellow);


		ball.move();
		//ball.checkColision()
		elapsed = clock.getElapsedTime();

		if(elapsed.asMilliseconds() > 100) {

			window.clear(sf::Color::Yellow);
			window.draw(ball);
			clock.restart();
		}


		for(Block block : blocks)
		{
			window.draw(block);
			ball.checkColision((sf::RectangleShape)block);
			
		}
			ball.checkWallColision(window.getUpperBorder());
			
		 
    


		//menu.draw_menu(window);
		window.drawGUI();
		window.display();

	}
	return 0;
}
