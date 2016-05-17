#include "Game.h"
#include "Ball.h"
#include "Block.h"
#include "Menu.h"
#include "Paddle.h"
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
void Game::generateBlocksFields(std::vector<Block>& blocks, int cols)
{
	int blockX = 50;
	int blockY = 30;
	int nBlocks = WIDTH/blockX;
	int startPrint = (WIDTH-(nBlocks*blockX))/2;
	for(int x = 0; x < nBlocks; ++x)
		for(int y= 0; y < cols; ++y)
			blocks.emplace_back(startPrint+(x*blockX), 5+(y*blockY));
}

int Game::run()
{

	//Block block;
	std::vector<Block> blocks;
	generateBlocksFields(blocks, 5);
	Menu menu(WIDTH,HEIGHT);
	Paddle p(float(WIDTH/2), float(HEIGHT-50));
// create the window
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Arcanoid - nasza wypas wersja 1.0");

	sf::Clock clock; // starts the clock
	sf::Time elapsed = clock.getElapsedTime();

	unsigned int r =50;

	sf::CircleShape circle(r);
	circle.setFillColor(sf::Color::Blue);
	circle.setOrigin(50, 50);

	float xc = 400;
	float yc = 300;

	circle.setPosition(xc, yc);


	while (window.isOpen()) {
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::MouseMoved) {
				float mouseXPosition = event.mouseMove.x;
				p.movePaddle(mouseXPosition);
			}

			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {

				for (auto& block : blocks) {
					if (block.is_colision(xc, yc, r))
						block.setPosition(801, 601);

				}
			}
		}


		// clear the window with black color
		window.clear(sf::Color::Black);


		elapsed = clock.getElapsedTime();

		if(elapsed.asMilliseconds() > 100) {


			clock.restart();
		}

		for(auto& block : blocks) window.draw(block);
		//window.draw(block.block);

		window.draw(circle);
		p.draw(window);
		//menu.draw_menu(window);
		window.display();

	}
	return 0;
}
