#include "Snake.h"
#include "SFML\Graphics.hpp"
#define CAP 10


Snake::Snake()
{
	this->capacity = CAP;
	this->Segments = new SnakeBody[CAP];
	this->size = 4;
	this->direction = Up;
	this->speed = speed;
	this->positionUpdater = (size-1);

	
	for (int i = 0; i < size; i++)
	{
		Segments[i].setPosition({ 4, 4 * i });
	}


	//Behöver göra: huvudet ska placeras, 

	bodyTexture.loadFromFile("body_snake.png", sf::IntRect(0, 0, 32, 32));
	headTexture.loadFromFile("head_snake.png", sf::IntRect(0, 0, 32, 32));
	
	Segments[0].setTexture(headTexture);
	for (int i = 0; i < size; i++)
	{
		Segments[i].setTexture(bodyTexture);
	}

	/*bodySprite.setTexture(headTexture);
	headSprite.setTexture(bodyTexture);*/

	//bodySprite.setOrigin(sf::Vector2f(16, 16));// Ändra mittpunkt i sprite
	//headSprite.setOrigin(sf::Vector2f(16, 16));//sprite.setTextureRect({ 0,0,32,32 });

	//if (!texture.loadFromFile("body_snake.png", sf::IntRect(10, 10, 32, 32)))
	//{
	//	// error...
	//}

	

}

Snake::~Snake()
{
	delete[] Segments;
}

sf::Vector2i Snake::getHeadPosition() const
{
	sf::Vector2i HeadPos = Segments[0].getPosition();


	return HeadPos;
}

void Snake::addBodyPart()
{
}

void Snake::setDirection(Direction setDir)
{

}

void Snake::update(Direction lastDirection)//stoppa in i main, skicka hit en direction som är densamma tills man trycker igen.
{

	this->direction = lastDirection;
	move();

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		direction = Left;
		move();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		direction = Right;
		move();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		direction = Up;
		move();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		direction = Down;
		move();
	}*/
}

void Snake::draw(sf::RenderTarget & t, sf::RenderStates s) const
{

	for (int i = 0; i < size; i++)
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
		//sf::Vector2f dir = Segments[positionUpdater]
		Segments[positionUpdater].setPosition(getHeadPosition());
		Segments[0].setPosition(sf::Vector2i(-1, 0));
		positionUpdater = (positionUpdater--) % size;
		if (positionUpdater == 0)
			positionUpdater = (size - 1);
		break;
	case Right:
		Segments[positionUpdater].setPosition(getHeadPosition());
		Segments[0].setPosition(sf::Vector2i(1, 0));
		positionUpdater = (positionUpdater--) % size;
		if (positionUpdater == 0)
			positionUpdater = (size - 1);
		break;
	case Up:
		Segments[positionUpdater].setPosition(getHeadPosition());
		Segments[0].setPosition(sf::Vector2i(0, -1));
		positionUpdater = (positionUpdater--) % size;
		if (positionUpdater == 0)
			positionUpdater = (size - 1);
		break;
	case Down:
		Segments[positionUpdater].setPosition(getHeadPosition());
		Segments[0].setPosition(sf::Vector2i(0, 1));
		positionUpdater = (positionUpdater--) % size;
		if (positionUpdater == 0)
			positionUpdater = (size - 1);
		break;
	}
}
