#include "SnakeBody.h"

sf::Vector2f SnakeBody::convertPosi(sf::Vector2i pos)
{
	sf::Vector2f convertedPosition(pos.x += 16, pos.y += 16);

	return convertedPosition;
}

SnakeBody::SnakeBody(sf::Vector2i pos)
{
	this->pos = pos;
	texture.loadFromFile("body_snake.png", sf::IntRect(0, 0, 32, 32));
	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(16, 16)); // Ändra mittpunkt i sprite
	//sprite.setTextureRect({ 0,0,32,32 });
}

SnakeBody::~SnakeBody()
{
}

sf::Vector2i SnakeBody::getPosition() const
{

	return sf::Vector2i();
}

void SnakeBody::setPosition(sf::Vector2i newPosi)
{
	this->pos += newPosi;

	sprite.setPosition({ float(pos.x),float(pos.y) });

	// Update pos i given direction, ett FIXED antal steg
	// pos (vector2i), ska innehålla box-index (ex x:[0,39], y:[0,19] (Med ett fönster på 400x200 pixlar där varje box är 10x10 pixlar
	// sprite.pos, ska innehålla PIXEL-positionen i ditt window. 
}

void SnakeBody::draw(sf::RenderTarget & t, sf::RenderStates s) const
{
	t.draw(sprite);
}
