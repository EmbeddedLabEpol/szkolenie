#include "Game.h"
#include "Ball.h"
#include "Block.h"
#include "Menu.h"
#include "Paddle.h"
#include "GameWindow.h"
#include <vector>
#include <SFML/Graphics.hpp>
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


	Paddle paddle(WIDTH/2, HEIGHT-50);

	// create the window
	GameWindow window(WIDTH, HEIGHT, "Arcanoid - nasza wypas wersja 2.0");
	Menu menu(WIDTH,HEIGHT);
	menu.intro(window);
	float width = window.getPlayableField().width;
	float x = window.getPlayableField().left;
	float y = window.getPlayableField().top;

	Blocks_Field b;

	sf::Clock clock; // starts the clock
	sf::Clock paddleClock;
	sf::Time elapsed = clock.getElapsedTime();

	  int r = 15;

	float xc = 512;
	float yc = 700;

	Ball ball {xc, yc, r, 10.0};

beginning:

	b.create_matrix(width, x, y);
	ball.setPosition(xc,yc);
	//////////////////////////////////// MENU ///////////////////////////////////////
	if (menu.run_menu(window)== false) {
		return 0;
	}
	//////////////////////////////////// END MENU ///////////////////////////////////



	while (window.isOpen()) {
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {



			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {

				ball.setSpeed(10);
				ball.dead = false;
				//blocks[0][0].state = false;
			}
			if (event.type == sf::Event::MouseMoved) {
				float mousePosX = event.mouseMove.x;
				sf::FloatRect availableField = window.getPlayableField();
				if(mousePosX > (availableField.left + paddle.getPaddleWidth()/2) && mousePosX < (availableField.left + availableField.width - paddle.getPaddleWidth()/2))
					paddle.movePaddle(mousePosX);
			}
		}


		// clear the window with black color
		window.clear(sf::Color::Black);
		elapsed = clock.getElapsedTime();

		//if(elapsed.asMilliseconds() > 100) {


		//clock.restart();
		//}
		//b.set_blocks_state(ball.getPosition().x, ball.getPosition().y, ball.getRadius());
		ball.move();
		ball.checkWallColision(window.getPlayableField());

//		std::vector<Block> tmp_vb = b.get_dawable_blocks();
//
//		for(unsigned int i = 0; i < tmp_vb.size(); ++i)
//			ball.checkColision(tmp_vb[i]);

		for(unsigned int r = 0; r < b.blocks.size(); ++r)
			for(unsigned int c = 0; c < b.blocks[r].size(); ++c)
				if(b.blocks[r][c].state)
					if(ball.checkColision(b.blocks[r][c])) {
						b.blocks[r][c].state = false;
						b.blocks_no = b.blocks_no - 1;
						
						if(b.blocks[r][c].up_speed){
							ball.speedUp();
							std::cout<< "szybcej"<< std::endl;
						}
													
						if(b.blocks[r][c].down_speed){
							ball.slowDown();
							std::cout<< "wolniej"<< std::endl;
						}
							
						if(b.blocks[r][c].up_size){
							ball.scale(2,2); //sizeUp();
							ball.setRadius(ball.getRadius()*2);
							std::cout<< "wieksza"<< std::endl;
						}
							
							
							
						if(b.blocks[r][c].down_size){
							ball.scale(0.5,0.5); //sizeDown();
							ball.setRadius(ball.getRadius()*0.5);
							std::cout<< "mniejsza"<< std::endl;
						}
						
						if(b.blocks[r][c].up_paddle_size){
							paddle.changePaddleSizeUp();
							std::cout<< "wieksza paletka"<< std::endl;
						}
						
						if(b.blocks[r][c].down_paddle_size){
							paddle.changePaddleSizeDown();
							std::cout<< "mniejsza paletka"<< std::endl;
						}
					}

		if(paddle.getPaddleCollisionState()) {
			int side = paddle.isCollision(ball);
			if(side > 0) {
				ball.bouncePaddle(side);
				paddle.setPaddleCollisionState(false);
			}
		} else if (paddleClock.getElapsedTime().asMilliseconds() > 300) {
			paddle.setPaddleCollisionState(true);
			paddleClock.restart();
		}
	
		if(ball.dead)
		{	
			ball.setPosition(512,700);
		}

		if (b.blocks_no == 0) {
			b.delete_matrix();
			goto beginning;
		}

		b.draw_field(window);

		window.draw(ball);
		paddle.draw(window);
		window.drawGUI(sf::seconds(90),3,menu.get_user_name());
		window.display();

	}
	return 0;
}
