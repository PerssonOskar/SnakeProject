#ifndef FOOD_H
#define FOOD_H
#include <SFML\Graphics.hpp>

class food : public sf::Drawable
{
private:
	sf::Texture foodTexture;
	sf::Sprite spritefood;

public:
	food();
	~food();

	sf::Vector2f randPosition() const;

	void update();
	void setFoodPosition();
	void draw(sf::RenderTarget& t, sf::RenderStates s) const;
};

#endif // !FOOD_H

