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


	new_game_pos =  sf::Vector2f {static_cast<float>(WIDTH-WIDTH/2),static_cast<float>(HEIGHT-100)};
	set_name_pos =  sf::Vector2f {static_cast<float> (WIDTH-WIDTH/2),static_cast<float>(HEIGHT-300)};
	close_pos =  sf::Vector2f {static_cast<float>(WIDTH-WIDTH/2),static_cast<float>(HEIGHT-500)};

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
	set_name_b.setPosition(set_name_pos  );
	 close_b.setPosition(close_pos);


	text_new_game.setFont(font); // font is a sf::Font
	text_set_name.setFont(font);
	text_close.setFont(font);
// set the string to display
	text_new_game.setString("  NOWA GRA");
	text_set_name.setString("     PODAJ \n     KSYWE");
	text_close.setString("     WYJDZ");
// set the character size
	// in pixels, not points!
	text_new_game.setCharacterSize(55);
	text_set_name.setCharacterSize(55);
	text_close.setCharacterSize(55);
// set the color
	text_new_game.setColor(sf::Color::Black);
	text_set_name.setColor(sf::Color::Black);
	text_close.setColor(sf::Color::Black);
// set the text style
	//text_new_game.setStyle(sf::Text::Bold  );
	//text_set_name.setStyle(sf::Text::Bold  );
	//   text_close.setStyle(sf::Text::Bold  );
	// set orgin
	text_new_game.setOrigin(button_size.x/2,button_size.y/2);
	text_set_name.setOrigin(button_size.x/2,button_size.y/2);
	text_close.setOrigin(button_size.x/2,button_size.y/2);


// set pos
	text_new_game.setPosition(new_game_pos);
	text_set_name.setPosition(set_name_pos.x, set_name_pos.y-55);
	text_close.setPosition(close_pos);
}

bool Menu::run_menu(sf::RenderWindow& w)
{

	 
	while (true) {
		draw_menu(w);
		w.display();

		while (w.pollEvent(event)) {
			/*if (event.type == sf::Event::MouseMoved) {
				std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
				std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
			}*/
			if (event.type == sf::Event::MouseButtonPressed) {

				if (event.mouseButton.button == sf::Mouse::Left) {
					std::cout << "the left button was pressed" << std::endl;

					if (event.mouseButton.x>new_game_pos.x-button_size.x/2 && event.mouseButton.x<new_game_pos.x+button_size.x/2) {

						if (event.mouseButton.y > new_game_pos.y-button_size.y && event.mouseButton.y < new_game_pos.y) {
							std::cout << "mouse x: " << event.mouseButton.x << std::endl;
							std::cout << "mouse y: " << event.mouseButton.y << std::endl;
							new_game_b.setFillColor(sf::Color::Red);
							draw_menu(w);
							w.display();
							sf::sleep(sf::milliseconds(10));
							new_game_b.setFillColor(sf::Color::Magenta);
							draw_menu(w);
							w.display();
							sf::sleep(sf::milliseconds(20));
							return true;
						}
						if (event.mouseButton.y > close_pos.y-button_size.y && event.mouseButton.y < close_pos.y) {
							std::cout << "mouse x: " << event.mouseButton.x << std::endl;
							std::cout << "mouse y: " << event.mouseButton.y << std::endl;

							close_b.setFillColor(sf::Color::Red);
							draw_menu(w);
							w.display();
							sf::sleep(sf::milliseconds(10));
							close_b.setFillColor(sf::Color::Magenta);
							draw_menu(w);
							w.display();
							sf::sleep(sf::milliseconds(20));
							return false;
						}

						if (event.mouseButton.y > set_name_pos.y-button_size.y && event.mouseButton.y < set_name_pos.y) {
							std::cout << "mouse x: " << event.mouseButton.x << std::endl;
							std::cout << "mouse y: " << event.mouseButton.y << std::endl;
							set_name_b.setFillColor(sf::Color::Red);

							user_name = set_name(w);
							if (user_name == "_false") {
								return false;
							}
							set_name_b.setFillColor(sf::Color::Magenta);
							draw_menu(w);
						}

					}
				}

			}
			if (event.type == sf::Event::Closed) {
				w.close();
				return false;
			}
		}//while

		/*if(sf::Mouse::isButtonPressed( sf::Mouse::Left ) ) {

			std::cout << sf::Mouse::getPosition( w ).x<< " , "  << sf::Mouse::getPosition( w ).y << std::endl;
			//break;
		}*/
	}//while true


	return true;
}
std::string Menu::get_user_name ()
{
	return user_name;
}

std::string Menu::set_name(sf::RenderWindow& w)
{
	sf::Text text,title;
	std::string temp = "";
	text.setFont(font);
	text.setColor(sf::Color::Blue);
	text.setCharacterSize(60);
	text.setPosition(WIDTH/2-150, HEIGHT/2.);

	title.setFont(font);
	title.setString("Podaj swoja ksywe:");
	title.setColor(sf::Color::Blue);
	title.setCharacterSize(60);
	title.setPosition(WIDTH/2-350, 200);
	while (true) {


		while (w.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				w.close();
				return "_false";
			}

			if (event.type == sf::Event::TextEntered) {
				if ((event.text.unicode >= 48 && event.text.unicode <= 57)  || (event.text.unicode >= 65 && event.text.unicode <= 90) ||
				    (event.text.unicode >= 97 && event.text.unicode <= 122))
					if (temp.size() < 8) {
						temp += static_cast<char>(event.text.unicode);

					}
				text.setString(temp);
				if (event.text.unicode == 13) {
					w.clear(sf::Color::Green);
					w.draw(text);
					w.display();
					sf::sleep(sf::milliseconds(100));
					return temp;
				}

				if (event.text.unicode == 27) {
					if (temp.size() >0) {
						temp.clear();
						text.setString(temp);
					} else {
						return "za glupi by podac nazwe";
					}
					w.clear(sf::Color::Green);
					w.draw(text);
					w.display();
					sf::sleep(sf::milliseconds(100));

				}
				if (event.text.unicode == 8) {
					if (temp.size() >0) {
						temp.pop_back();
					}
					text.setString(temp);

				}

			}
		}//end while event

		w.clear(sf::Color::Green);
		w.draw(title);
		w.draw(text);
		w.display();



	}// while true
	return temp;
}

void Menu::intro(sf::RenderWindow& w)
{

	sf::Text text;
	std::string temp = "Loading.";
	text.setFont(font);
	text.setColor(sf::Color::Blue);
	text.setCharacterSize(60);
	text.setPosition(WIDTH/2-150, HEIGHT/2.);
	
	
	sf::Texture skun;
	skun.loadFromFile("../skun.png");
	sf::Sprite logo;
	logo.setTexture(skun);
	logo.setOrigin(140,0);
	logo.setPosition(WIDTH/2,10);
	
	for (unsigned int i =155 ; i >10; i-=10) {
		w.clear(sf::Color(255,i,255,255));
		if ( i % 25 == 0) {
			temp+=".";
		}

		text.setString(temp);
		w.draw(logo);
		w.draw(text);
		w.display();
		 
	}


}
void Menu::draw_menu(sf::RenderWindow& w)
{
	sf::Text text;
	text.setString("Witaj w grze "+user_name+" ,skujesz sie ?");
	text.setFont(font);
	text.setColor(sf::Color::Blue);
	text.setCharacterSize(60);
	text.setPosition(10,10);//WIDTH/2-200, 50);


	w.clear(sf::Color::Yellow);
	w.draw(text);
	w.draw(  new_game_b);
	w.draw(  set_name_b);
	w.draw(  close_b);
	w.draw( text_new_game);
	w.draw( text_set_name);
	w.draw( text_close);
}
