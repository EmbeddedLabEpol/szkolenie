#include "Menu.h"

Menu::Menu(int w,int h):WIDTH(w), HEIGHT(h)
{
}

Menu::~Menu()
{
}
void Menu::init(){
	new_game_b.setSize(button_size );
	 
	set_name_b.setSize(button_size );
	   close_b.setSize( button_size);
	 
}
void Menu::draw_menu(sf::RenderWindow& w)
{

	w.draw(  new_game);
	w.draw(  set_name);
	w.draw(  close);
}
