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

	if (!font.loadFromFile("../TimesOldAttic.TTF")) {
		// error...
	}

	
	new_game_pos =  sf::Vector2f {WIDTH-WIDTH/2.0,HEIGHT-100.};
	set_name_pos =  sf::Vector2f { WIDTH-WIDTH/2.0,HEIGHT-300.};
	close_pos =  sf::Vector2f {WIDTH-WIDTH/2.0,HEIGHT-500.};

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
	
	
	text_new_game.setFont(font); // font is a sf::Font
	text_set_name.setFont(font);
	   text_close.setFont(font);
// set the string to display
	text_new_game.setString("NEW GAME");
	text_set_name.setString("SET NAME");
	   text_close.setString("CLOSE GAME");
// set the character size
	 // in pixels, not points!
	text_new_game.setCharacterSize(50);
	text_set_name.setCharacterSize(50);
	   text_close.setCharacterSize(50);
// set the color
	text_new_game.setColor(sf::Color::Black);
	text_set_name.setColor(sf::Color::Black);
	   text_close.setColor(sf::Color::Black);
// set the text style
	text_new_game.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text_set_name.setStyle(sf::Text::Bold | sf::Text::Underlined);
	   text_close.setStyle(sf::Text::Bold | sf::Text::Underlined);
	// set orgin
	text_new_game.setOrigin(button_size.x/2,button_size.y);
	text_set_name.setOrigin(button_size.x/2,button_size.y);
	   text_close.setOrigin(button_size.x/2,button_size.y);

	
// set pos
	text_new_game.setPosition(new_game_pos);
    text_set_name.setPosition(set_name_pos);
	   text_close.setPosition(close_pos);
}
void Menu::draw_menu(sf::RenderWindow& w)
{

	w.draw(  new_game_b);
	w.draw(  set_name_b);
	w.draw(  close_b);
	w.draw( text_new_game);
	w.draw( text_set_name);
	w.draw( text_close);
}
