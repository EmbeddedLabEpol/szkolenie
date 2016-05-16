#include "Game.h"
#include "Ball.h"
#include "Block.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
Game::Game()
{
}

Game::~Game()
{
}

int Game::run()
{
	
	Block b;
	
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
		window.clear(sf::Color::Yellow);


		elapsed = clock.getElapsedTime();

		if(elapsed.asMilliseconds() > 100) {
		

			clock.restart();
		}

		
		b.draw(window);
		
		window.display();

	}
	return 0;
}
