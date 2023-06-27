#include <SFML/Graphics.hpp>
#include "Game_Board.h"
#include "Coordinates.h"
#include "Tetromino.h"

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

		sf::RectangleShape square(sf::Vector2<float>(17.f, 17.f));
		square.setFillColor(sf::Color::Blue);
		square.setOutlineThickness(1.f); 
		square.setOutlineColor(sf::Color::Black);

		Tetromino tetromino;
		std::array<Coordinates, tetromino.MAX_SQUARE_COUNT> coordinates;

		// I find out the displacement of each square of the tetromino
		for (int square_num = 0; square_num < 4; ++square_num)
		{
			coordinates[square_num].m_x = tetromino.m_type['Z'][square_num] % 2;
			coordinates[square_num].m_y = tetromino.m_type['Z'][square_num] / 2;
		}
 
		// I set the background color - white
		window.clear(sf::Color::White);

		for (int square_num = 0; square_num < 4; ++square_num)
		{
			// I set each square of the tetromino to the appropriate position, taking into account the displacement and dimension
			square.setPosition(static_cast<float>(coordinates[square_num].m_x * 18), static_cast<float>(coordinates[square_num].m_y * 18));
			
			window.draw(square);
		}

		window.display();
	}

	return 0;
}