#include <sfml/Graphics.hpp>
#include "Snake.h"
#include "food.h"
#include "Game.h"
#include <math.h>
#include <ctime>
#include <iostream>

int main()
{
	srand(time(0));

	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(960, 672), "Snake", sf::Style::Close | sf::Style::Titlebar);
	
	/*sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setPosition(000.0f, 200.0f);*/

	/*sf::Texture plTxture;
	plTxture.loadFromFile("head_snake.png");
	player.setTexture(&plTxture);*/
	Game theGame;

	//Snake theSnake;
	//food theFood;
	float dt;
	float timeSinceLastFrame;
	//Direction lastDirection = Non;

	//window.draw(theSnake);

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
		


		//Ändra nedastående till game klassen---------------------
		/*Direction ifAlive = Non;
		ifAlive = theSnake.checkCollission();
		Direction collFood;
		collFood = theGame.checkCollisionfood();

		std::cout << std::to_string(ifAlive) << std::endl;
		if(ifAlive != Stop)
		{
			
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
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				lastDirection = Down;
			}

		}
		else
		{
			lastDirection = Stop;
		}*/
		
		theGame.update();

		dt = clock.restart().asSeconds();
		timeSinceLastFrame += dt;
		

		if (timeSinceLastFrame > 0.5f)
		{
			///	player.move(direc);

			theGame.move();
			timeSinceLastFrame = 0;
		}

		window.clear();
		window.draw(theGame);
		//window.draw(theFood);
		window.display();
	}

	return 0;
}