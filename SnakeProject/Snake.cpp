#include "Snake.h"
#include "SFML\Graphics.hpp"

Snake::Snake()
{
	this->capacity = capacity;
	this->Segments = new sf::RectangleShape[capacity];
	this->size = 0;
	this->direction = direction;
	this->speed = speed;

}

Snake::~Snake()
{
	delete[] Segments;
}

void Snake::update(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		direction = { -0.1f, 0.0f };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		direction = { 0.1f, 0.0f };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		direction = { 0.0f, -0.1f };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		direction = { 0.0f, 0.1f };
	}
}

void Snake::draw(sf::RenderTarget & t, sf::RenderStates & s) const
{
	Segments[size].setFillColor(sf::Color::Yellow);

	for (int i = 0; i < this->size; i++)
	{

	}
}
