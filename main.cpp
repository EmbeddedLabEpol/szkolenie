#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
	struct WH {
		const int H=600;
		const int W=800;
	};
	WH rozmiar;
	// create the window
	sf::RenderWindow window(sf::VideoMode(rozmiar.W, rozmiar.H), "My window");
	sf::CircleShape kolo(50);
	sf::RectangleShape kwadrat(sf::Vector2f(100,50));
	sf::Vector2i pozycjaMyszyWzgledemOkna = sf::Mouse::getPosition( window );
	kolo.setOrigin(50,50);
	kolo.setFillColor(sf::Color::Green);
	kwadrat.setOrigin(50,25);
	kwadrat.setFillColor(sf::Color::Red);
	kwadrat.setPosition(rozmiar.W/2,rozmiar.H/2);
	
	float kat=0.0;
	// run the program as long as the window is open
	while (window.isOpen()) {
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed){
				window.close();
			 
			}
			if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) ) {
				std::cout << " lewy klawisz myszy" <<std::endl;
				kat*=-1;
			}
			if( sf::Mouse::isButtonPressed( sf::Mouse::Right ) ) {
				std::cout << " lewy klawisz myszy" <<std::endl;
				kat=0;
			}
			if (event.type == sf::Event::MouseWheelMoved )
			{
				std::cout << " kolo klawisz myszy" << event.mouseWheel.delta<<std::endl;
				 kat+=event.mouseWheel.delta/10.0;
			}
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);

		// end the current frame
		pozycjaMyszyWzgledemOkna = sf::Mouse::getPosition( window );
		kolo.setPosition(pozycjaMyszyWzgledemOkna.x,pozycjaMyszyWzgledemOkna.y);
		
		kwadrat.rotate(kat);
		
		window.draw(kwadrat);
		window.draw(kolo);
		
		window.display();

	}

	return 0;
}
