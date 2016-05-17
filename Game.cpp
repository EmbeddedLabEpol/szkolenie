#include "Game.h"
#include "Ball.h"
#include "Block.h"
#include "Menu.h"
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
	sf::RectangleShape pad{sf::Vector2f(1000,10)};
	pad.setPosition(0,750);
	//Block block;
	std::vector<Block> blocks;
	generateBlocksFields(blocks, 10 , 2);
	//Menu menu(WIDTH,HEIGHT);	
// create the window
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Arcanoid - nasza wypas wersja 1.0");

	sf::Clock clock; // starts the clock
	sf::Time elapsed = clock.getElapsedTime();
  

	while (window.isOpen()) {
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::MouseMoved) {
				std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
				std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
			}

			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
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

		for(auto& block : blocks)
		{
			window.draw(block.block);
			ball.checkColision(block);
			ball.checkColision(pad);
			window.draw(pad);
		}
		//window.draw(block.block);
		 
    
		//menu.draw_menu(window);
		window.display();

	}
	return 0;
}
