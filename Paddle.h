#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include <vector>

class Paddle
{
private:
	float paddleWidth = 100;
	const float paddleHeight = 20;
	sf::Color paddleColor = sf::Color::Red;
	float paddlePositionX, paddlePositionY, radius = paddleHeight/2;
	sf::CircleShape leftCircle;
	sf::RectangleShape rectangle;
	sf::CircleShape rightCircle;
	int checkPaddleCollisionSide(float, float, float, float, float);

public:
	Paddle(float, float);
	void draw(sf::RenderWindow&);
	void movePaddle(float);
	void setPaddleWidth(float);
	void setPaddleColor(sf::Color);
	int isCollision(sf::CircleShape&, sf::RenderWindow&);
	~Paddle();

};

#endif // PADDLE_H
