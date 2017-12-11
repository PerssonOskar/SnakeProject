#ifndef SNAKE_H
#define SNAKE_H
#include "SFML\Graphics.hpp"
#include "SnakeBody.h"
#include "SnakeHead.h"
#include <iostream>

class Snake : public sf::Drawable
{
private: 
	sf::RectangleShape* Segments;
	int size;
	int capacity;
	sf::Vector2f direction;
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

	void update(float time);
	void draw(sf::RenderTarget& t, sf::RenderStates& s) const;
	void move();

};

#endif
