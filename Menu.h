#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
class Menu
{
public:
	Menu(int w, int h);
	~Menu();
	void draw_menu(sf::RenderWindow& w);

private:

	int WIDTH  ;
	int HEIGHT ;
	sf::Vector2f button_size(200.,150.);
	void init();
	sf::RectangleShape new_game_b;
	sf::RectangleShape set_name_b;
	sf::RectangleShape close_b;

};

#endif // MENU_H
