#include "Menu.h"

Menu::Menu(int w,int h):WIDTH(w), HEIGHT(h)
{
	
	init();
}

Menu::~Menu()
{
}
void Menu::init()
{
	new_game_pos =  sf::Vector2f{WIDTH-WIDTH/2.0,HEIGHT-100.};
	set_name_pos =  sf::Vector2f{ WIDTH-WIDTH/2.0,HEIGHT-300.};
	   close_pos =  sf::Vector2f{WIDTH-WIDTH/2.0,HEIGHT-500.};
	   
	new_game_b.setSize(button_size );
	set_name_b.setSize(button_size );
	   close_b.setSize( button_size);
	   
	new_game_b.setFillColor(sf::Color::Magenta);
	set_name_b.setFillColor(sf::Color::Magenta);
	   close_b.setFillColor(sf::Color::Magenta);
	
	new_game_b.setOrigin(button_size.x/2,button_size.y);
	set_name_b.setOrigin(button_size.x/2,button_size.y);
	   close_b.setOrigin(button_size.x/2,button_size.y);
	
	new_game_b.setPosition(new_game_pos);
	set_name_b.setPosition(set_name_pos);
	   close_b.setPosition(close_pos);
}
void Menu::draw_menu(sf::RenderWindow& w)
{

	w.draw(  new_game_b);
	w.draw(  set_name_b);
	w.draw(  close_b);
}
