#ifndef SNAKE_H
#define SNAKE_H
#include "SFML\Graphics.hpp"

class Snake : public sf::Drawable
{
private: 
	sf::RectangleShape* Segments;
	int size;
	int capacity;
	sf::Vector2f direction;
	float speed;
	//std::string playerName;

public:
	Snake();
	~Snake();

	void update(float time);
	void draw(sf::RenderTarget& t, sf::RenderStates& s) const;

};

#endif
