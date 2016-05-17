#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

class Ball : public sf::CircleShape
{
  public:
	Ball(double x, double y, int r);
	~Ball();
	void move();
	void speedUp();
	void slowDown();
	void bounce(int _directionX, int _directionY);
	void checkColision(sf::RectangleShape);
	
	
private:
	double speed;
	int directionY;
	int directionX;
	
	double getX();
	double getY();
};

#endif // BALL_H
