#include "Paddle.h"

Paddle::Paddle(float posX, float posY):paddlePositionX(posX), paddlePositionY(posY)
{
	leftCircle.setPosition(posX-radius, posY);
	leftCircle.setRadius(radius);
	leftCircle.setFillColor(paddleColor);
	leftCircle.setOrigin(paddleWidth/2, paddleHeight/2);

	rectangle.setPosition(posX, posY);
	rectangle.setSize( {paddleWidth, paddleHeight});
	rectangle.setFillColor(paddleColor);
	rectangle.setOrigin(paddleWidth/2, paddleHeight/2);

	rightCircle.setPosition(posX + (paddleWidth - radius), posY);
	rightCircle.setRadius(radius);
	rightCircle.setFillColor(paddleColor);
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
	leftCircle.setPosition(posX-radius, paddlePositionY);
	rightCircle.setPosition(posX + (paddleWidth - radius), paddlePositionY);
}

void Paddle::setPaddleColor(sf::Color color)
{
	paddleColor = color;
}

void Paddle::setPaddleWidth(float width)
{
	paddleWidth = width;
}

Paddle::~Paddle()
{
}
