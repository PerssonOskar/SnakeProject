#ifndef GAME_H
#define GAME_H
#include "Snake.h"
#include "food.h"
#include "HighScore.h"

class Game : public sf::Drawable
{
private:
	Snake LeSnake;
	food LeFood;
	HighScore LeHighScore;
	Direction lastDirection;
	Direction ifAliveWall;
	Direction ifAliveSnake;
	Direction collFood;
		
	//skapa klass food, ska inneh�la position och sprite, ocks� bhe�va funktion som �ndrar d� �ten

	sf::Vector2f converttPos(sf::Vector2i pos);

public:
	Game();
	~Game();
	
	Direction getLastDirection() const;

	void update();
	
	void draw(sf::RenderTarget& t, sf::RenderStates s) const;
	
	void checkCollisionfood();

	void move();

};

#endif // !GAME_H
