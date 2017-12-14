#include "food.h"

food::food()
{
	foodTexture.loadFromFile("body_snake.png", sf::IntRect(0, 0, 32, 32));

	spritefood.setTexture(foodTexture);
	spritefood.setOrigin(sf::Vector2f(16, 16)); 
}

food::~food()
{
}
