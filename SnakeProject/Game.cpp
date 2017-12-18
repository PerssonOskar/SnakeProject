#include "Game.h"

sf::Vector2f Game::converttPos(sf::Vector2i pos)
{
	sf::Vector2f convertedPosToPixel = sf::Vector2f((pos.x * 32), (pos.y * 32));
	return convertedPosToPixel;
}



Game::Game()
{
	lastDirection = Non;
	ifAliveWall = Non;
	ifAliveSnake = Non;
	collFood = Non;
}

Game::~Game()
{
}

Direction Game::getLastDirection() const
{
	return this->lastDirection;
}

void Game::update()
{
	ifAliveWall = LeSnake.checkWallCollission();
	ifAliveSnake = LeSnake.checkSnakeCollision();
	checkCollisionfood();
	//collFood = checkCollisionfood();

	std::cout << std::to_string(ifAliveWall) << std::endl;
	if (ifAliveWall != Stop)
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
	}

	//FIIIIIIIXXXAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

	if (ifAliveSnake != Stop)
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
	}


	

	//LeSnake.update(lastDirection);
}

void Game::draw(sf::RenderTarget & t, sf::RenderStates s) const
{
	t.draw(LeFood);
	t.draw(LeSnake);
}

void Game::checkCollisionfood()
{
	//Direction killDirection = Non;

	sf::Vector2f headPos = converttPos(LeSnake.getHeadPosition());
	sf::Vector2f headPosRightDown = converttPos(LeSnake.getHeadPosition()) + sf::Vector2f(32, 32);

	sf::Vector2f foodPos = LeFood.getFoodPosition();
	sf::Vector2f foodPosRIghtDown = LeFood.getFoodPosition() + sf::Vector2f(32, 32);

	
	if (headPos.x >= foodPos.x && headPos.x <= foodPosRIghtDown.x && headPosRightDown.y >= foodPos.y && headPosRightDown.y <= foodPosRIghtDown.y)
	{
		LeFood.update();
		LeSnake.addBodyPart();
	}
	if (headPosRightDown.x >= foodPos.x && headPosRightDown.x <= foodPosRIghtDown.x && headPosRightDown.y >= foodPos.y && headPosRightDown.y <= foodPosRIghtDown.y)
	{
		LeFood.update();
		LeSnake.addBodyPart();
	}
	if (headPos.x >= foodPos.x && headPos.x <= foodPosRIghtDown.x && headPos.y >= foodPos.y && headPos.y <= foodPosRIghtDown.y)
	{
		LeFood.update();
		LeSnake.addBodyPart();
	}
	if (headPosRightDown.x >= foodPos.x && headPosRightDown.x <= foodPosRIghtDown.x && headPos.y >= foodPos.y && headPos.y <= foodPosRIghtDown.y)
	{
		LeFood.update(); 
		LeSnake.addBodyPart();
	}


	//return killDirection;
}

void Game::move()
{
	LeSnake.update(lastDirection);
}

