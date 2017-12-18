#include "Snake.h"
#include "SFML\Graphics.hpp"
#define CAP 10


sf::Vector2f Snake::converHeadtPosi(sf::Vector2i pos)
{
	sf::Vector2f convertedPosToPixel = sf::Vector2f((pos.x * 32), (pos.y * 32));
	return convertedPosToPixel;
}

Snake::Snake()
{
	this->capacity = CAP;
	this->Segments = new SnakeBody[CAP];
	this->size = 4;
	this->addedIndex = -1;
	this->direction = Up;
	this->speed = speed;
	this->positionUpdater = (size-1);

	int positionCounter = 10;
	for (int i = 0; i < size; i++)
	{
		Segments[i].setPosition({ 15, 1 * positionCounter });
		positionCounter++;
	}


	//Behöver göra: huvudet ska placeras, 

	bodyTexture.loadFromFile("body_snake.png", sf::IntRect(0, 0, 32, 32));
	headTexture.loadFromFile("head_snake.png", sf::IntRect(0, 0, 32, 32));
	
	Segments[0].setTexture(headTexture);
	for (int i = 1; i < size; i++)
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
	sf::Vector2i lastPosCo = Segments[size-1].getPosition();
	addedIndex = size;

	if (size != capacity)
	{ 		
		Segments[size].setPosition(lastPosCo);
		Segments[size].setTexture(bodyTexture);
	}
	else
	{
		Expand();
		Segments[size].setPosition(lastPosCo);
		Segments[size].setTexture(bodyTexture);
	}
	

	size++;
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
	if(direction != Stop)
	{
		switch (direction)
		{
		case Left:
			//sf::Vector2f dir = Segments[positionUpdater]

		/*	if (addedIndex != -1)
			{
				Segments[addedIndex].setHeadPosition(getHeadPosition());
				addedIndex = -1;
			}
			else
			{*/
				Segments[positionUpdater].setHeadPosition(getHeadPosition());
				positionUpdater = positionUpdater - 1;
				if (positionUpdater == 0)
					positionUpdater = (size - 1);
			//}
			//Segments[positionUpdater].setHeadPosition(getHeadPosition());
			Segments[0].setPosition(sf::Vector2i(-1, 0));
			/*positionUpdater = positionUpdater- 1;
			if (positionUpdater == 0)
				positionUpdater = (size - 1);*/
			break;
		case Right:

			

				Segments[positionUpdater].setHeadPosition(getHeadPosition());
				positionUpdater = positionUpdater - 1;
				if (positionUpdater == 0)
					positionUpdater = (size - 1);
			

			Segments[0].setPosition(sf::Vector2i(1, 0));
			/*positionUpdater = positionUpdater - 1;
			if (positionUpdater == 0)
				positionUpdater = (size - 1);*/
			break;
		case Up:

			
				Segments[positionUpdater].setHeadPosition(getHeadPosition());
				positionUpdater = positionUpdater - 1;
				if (positionUpdater == 0)
					positionUpdater = (size - 1);
			

		//	Segments[positionUpdater].setHeadPosition(getHeadPosition());
			Segments[0].setPosition(sf::Vector2i(0, -1));
			/*positionUpdater = positionUpdater - 1;
			if (positionUpdater == 0)
				positionUpdater = (size - 1);*/
			break;
		case Down:

			
				Segments[positionUpdater].setHeadPosition(getHeadPosition());
				positionUpdater = positionUpdater - 1;
				if (positionUpdater == 0)
					positionUpdater = (size - 1);
			
			
			//Segments[positionUpdater].setHeadPosition(getHeadPosition());
			Segments[0].setPosition(sf::Vector2i(0, 1));
			/*positionUpdater = positionUpdater - 1;
			if (positionUpdater == 0)
				positionUpdater = (size - 1);*/
			break;
		}
	}
}

void Snake::Expand()
{
	this-> capacity += 5;
	SnakeBody* temp = new SnakeBody[capacity];
	for (int i = 0; i < size; i++)
	{
		temp[i] = Segments[i];
	}
	delete[] Segments;
	Segments = temp;

}

Direction Snake::Kill() const
{
	Direction killDirection = Stop;
	return killDirection;
}

Direction Snake::checkWallCollission()
{
	Direction retDirection = Non;

	sf::Vector2f rightX(960.0f, 0.0f);
	sf::Vector2f leftX(0.0f, 0.0f);
	sf::Vector2f upperY(0.0f, 0.0f);
	sf::Vector2f lowerY(0.0f, 640.0f);

	sf::Vector2f headPos = converHeadtPosi(getHeadPosition());
	sf::Vector2f headPosDownRight = converHeadtPosi(getHeadPosition());
	headPosDownRight += sf::Vector2f(32, 32);

	if (headPos.x > rightX.x || headPos.x < leftX.x || headPos.y < upperY.y || headPos.y > lowerY.y)
	{
		retDirection = Kill();
	}
	if (headPosDownRight.x > rightX.x || headPosDownRight.x < leftX.x || headPosDownRight.y < upperY.y || headPosDownRight.y > lowerY.y)
	{
		retDirection = Kill();
	}

	return retDirection;
}

Direction Snake::checkSnakeCollision()
{

	Direction retDirection = Non;

	sf::Vector2f headPos = converHeadtPosi(getHeadPosition());
	sf::Vector2f headPosRightDown = converHeadtPosi(getHeadPosition()) + sf::Vector2f(32, 32);

	for(int i = 1; i < size; i++)
	{
		sf::Vector2f SnakeBodyPos = converHeadtPosi(Segments[i].getPosition());
		sf::Vector2f SnakeBodyPosRIghtDown = converHeadtPosi(Segments[i].getPosition()) + sf::Vector2f(32, 32);

		if (headPos.x == SnakeBodyPos.x && headPosRightDown.x == SnakeBodyPosRIghtDown.x && headPos.y == SnakeBodyPos.y && headPosRightDown.y == SnakeBodyPosRIghtDown.y)
		{
			retDirection = Kill();		
		}
			
	}

	return retDirection;
}
