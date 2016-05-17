#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>

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

public:
	Paddle(float, float);
	void draw(sf::RenderWindow&);
	void movePaddle(float);
	void setPaddleWidth(float);
	void setPaddleColor(sf::Color);
	~Paddle();

};

#endif // PADDLE_H
