#include "HighScore.h"
#include <string>
#include <iostream>

HighScore::HighScore()
{
	highScoreTxt.loadFromFile("score_snake.png", sf::IntRect(0, 0, 960, 32));
	scoreSprite.setTexture(highScoreTxt);
	scoreSprite.setPosition(0.0f, 640.0f);

	if (!scoreFont.loadFromFile("fonter.otf"))
	{
		std::cout << "Failure font" << std::endl;
	}
	
	scoreText.setFont(scoreFont);
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setCharacterSize(30);
	scoreText.setPosition(340.0f, 640.0f);
	scoreText.setString("U no $");



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
