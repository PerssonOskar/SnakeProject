#include "SnakeBody.h"

sf::Vector2f SnakeBody::convertPosi(sf::Vector2i pos)
{
	sf::Vector2f convertedPosToPixel = sf::Vector2f((pos.x * 16), (pos.y*16));
	return convertedPosToPixel;
}

SnakeBody::SnakeBody(sf::Vector2i pos)
{
	this->pos = pos;
	
	sprite.setOrigin(sf::Vector2f(16, 16));
	
	
	
	//bodyTexture.loadFromFile("body_snake.png", sf::IntRect(0, 0, 32, 32));
	//headTexture.loadFromFile("body_snake.png", sf::IntRect(0, 0, 32, 32));

	//sprite.setTexture(bodyTexture);
	//sprite.setOrigin(sf::Vector2f(16, 16)); // Ändra mittpunkt i sprite
	//sprite.setTextureRect({ 0,0,32,32 });
}

SnakeBody::~SnakeBody()
{
}

sf::Vector2i SnakeBody::getPosition() const
{
	
	sf::Vector2i urrentPosition = pos;
	
	/*sf::Vector2f SpritePosition = sprite.getPosition();
	return SpritePosition;*/
	return urrentPosition;
}

void SnakeBody::setPosition(sf::Vector2i newPosi)
{
	this->pos += newPosi;

	sprite.setPosition(this->convertPosi(this->pos));

	// Update pos i given direction, ett FIXED antal steg
	// pos (vector2i), ska innehålla box-index (ex x:[0,39], y:[0,19] (Med ett fönster på 400x200 pixlar där varje box är 10x10 pixlar
	// sprite.pos, ska innehålla PIXEL-positionen i ditt window. 
}

void SnakeBody::draw(sf::RenderTarget & t, sf::RenderStates s) const
{
	t.draw(sprite);
}

void SnakeBody::setTexture(sf::Texture texture)
{
	sprite.setTexture(texture);
}
