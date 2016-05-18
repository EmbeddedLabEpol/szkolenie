#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <cstdio>

constexpr int borderSize = 3;
constexpr float sideMarginFactor = 0.15;
constexpr float upperMarginFactor = 0.20;
constexpr float playableWidthFactor = 0.70;
constexpr float playableHigthFactor = 0.80;

class GameWindow : public sf::RenderWindow
{
public:
	
	GameWindow();
	GameWindow(int windowWidth, int windowHight, std::string windowName);
	~GameWindow();
		
	void drawGUI(const sf::Time gameTime = sf::Time().Zero, int numberOfLifes = 3, sf::String playerName = "Skuwacz");
	void setDisplayedUserName(std::string);
	
	void drawPause();
	void drawEndGame();
	void drawWinGame();
	
	sf::FloatRect getPlayableField();

private:
	sf::RectangleShape upperBorder;
	sf::RectangleShape lowerBorder;
	sf::RectangleShape leftBorder;
	sf::RectangleShape rightBorder;

	sf::RectangleShape lifeIcon;
	
	sf::Font gameWindowFont;
	sf::Text timeText;
	sf::Text playerName;
	sf::Text lifesText;
	sf::Text pauseText{"Przerwa na bucha...", gameWindowFont, 70};
	sf::Text endGameText{"Skułeś sie!", gameWindowFont, 70};
	sf::Text winGameText{"Wygrałeś", gameWindowFont, 70};
	
	sf::Texture lifeTexture;
			
	void drawGameTime(const sf::Time &gameTime);
	void drawLifes(int numberOfLifes = 3);

	void setBorder(sf::RectangleShape &border, const sf::Vector2f &_borderSize, const sf::Vector2f &borderPosition, const sf::Color borderColor );
	void configText(sf::Text &confText, sf::Vector2f textPosition);
	
	void drawBorders();
	void drawPlayerName(const sf::String &playerNameString);
	
	void configureLifeIcon();
	
	sf::String generateTimeString(const sf::Time &gameTime);

	
};

#endif // GAMEWINDOW_H
