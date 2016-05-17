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


void Game::generateBlocksFields(std::vector<Block>& blocks, int rows, int cols)
{


	for(int x = 1; x < rows; ++x)
		//for(int y= 3; y < cols+2; ++y)
		blocks.emplace_back(x*100+5, 500);
}

int Game::run()
{
	Ball ball {500,700,10};
	Paddle paddle(WIDTH/2, HEIGHT-50);


	//Block block;
	std::vector<Block> blocks;
	generateBlocksFields(blocks, 10 , 2);
	//Menu menu(WIDTH,HEIGHT);

// create the window
	GameWindow window(WIDTH, HEIGHT, "Arcanoid - nasza wypas wersja 1.0");

	sf::Clock clock; // starts the clock
	sf::Time elapsed = clock.getElapsedTime();

	unsigned int r = 30;

	while (window.isOpen()) {
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::MouseMoved) {
				float mousePosX = event.mouseMove.x;
				paddle.movePaddle(mousePosX);

			}
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();


		}


		// clear the window with black color
		// window.clear(sf::Color::Yellow);


		ball.move();
		int side = paddle.isCollision(ball);

		ball.bouncePaddle(side);
		//ball.checkColision()
		elapsed = clock.getElapsedTime();

		//if(elapsed.asMilliseconds() > 100) {

		window.clear(sf::Color::Yellow);
		window.draw(ball);
		paddle.draw(window);

		for(Block block : blocks) {
			window.draw(block);
			ball.checkColision((sf::RectangleShape)block);

		}

		ball.checkWallColision(window.getPlayableField());

		clock.restart();
		//}

		//for(auto& block : blocks) window.draw(block);
		//window.draw(block.block);









		//menu.draw_menu(window);
		window.drawGUI();
		window.getPlayableField();
		window.display();

	}
	return 0;
}
