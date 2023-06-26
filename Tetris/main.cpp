#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(320, 480), "Tetris");
 
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// if the user wants to close the window
			if (event.type == sf::Event::Closed)
			{
				// then I close it
				window.close();
			}
		}
 
		// I set the background color - white
		window.clear(sf::Color::White);

		window.display();
	}

	return 0;
}