#ifndef FOOD_H
#define FOOD_H
#include <SFML\Graphics.hpp>

class food : public sf::Drawable
{
private:

	//sf::Vector2i foodPos;

	sf::Texture foodTexture;
	sf::Sprite spritefood;

	sf::Vector2f convertPosi(sf::Vector2i pos);

public:
	food();
	~food();

	sf::Vector2f randPosition();
	sf::Vector2f getFoodPosition() const;

	void update();
	void setFoodPosition();
	void draw(sf::RenderTarget& t, sf::RenderStates s) const;
};

#endif // !FOOD_H

