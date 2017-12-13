#include <sfml/Graphics.hpp>
#include "Snake.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Snake", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	//player.setFillColor(sf::Color::Green);
	player.setPosition(000.0f, 200.0f);

	/*sf::Texture plTxture;
	plTxture.loadFromFile("head_snake.png");
	player.setTexture(&plTxture);*/
	
	Snake theSnake;

	window.draw(theSnake);

	//sf::Vector2f dir = { 0,0 };

	      
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
					window.close();
					break;
			}


			/*if (event.type == event.Closed)
				window.close();*/
		}

			
		
		
		///	player.move(direc);
		

		window.clear();
		window.draw(theSnake);
		window.display();
	}

	return 0;
}