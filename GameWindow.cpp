#include "GameWindow.h"


GameWindow::GameWindow()
{
	
}
GameWindow::GameWindow(int playableWindowHight, int playableWindowWidth, int windowHight, int windowWidth){}

GameWindow::GameWindow(int windowWidth,int windowHight, std::string windowName):sf::RenderWindow(sf::VideoMode(windowWidth, windowHight), windowName)
{
	float playableWidth = float (windowWidth) * playableWidthFactor - (2 * borderSize);
    float borderHight = float (windowHight) * playableHigthFactor; 
	//float playableHight = borderHight - (2 * borderSize);
	float xPosLeftBorder = float (windowWidth * sideMarginFactor);
	float yPosLeftBorder = float (windowHight * upperMarginFactor);
	float xPosUpperBorder = xPosLeftBorder + borderSize;
	float yPosUpperBorder = yPosLeftBorder;
	float xPosRightBorder = playableWidth + borderSize;
	float yPosRightBorder = yPosLeftBorder;
	float xPosLowerBorder = xPosUpperBorder;
	float yPosLowerBorder = windowHight - borderSize;
	
	setBorder( upperBorder, sf::Vector2f(playableWidth, borderSize), sf::Vector2f(xPosUpperBorder, yPosUpperBorder), sf::Color::Cyan);
	setBorder( lowerBorder, sf::Vector2f(playableWidth, borderSize), sf::Vector2f(xPosLowerBorder, yPosLowerBorder), sf::Color::Red);
	setBorder( leftBorder, sf::Vector2f(borderSize, borderHight), sf::Vector2f(xPosLeftBorder, yPosLeftBorder), sf::Color::Cyan);
	setBorder( rightBorder, sf::Vector2f(borderSize,borderHight), sf::Vector2f(xPosRightBorder, yPosRightBorder), sf::Color::Cyan);	
	
}

GameWindow::~GameWindow()
{
}

void GameWindow::drawGUI(sf::Time gameTime, int numberOfLifes )
{
	
}

void GameWindow::setBorder(sf::RectangleShape &border, const sf::Vector2f &_borderSize, const sf::Vector2f &borderPosition, const sf::Color borderColor){
	border.setSize(_borderSize);
	border.setPosition(borderPosition.x, borderPosition.y);
	border.setFillColor(borderColor);
}

