#include <sfml/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setFillColor(sf::Color::Green);
	player.setPosition(200.0f, 200.0f);
	

	sf::Vector2f dir = { 0,0 };

	      
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == event.Closed)
				window.close();
		}

			
		
		
			player.move(dir);
		

		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}