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
};

#endif // !FOOD_H

