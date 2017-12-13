#include "Snake.h"
#include "SFML\Graphics.hpp"
#define CAP 10


Snake::Snake()
{
	this->capacity = CAP;
	this->Segments = new SnakeBody[CAP];
	this->size = 0;
	this->direction = Up;
	this->speed = speed;

	for (int i = 0; i < 3; i++)
	{
		Segments[i].setPosition({ 200, 100 + 32 * i });
	}


	//Behöver göra: huvudet ska placeras, 




	//if (!texture.loadFromFile("body_snake.png", sf::IntRect(10, 10, 32, 32)))
	//{
	//	// error...
	//}

	texture.loadFromFile("body_snake.png", sf::IntRect(10, 10, 32, 32));

	sprite.setTexture(texture);

}

Snake::~Snake()
{
	delete[] Segments;
}

void Snake::addBodyPart()
{
}

void Snake::setDirection(Direction setDir)
{

}

void Snake::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		direction = Left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		direction = Right;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		direction = Up;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		direction = Down;
	}
}

void Snake::draw(sf::RenderTarget & t, sf::RenderStates s) const
{

	for (int i = 0; i < 3; i++)
	{
		t.draw(Segments[i]);
	}
	/*
	*	for(alla bodyparts)
	*	{
	*		t.draw(segments[i].getSprite());
	*	}
	*/
}

void Snake::move()
{
	switch (direction)
	{
	case Left:
		sf::Vector2f dir = Segments[positionUpdater]
		Segments[positionUpdater].setPosition(sf::Vector2i(-1,0));
		break;
	case Right:
		Segments[positionUpdater].setPosition(sf::Vector2i(1, 0));
		break;
	case Up:
		Segments[positionUpdater].setPosition(sf::Vector2i(0, -1));
		break;
	case Down:
		Segments[positionUpdater].setPosition(sf::Vector2i(0, 1));
		break;
	}
}
