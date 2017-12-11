#ifndef SNAKEBODY_H
#define SNAKEBODY_H
#include "Snake.h"

class SnakeBody : public Snake
{
private:

	sf::Texture textureBody;
	sf::Sprite spriteBody;

public:
	SnakeBody();
	~SnakeBody();


};

#endif // !SNAKEHEAD_H

