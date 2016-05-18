#include "Paddle.h"

Paddle::Paddle(float posX, float posY):paddlePositionX(posX), paddlePositionY(posY)
{
	leftCircle.setPosition(posX-paddleWidth/2, posY);
	leftCircle.setRadius(radius);
	leftCircle.setFillColor(paddleColor);
	leftCircle.setOrigin(radius, radius);

	rectangle.setPosition(posX, posY);
	rectangle.setSize( {paddleWidth, paddleHeight});
	rectangle.setFillColor(paddleColor);
	rectangle.setOrigin(paddleWidth/2, paddleHeight/2);

	rightCircle.setPosition(posX + paddleWidth/2, posY);
	rightCircle.setRadius(radius);
	rightCircle.setFillColor(paddleColor);
	rightCircle.setOrigin(radius, radius);
}

void Paddle::draw(GameWindow& window)
{
	window.draw(leftCircle);
	window.draw(rectangle);
	window.draw(rightCircle);
}

void Paddle::movePaddle(float posX)
{
	paddlePositionX = posX;
	rectangle.setPosition(posX, paddlePositionY);
	leftCircle.setPosition(posX-paddleWidth/2, paddlePositionY);
	rightCircle.setPosition(posX + paddleWidth/2, paddlePositionY);
}

void Paddle::setPaddleColor(sf::Color color)
{
	paddleColor = color;
}

void Paddle::setPaddleWidth(float width)
{
	paddleWidth = width;
}

float Paddle::getPaddleWidth()
{
	return paddleWidth;
}

int Paddle::isCollision(Ball& ball)
{
	float ballLeftX = ball.getPosition().x - ball.getRadius();
	float ballLeftY = ball.getPosition().y;

	float ballBottomX = ball.getPosition().x;
	float ballBottomY = ball.getPosition().y + ball.getRadius();

	float ballRigthX = ball.getPosition().x + ball.getRadius();
	float ballRigthY = ball.getPosition().y;

	float leftPaddleX = leftCircle.getPosition().x - leftCircle.getRadius();
	float leftPaddleY = leftCircle.getPosition().y;

	float leftMiddlePaddleX = leftCircle.getPosition().x;
	float leftMiddlePaddleY = leftCircle.getPosition().y - leftCircle.getRadius();

	float rightMiddlePaddleX = rightCircle.getPosition().x;

	float rightPaddleX = rightCircle.getPosition().x + rightCircle.getRadius();

	int offset = 20;
	int res = 0;
	if(
	    ballBottomX > leftPaddleX
	    && ballBottomX < rightPaddleX
	    && ballBottomY > leftMiddlePaddleY
	    && ballBottomY < leftPaddleY + offset
	) {
		res = checkPaddleCollisionSide(leftPaddleX, leftMiddlePaddleX, rightMiddlePaddleX, rightPaddleX, ballBottomX);
	} else if
	(
	    ballLeftX > leftPaddleX
	    && ballLeftX < rightPaddleX
	    && ballLeftY > leftMiddlePaddleY
	    && ballLeftY < leftPaddleY + offset
	) {
		res = checkPaddleCollisionSide(leftPaddleX, leftMiddlePaddleX, rightMiddlePaddleX, rightPaddleX, ballLeftX);
	} else if
	(
	    ballRigthX > leftPaddleX
	    && ballRigthX < rightPaddleX
	    && ballRigthY > leftMiddlePaddleY
	    && ballRigthY < leftPaddleY + offset
	) {
		res = checkPaddleCollisionSide(leftPaddleX, leftMiddlePaddleX, rightMiddlePaddleX, rightPaddleX, ballRigthX);
	}

	return res;

}

int Paddle::checkPaddleCollisionSide(float xA, float xB, float xC, float xD, float ballPointX)
{
	xB += 10;
	xC -= 10;
	if(ballPointX >= xA && ballPointX < xB)
		return 1;
	if(ballPointX >= xB && ballPointX <= xC)
		return 2;
	if(ballPointX > xC && ballPointX <= xD)
		return 3;
	return 0;

}

void Paddle::setPaddleCollisionState(bool state)
{
	paddleCollisionState = state;
}

bool Paddle::getPaddleCollisionState()
{
	return paddleCollisionState;
}

void Paddle::changePaddleSizeUp()
{
	if(paddleWidth <= 175)
		paddleWidth *= 1.5f;

	leftCircle.setPosition(paddlePositionX-paddleWidth/2, paddlePositionY);
	rightCircle.setPosition(paddlePositionX+paddleWidth/2, paddlePositionY);
	rectangle.setSize( {paddleWidth, paddleHeight});
	rectangle.setOrigin(paddleWidth/2, paddleHeight/2);
}

void Paddle::changePaddleSizeDown()
{
	if(paddleWidth >= 10)
		paddleWidth *= 0.5f;

	leftCircle.setPosition(paddlePositionX-paddleWidth/2, paddlePositionY);
	rightCircle.setPosition(paddlePositionX+paddleWidth/2, paddlePositionY);
	rectangle.setSize( {paddleWidth, paddleHeight});
	rectangle.setOrigin(paddleWidth/2, paddleHeight/2);
}

sf::Vector2f Paddle::getPaddlePosition()
{
	return rectangle.getPosition();
}

Paddle::~Paddle()
{
}
