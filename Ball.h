#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
class Ball : public sf::CircleShape
{
public:
	Ball(int i);
	~Ball();
	void color();
	 

};

#endif // BALL_H
