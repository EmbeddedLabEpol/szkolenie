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
void Game::generateBlocksFields(std::vector<Block>& blocks, int rows, int cols)
{

	for(int x = 0; x < rows; ++x)
		for(int y= 0; y < cols; ++y)
			blocks.emplace_back(x*60+5, y*40+5);
}

int Game::run()
{

	//Block block;
	std::vector<Block> blocks;
	generateBlocksFields(blocks, 5 , 5);



// create the window
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Arcanoid - nasza wypas wersja 1.0");

	//////////////////////////////////// MENU ///////////////////////////////////////
	Menu menu(WIDTH,HEIGHT);
	if (menu.run_menu(window)== false){
		return 0;
	}
	//////////////////////////////////// END MENU ///////////////////////////////////


	sf::Clock clock; // starts the clock
	sf::Time elapsed = clock.getElapsedTime();


	while (window.isOpen()) {
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {
			/*if (event.type == sf::Event::MouseMoved) {
				std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
				std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
			}
			*/
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}


		// clear the window with black color
		window.clear(sf::Color::Yellow);


		elapsed = clock.getElapsedTime();

		if(elapsed.asMilliseconds() > 100) {


			clock.restart();
		}

		for(auto& block : blocks) window.draw(block.block);
		//window.draw(block.block);



		window.display();

	}
	return 0;
}
