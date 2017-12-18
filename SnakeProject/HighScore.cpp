#include "HighScore.h"
#include <string>


HighScore::HighScore()
{
	highScoreTxt.loadFromFile("score_snake.png", sf::IntRect(0, 0, 960, 32));
	scoreSprite.setTexture(highScoreTxt);
	scoreSprite.setPosition(0.0f, 640.0f);

	scoreFont.loadFromFile("arial.tff");
	scoreText.setFont(scoreFont);
	scoreText.setCharacterSize(20);
	scoreText.setPosition(340.0f, 645.0f);



	this->highscore = 0;

}

HighScore::~HighScore()
{
}

void HighScore::addToHighScore()
{
	this->highscore += 10;
	std::string retTxt = "";
	retTxt += std::to_string(highscore);
	scoreText.setString(retTxt);
}

void HighScore::draw(sf::RenderTarget & t, sf::RenderStates s) const
{
	t.draw(scoreSprite);
	t.draw(scoreText);
}
