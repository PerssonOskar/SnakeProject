#include "SnakeBody.h"

SnakeBody::SnakeBody()
{
	textureBody.loadFromFile("body_snake.png", sf::IntRect(10, 10, 32, 32));
	spriteBody.setTexture(textureBody);
}

SnakeBody::~SnakeBody()
{
}
