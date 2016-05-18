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

int Game::run()
{
	Paddle paddle(WIDTH/2, HEIGHT-50);

	GameWindow window(WIDTH, HEIGHT, "Arcanoid - nasza wypas wersja 2.0");

	float width = window.getPlayableField().width;
	float x = window.getPlayableField().left;
	float y = window.getPlayableField().top;

	Blocks_Field b;
	b.create_matrix(width, x, y);

	//////////////////////////////////// MENU ///////////////////////////////////////
	//Menu menu(WIDTH,HEIGHT);
	//if (menu.run_menu(window)== false) {
	//	return 0;
	//}
	//////////////////////////////////// END MENU ///////////////////////////////////


	sf::Clock clock; // starts the clock
	sf::Time elapsed = clock.getElapsedTime();


	unsigned int r = 15;
	float xc = 440;
	float yc = 220;

	Ball ball {xc, yc, r};

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			
			if (event.type == sf::Event::MouseButtonPressed) 
			{

			}
			
			if (event.type == sf::Event::MouseMoved) 
			{
				float mousePosX = event.mouseMove.x;
				paddle.movePaddle(mousePosX);
			}
		}

		window.clear(sf::Color::Black);
		elapsed = clock.getElapsedTime();

		//if(elapsed.asMilliseconds() > 100) {


		//clock.restart();
		//}
		//b.set_blocks_state(ball.getPosition().x, ball.getPosition().y, ball.getRadius());
		
		ball.move();
		ball.checkWallColision(window.getPlayableField());

		std::vector<Block> tmp_vb = b.get_dawable_blocks();

		for(unsigned int i = 0; i < tmp_vb.size(); ++i)
		{
			bool b = ball.checkColision(tmp_vb[i]);
		
			if(b)
			{
				std::cout<<"stan: " << tmp_vb[i].state <<std::endl;
			}
			else
			{
				window.draw(tmp_vb[i]);
				
			}
		}

		int side = paddle.isCollision(ball);
		ball.bouncePaddle(side);
		//b.draw_field(window);

		window.draw(ball);
		paddle.draw(window);
		window.drawGUI();
		window.display();

	}
	return 0;
}
