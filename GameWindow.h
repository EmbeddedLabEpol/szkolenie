#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

constexpr int borderSize = 3;
constexpr float sideMarginFactor = 0.15;
constexpr float upperMarginFactor = 0.20;
constexpr float playableWidthFactor = 0.70;
constexpr float playableHigthFactor = 0.80;

class GameWindow : public sf::RenderWindow
{
public:
	const int playableWindowHight = 600;
	const int playableWindowWidth = 900;
	
	GameWindow();
	GameWindow(int playableWindowWidth, int playableWindowHight, int windowWidth, int windowHight);
	GameWindow(int windowWidth, int windowHight, std::string windowName);
	~GameWindow();
		
	void drawGUI(sf::Time gameTime = sf::Time().Zero, int numberOfLifes = 3);
	void setDisplayedUserName(std::string);
	sf::FloatRect getPlayableField();
	
	sf::RectangleShape getUpperBorder(){return upperBorder;}
	sf::RectangleShape getLowerBorder(){return lowerBorder;}
	sf::RectangleShape getLeftBorder(){return leftBorder;}
	sf::RectangleShape getRightBorder(){return rightBorder;}
	

private:
	sf::RectangleShape upperBorder;
	sf::RectangleShape lowerBorder;
	sf::RectangleShape leftBorder;
	sf::RectangleShape rightBorder;	
			
	void drawGameTime(sf::Time gameTime);
	void drawLifes(int numberOfLifes = 3);
	void drawUserName(std::string);
	void setBorder(sf::RectangleShape &border, const sf::Vector2f &_borderSize, const sf::Vector2f &borderPosition, const sf::Color borderColor );
	
};

#endif // GAMEWINDOW_H
