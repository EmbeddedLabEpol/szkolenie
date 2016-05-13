#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

const int WIDTH = 800;
const int HEIGHT = 600;

int rectW = 300;
int rectH = 300;

int tX = WIDTH;
int tY = 550;

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Arcanoid - nasza wypas wersja 1.0");
	int angle = 0;
	int rot = -1;
	int speed = 10;
	double cX = 200;
	double cY = 200;
	
	int r1X = rand() % WIDTH;
	int r1Y = rand() % HEIGHT;
	 
	
	sf::Clock clock; // starts the clock
	sf::Time elapsed = clock.getElapsedTime();
    
	//sf::RectangleShape rectangle(sf::Vector2f(rectW, rectH));
	//rectangle.setPosition(WIDTH/2,HEIGHT/2);
	//rectangle.setOrigin(rectW/2,rectH/2);
	//rectangle.setFillColor(sf::Color(100, 250, 50));
	
	sf::Texture texture;
	if (!texture.loadFromFile("../ruda.png"))
	{
		// error...
	}
	
	
	
	//rectangle.setTexture(texture);
	sf::Sprite rectangle;
	//sf::RectangleShape rectangle(sf::Vector2f(rectW, rectH));
	rectangle.setPosition(WIDTH/2,HEIGHT/2);
	rectangle.setOrigin(rectW/2,rectH/2);
	rectangle.setTexture(texture);
	rectangle.setTextureRect(sf::IntRect(rectW, rectW, rectH, rectH));
	
	sf::Sprite rectangle1;
	//sf::RectangleShape rectangle(sf::Vector2f(rectW, rectH));
	rectangle1.setPosition(r1X, r1Y);
	rectangle1.setOrigin(rectW/4,rectH/4);
	rectangle1.setTexture(texture);
	rectangle1.setTextureRect(sf::IntRect(rectW/2, rectW/2, rectH/2, rectH/2));
	sf::Sprite rectangle2;
	//sf::RectangleShape rectangle(sf::Vector2f(rectW, rectH));
	rectangle2.setPosition(rand() % WIDTH, rand() % HEIGHT);
	rectangle2.setOrigin(rectW/4,rectH/4);
	rectangle2.setTexture(texture);
	rectangle2.setTextureRect(sf::IntRect(rectW/2, rectW/2, rectH/2, rectH/2));
	
	sf::CircleShape circle(50);
	circle.setPosition(cX,cY);
	circle.setOrigin(50,50);
	circle.setFillColor(sf::Color::Red);
	
	sf::Font font;
	sf::Text text;
	font.loadFromFile("../arial.ttf");
	text.setFont(font); // font is a sf::Font
	text.setString("!!! Breakin news !!!");
	text.setCharacterSize(24); // in pixels, not points!
	text.setColor(sf::Color::Magenta);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(tX,tY);
	
	while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {	
			if (event.type == sf::Event::MouseMoved)
			{
				//std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
				//std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
				cX = event.mouseMove.x;
				cY = event.mouseMove.y;
				circle.setPosition(cX,cY);
			}
			
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the left button was pressed" << std::endl;
					rot *= -1;
				}
			}

			if (event.type == sf::Event::MouseWheelMoved)
			{
				std::cout << speed << std::endl;
				if (event.mouseWheel.delta > 0)
				{
					if(speed < 360)
						speed += 1;
					//speed %=360;
				} else
				{
					if(speed > 0)
						speed -= 1;
					//speed %= 360;
				}	
			
			}	
				
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
		
        
		// clear the window with black color
        window.clear(sf::Color::Yellow);
		

		elapsed = clock.getElapsedTime();
		//std::cout << elapsed.asMilliseconds() << std::endl;
		
		if(elapsed.asMilliseconds() > 100) 
		{
			rectangle.rotate(rot * speed);
			std::cout << rot * speed << std::endl;
			angle = angle % 360;
			
			text.setPosition(tX-=10, tY);
			if(tX < -text.getLocalBounds().width)
			{
				tX = WIDTH;
			}
			
			clock.restart();
		}
		
		
		//window.draw(sprite);
		window.draw(rectangle);
		window.draw(rectangle1);
		window.draw(rectangle2);
		window.draw(circle);
		window.draw(text);	
		window.display();
        
    }

    return 0;
}