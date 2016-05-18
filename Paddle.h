#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include <vector>
#include "GameWindow.h"

class Paddle
{
private:
	float paddleWidth = 100;
	const float paddleHeight = 10;
	sf::Color paddleColor = sf::Color::Red;
	float paddlePositionX, paddlePositionY, radius = paddleHeight/2;
	sf::CircleShape leftCircle;
	sf::RectangleShape rectangle;
	sf::CircleShape rightCircle;
	int checkPaddleCollisionSide(float, float, float, float, float);
	bool paddleCollisionState = true;

public:
	Paddle(float, float);
	void draw(GameWindow&);
	void movePaddle(float);
	void setPaddleWidth(float);
	float getPaddleWidth();
	void setPaddleColor(sf::Color);
	int isCollision(sf::CircleShape&);
	void setPaddleCollisionState(bool);
	bool getPaddleCollisionState();
	void changePaddleSizeUp();
	void changePaddleSizeDown();
	~Paddle();

};

#endif // PADDLE_H
