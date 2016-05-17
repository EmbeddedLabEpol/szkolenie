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

int Paddle::isCollision(sf::CircleShape& ball)
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

	int res = 0;
	if(
	    ballBottomX > leftPaddleX
	    && ballBottomX < rightPaddleX
	    && ballBottomY > leftMiddlePaddleY
	    && ballBottomY < leftPaddleY
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
	    && ballLeftY < leftPaddleY
	) {
		res = checkPaddleCollisionSide(leftPaddleX, leftMiddlePaddleX, rightMiddlePaddleX, rightPaddleX, ballLeftX);
		std::cout << "Ball left" <<  std::endl;
		std::cout << res << std::endl;
	} else if
	(
	    ballRigthX > leftPaddleX
	    && ballRigthX < rightPaddleX
	    && ballRigthY > leftMiddlePaddleY
	    && ballRigthY < leftPaddleY
	) {
		res = checkPaddleCollisionSide(leftPaddleX, leftMiddlePaddleX, rightMiddlePaddleX, rightPaddleX, ballRigthX);
		std::cout << "Ball right" << std::endl;
		std::cout << res << std::endl;
	}

	return res;

}

int Paddle::checkPaddleCollisionSide(float xA, float xB, float xC, float xD, float ballPointX)
{
	if(ballPointX >= xA && ballPointX < xB)
		return 1;
	if(ballPointX >= xB && ballPointX <= xC)
		return 2;
	if(ballPointX > xC && ballPointX <= xD)
		return 3;
	return 0;

}
Paddle::~Paddle()
{
}
