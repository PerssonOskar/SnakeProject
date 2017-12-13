#ifndef SNAKE_H
#define SNAKE_H
#include "SFML\Graphics.hpp"
#include "SnakeBody.h"
//#include "SnakeHead.h"
#include <iostream>

enum Direction {Up, Right, Down, Left};
enum Bool {True, False};

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

	sf::Texture texture;
	//texture.loadFromFile("body_snake.png");
	sf::Sprite sprite;
	
	//std::string playerName


	//sf::Texture playerTexture;
	//playerTexture.loadFromFile("snake_head");

public:
	Snake();
	~Snake();

	void addBodyPart();
	void setDirection(Direction setDir);

	void update();
	void draw(sf::RenderTarget& t, sf::RenderStates s) const;
	void move();

};

#endif
