#include "Paddle.h"

Paddle::Paddle(float posX, float posY):paddlePositionX(posX), paddlePositionY(posY)
{
	leftCircle.setPosition(posX-10, posY);
	leftCircle.setRadius(paddleHeight/2);
	leftCircle.setFillColor(sf::Color::Black);
	leftCircle.setOrigin(paddleWidth/2, paddleHeight/2);

	rectangle.setPosition(posX, posY);
	rectangle.setSize( {paddleWidth, paddleHeight});
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setOrigin(paddleWidth/2, paddleHeight/2);

	rightCircle.setPosition(posX + 70, posY);
	rightCircle.setRadius(paddleHeight/2);
	rightCircle.setFillColor(sf::Color::Black);
	rightCircle.setOrigin(paddleWidth/2, paddleHeight/2);
}

void Paddle::draw(sf::RenderWindow& window)
{
	window.draw(leftCircle);
	window.draw(rectangle);
	window.draw(rightCircle);
}

void Paddle::movePaddle(float posX)
{
	rectangle.setPosition(posX, paddlePositionY);
	leftCircle.setPosition(posX-10, paddlePositionY);
	rightCircle.setPosition(posX + 70, paddlePositionY);
}

Paddle::~Paddle()
{
}
