#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H
#include "Snake.h"

class SnakeHead : public Snake
{
private:


	sf::Texture textureHead;
	sf::Sprite spriteHead;

public:
	SnakeHead();
	~SnakeHead();


};

#endif // !SNAKEHEAD_H

