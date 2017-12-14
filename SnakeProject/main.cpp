#include <sfml/Graphics.hpp>
#include "Snake.h"

int main()
{
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(960, 640), "Snake", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	//player.setFillColor(sf::Color::Green);
	player.setPosition(000.0f, 200.0f);

	/*sf::Texture plTxture;
	plTxture.loadFromFile("head_snake.png");
	player.setTexture(&plTxture);*/
	
	Snake theSnake;
	float dt;
	float timeSinceLastFrame;
	Direction lastDirection = Right;

	window.draw(theSnake);

	//sf::Vector2f dir = { 0,0 };

	timeSinceLastFrame = 0;

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			lastDirection = Left;
			
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			lastDirection = Right;
			
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			lastDirection = Up;
			//move();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			lastDirection = Down;
			//move();
		}

		dt = clock.restart().asSeconds();
		timeSinceLastFrame += dt;
		

		if (timeSinceLastFrame > 1.f)
		{
			///	player.move(direc);
			theSnake.update(lastDirection);
			timeSinceLastFrame = 0;
		}

		window.clear();
		window.draw(theSnake);
		window.display();
	}

	return 0;
}