#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
class Menu
{
public:
	Menu(int w, int h);
	~Menu();
	bool run_menu(sf::RenderWindow& w);
	void draw_menu(sf::RenderWindow& w);
	std::string get_user_name ();

private:

	int WIDTH  ;
	int HEIGHT ;
	
	sf::Vector2f new_game_pos;
	sf::Vector2f set_name_pos;
	sf::Vector2f close_pos;
	
	sf::Vector2f button_size{	sf::Vector2f(400.0 , 150.0)     };
	
	sf::RectangleShape new_game_b;
	sf::RectangleShape set_name_b;
	sf::RectangleShape close_b;

	sf::Font font;
	
	sf::Text text_new_game;
	sf::Text text_set_name;
	sf::Text text_close;
	
	sf::Event event;
	
	std::string user_name = "Lolek";
	void init();
	void intro(sf::RenderWindow& w);
	std::string set_name(sf::RenderWindow& w);
	
};

#endif // MENU_H
