#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <SFML\Graphics.hpp>

class HighScore : public sf::Drawable
{
private:
	sf::Texture highScoreTxt;
	sf::Sprite scoreSprite;

	sf::Font scoreFont;
	sf::Text scoreText;

	int highscore;

public:
	HighScore();
	~HighScore();


	void addToHighScore();
	void draw(sf::RenderTarget& t, sf::RenderStates s) const;

};

#endif // !HIGHSCORE_H

