#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Block.h"

class Ball : public sf::CircleShape
{
public:
	Ball(double x, double y, int r, double s);
	~Ball();
	void move();
	void speedUp();
	void slowDown();
	void bounce(sf::RectangleShape);
	bool checkColision(sf::RectangleShape);
	bool checkColision(Block &block);
	void bounceWall(sf::FloatRect);
	void checkWallColision(sf::FloatRect);
	void bouncePaddle(int);
	void setSpeed(double);
	
	bool dead = false;

private:
	double speed;
	int directionX;
	int directionY;

	double getX();
	double getY();
};

#endif // BALL_H
