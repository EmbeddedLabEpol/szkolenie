#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>

class Paddle
{
private:
	const float paddleWidth = 80, paddleHeight = 20;
	float paddlePositionX, paddlePositionY;
	sf::CircleShape leftCircle;
	sf::RectangleShape rectangle;
	sf::CircleShape rightCircle;

public:
	Paddle(float, float);
	void draw(sf::RenderWindow&);
	void movePaddle(float);
	~Paddle();

};

#endif // PADDLE_H
