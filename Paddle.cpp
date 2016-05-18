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

int Paddle::isCollision(sf::CircleShape& ball, GameWindow& window)
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
	float rightMiddlePaddleY = rightCircle.getPosition().y - rightCircle.getRadius();

	float rightPaddleX = rightCircle.getPosition().x + rightCircle.getRadius();
	float rightPaddleY = rightCircle.getPosition().y;

	int offset = 20;
	int res = 0;
	if(
	    ballBottomX > leftPaddleX
	    && ballBottomX < rightPaddleX
	    && ballBottomY > leftMiddlePaddleY
	    && ballBottomY < leftPaddleY + offset
	) {

		res = checkPaddleCollisionSide(leftPaddleX, leftMiddlePaddleX, rightMiddlePaddleX, rightPaddleX, ballBottomX);
		std::cout << "Ball bottom" << std::endl;
		std::cout << res << std::endl;
	}

	else if
	(
	    ballLeftX > leftPaddleX
	    && ballLeftX < rightPaddleX
	    && ballLeftY > leftMiddlePaddleY
	    && ballLeftY < leftPaddleY + offset
	) {
		res = checkPaddleCollisionSide(leftPaddleX, leftMiddlePaddleX, rightMiddlePaddleX, rightPaddleX, ballLeftX);
		std::cout << "Ball left" <<  std::endl;
		std::cout << res << std::endl;
	} else if
	(
	    ballRigthX > leftPaddleX
	    && ballRigthX < rightPaddleX
	    && ballRigthY > leftMiddlePaddleY
	    && ballRigthY < leftPaddleY + offset
	) {
		res = checkPaddleCollisionSide(leftPaddleX, leftMiddlePaddleX, rightMiddlePaddleX, rightPaddleX, ballRigthX);
		std::cout << "Ball right" << std::endl;
		std::cout << res << std::endl;
	}

	//std::cout << ballRigthX << " > " << leftPaddleX << " , "<< ballLeftX << " < " << rightPaddleX << " , " << ballRigthY << " > " << leftMiddlePaddleY << " , " << ballRigthY << " < " << leftPaddleY << std::endl;

	sf::CircleShape c1, c2, c3, c4, b1, b2, b3;

	c1.setPosition(leftPaddleX, leftPaddleY);
	c1.setRadius(2);

	c2.setPosition(leftMiddlePaddleX, leftMiddlePaddleY);
	c2.setRadius(2);

	c3.setPosition(rightMiddlePaddleX, rightMiddlePaddleY);
	c3.setRadius(2);

	c4.setPosition(rightPaddleX, rightPaddleY);
	c4.setRadius(2);

	b1.setPosition(ballLeftX, ballLeftY);
	b1.setRadius(2);

	b2.setPosition(ballBottomX, ballBottomY);
	b2.setRadius(2);

	b3.setPosition(ballRigthX, ballRigthY);
	b3.setRadius(2);

	window.draw(c1);
	window.draw(c2);
	window.draw(c3);
	window.draw(c4);
	window.draw(b1);
	window.draw(b2);
	window.draw(b3);

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
Paddle::~Paddle()
{
}
