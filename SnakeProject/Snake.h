#ifndef SNAKE_H
#define SNAKE_H
#include "SFML\Graphics.hpp"
#include "SnakeBody.h"
//#include "SnakeHead.h"
#include <iostream>

enum Direction {Up, Right, Down, Left};

class Snake : public sf::Drawable
{
private: 

	int positionUpdater;
	SnakeBody* Segments;
	int size;
	int capacity;
	//sf::Vector2f direction;
	Direction direction;
	float speed;
	bool head;
	//int partIndex;

	/*sf::Texture bodyTexture;
	sf::Texture headTexture;
	sf::Sprite sprite;*/
	
	//std::string playerName

	sf::Texture bodyTexture;
	sf::Texture headTexture;
	/*sf::Sprite bodySprite;
	sf::Sprite headSprite;*/


	//sf::Texture playerTexture;
	//playerTexture.loadFromFile("snake_head");

public:
	Snake();
	~Snake();

	sf::Vector2i getHeadPosition() const;

	void addBodyPart();
	void setDirection(Direction setDir);

	void update(Direction lastDirection);
	void draw(sf::RenderTarget& t, sf::RenderStates s) const;
	void move();

};

#endif
