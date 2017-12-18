#include "food.h"
#include <math.h>

sf::Vector2f food::convertPosi(sf::Vector2i pos)
{
	sf::Vector2f convertedPosToPixel = sf::Vector2f((pos.x * 32), (pos.y * 32));
	return convertedPosToPixel;
}

food::food()
{
	foodTexture.loadFromFile("food_snake.png", sf::IntRect(0, 0, 32, 32));

	spritefood.setTexture(foodTexture);

	/*float xPos = float(rand() % int(640));
	float yPos = float(rand() % int(200));*/
	

	int xCoPos = (rand() % 30);
	int yCoPos = (rand() % 20);
	sf::Vector2f randPos = convertPosi(sf::Vector2i(xCoPos, yCoPos));
	
	
	spritefood.setPosition(randPos);

	//spritefood.setOrigin(sf::Vector2f(float(rand() % int(640)), float(rand() % int(200))));
}

food::~food()
{
}

sf::Vector2f food::randPosition()
{
	int xCoPos = (rand() % 30);
	int yCoPos = (rand() % 20);
	sf::Vector2f randPos = convertPosi(sf::Vector2i(xCoPos, yCoPos));
	return randPos;
}

sf::Vector2f food::getFoodPosition() const
{
	return this->spritefood.getPosition();
}

void food::update()
{
	setFoodPosition();
}

void food::setFoodPosition()
{
	sf::Vector2f randPos = randPosition();
	spritefood.setPosition(randPos);
}

void food::draw(sf::RenderTarget & t, sf::RenderStates s) const
{
	t.draw(spritefood);
}
