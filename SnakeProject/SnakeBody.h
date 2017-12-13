#ifndef SNAKEBODY_H
#define SNAKEBODY_H
#include <SFML\Graphics.hpp>

class SnakeBody : public sf::Drawable
{
private:
	

	//sf::RectangleShape recShape;
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2i pos;

	// Update:
	// 1. Uppdatera position i pos.
	// 2. "Kasta" in pos i sprite.position(??)

	sf::Vector2f convertPosi(sf::Vector2i pos);

public:

	SnakeBody(sf::Vector2i pos = sf::Vector2i(0,0) );
	~SnakeBody();

	sf::Sprite getSprite() const;
	sf::Vector2i getPosition() const;
	void setPosition(sf::Vector2i newPosi);
	
	void draw(sf::RenderTarget& t, sf::RenderStates s) const;

	void setTexture(sf::Texture);
};

#endif // !SNAKEHEAD_H

