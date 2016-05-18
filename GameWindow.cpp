#include "GameWindow.h"
#include <iostream>

GameWindow::GameWindow()
{
	
}


GameWindow::GameWindow(int windowWidth,int windowHight, std::string windowName):sf::RenderWindow(sf::VideoMode(windowWidth, windowHight), windowName)
{
	float playableWidth = float (windowWidth) * playableWidthFactor - (2 * borderSize);
    float borderHight = float (windowHight) * playableHigthFactor; 
	//float playableHight = borderHight - (2 * borderSize);
	float xPosLeftBorder = float (windowWidth * sideMarginFactor);
	float yPosLeftBorder = float (windowHight * upperMarginFactor);
	float xPosUpperBorder = xPosLeftBorder + borderSize;
	float yPosUpperBorder = yPosLeftBorder;
	float xPosRightBorder = playableWidth + xPosLeftBorder + borderSize;
	float yPosRightBorder = yPosLeftBorder;
	float xPosLowerBorder = xPosUpperBorder;
	float yPosLowerBorder = windowHight - borderSize;
	
	setBorder( upperBorder, sf::Vector2f(playableWidth, borderSize), sf::Vector2f(xPosUpperBorder, yPosUpperBorder), sf::Color::Cyan);
	setBorder( lowerBorder, sf::Vector2f(playableWidth, borderSize), sf::Vector2f(xPosLowerBorder, yPosLowerBorder), sf::Color::Red);
	setBorder( leftBorder, sf::Vector2f(borderSize, borderHight), sf::Vector2f(xPosLeftBorder, yPosLeftBorder), sf::Color::Cyan);
	setBorder( rightBorder, sf::Vector2f(borderSize,borderHight), sf::Vector2f(xPosRightBorder, yPosRightBorder), sf::Color::Cyan);	
	
    if (!gameWindowFont.loadFromFile("../TimesOldAttic.TTF")) {
		// error...
	}
	
	configureLifeIcon();
	
	configText(playerName, sf::Vector2f(50,30));
	configText(timeText, sf::Vector2f(50,80));	
	configText(lifesText, sf::Vector2f(450,50));
}

GameWindow::~GameWindow()
{
}

void GameWindow::drawGUI(const sf::Time gameTime, int numberOfLifes, sf::String playerNameString )
{
	drawBorders();
	drawPlayerName(playerNameString);
	drawGameTime(gameTime);
	drawLifes(numberOfLifes);	
}

void GameWindow::setBorder(sf::RectangleShape &border, const sf::Vector2f &_borderSize, const sf::Vector2f &borderPosition, const sf::Color borderColor){
	border.setSize(_borderSize);
	border.setPosition(borderPosition.x, borderPosition.y);
	border.setFillColor(borderColor);
}
void GameWindow::configText(sf::Text &confText, sf::Vector2f textPosition)
{
	// select the font
	confText.setFont(gameWindowFont); // font is a sf::Font	

	// set the character size
	confText.setCharacterSize(24); // in pixels, not points!    
	// set the color
	confText.setColor(sf::Color::Yellow);

	// set the text style
	confText.setStyle(sf::Text::Bold | sf::Text::Regular);
    
	confText.setOrigin(0,0);
	confText.setPosition(textPosition);
}

sf::FloatRect GameWindow::getPlayableField()
{
	return sf::FloatRect(upperBorder.getGlobalBounds().left, upperBorder.getGlobalBounds().top+borderSize, upperBorder.getSize().x, leftBorder.getSize().y);
}

void GameWindow::drawBorders()
{
    draw(upperBorder);
	draw(lowerBorder);
	draw(leftBorder);
	draw(rightBorder);
}

void GameWindow::drawPlayerName(const sf::String &playerNameString)
{
	playerName.setString( "Player: " + playerNameString);
	draw(playerName);
}

void GameWindow::drawGameTime(const sf::Time &gameTime)
{
	timeText.setString("Game time: " + generateTimeString(gameTime));	
	draw(timeText);
}

void GameWindow::drawLifes(int numberOfLifes){
	
	lifesText.setString("Lifes: ");
	draw(lifesText);
	
	for(int i = 0; i < numberOfLifes; i++ )
	{
		lifeIcon.setPosition(sf::Vector2f(550 + i*100, 25));
		draw(lifeIcon);
	}
	
}

sf::String GameWindow::generateTimeString(const sf::Time &gameTime)
{
	int minutes = 0;
	int seconds = 0;
	char charGameTime[6] = "\0";
	char *ptrCharGameTime = charGameTime;	
	
	if( int(gameTime.asSeconds())%60 > 0)
		minutes = int (gameTime.asSeconds()/60);
	seconds = gameTime.asSeconds() - minutes*60;
	sprintf(ptrCharGameTime, "%02d:%02d", minutes, seconds);
	
	
	return sf::String(ptrCharGameTime);	
}

void GameWindow::configureLifeIcon()
{		
	if (!lifeTexture.loadFromFile("../joint.png"))
	{
		// error...
	}
	lifeIcon.setSize(sf::Vector2f(80,60));
	
	lifeIcon.setTexture(&lifeTexture);
}
