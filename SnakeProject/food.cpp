#include "food.h"
#include <math.h>

food::food()
{
	foodTexture.loadFromFile("food_snake.png", sf::IntRect(0, 0, 32, 32));

	spritefood.setTexture(foodTexture);

	//spritefood.setOrigin(sf::Vector2f(float(rand() % int(640)), float(rand() % int(200))));
}

food::~food()
{
}

sf::Vector2f food::randPosition() const
{
	float xPos = float(rand() % int(640));
	float yPos = float(rand() % int(200));
	sf::Vector2f randPos = sf::Vector2f(xPos, yPos);
	return randPos;
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
