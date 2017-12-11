#include "SnakeHead.h"

SnakeHead::SnakeHead()
{
	textureHead.loadFromFile("head_snake.png", sf::IntRect(10, 10, 32, 32));
	spriteHead.setTexture(textureHead);
}

SnakeHead::~SnakeHead()
{

}
