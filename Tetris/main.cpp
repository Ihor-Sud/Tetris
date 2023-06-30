#include <SFML/Graphics.hpp>
#include "Tetromino.h"
#include "Square.h"
#include "Coordinates.h"


int main()
{
	// the game window size and its name
	sf::RenderWindow tetris_window(sf::VideoMode(320, 480), "Tetris"); 


	Tetromino tetromino;
	sf::Clock clock; 

	// the game runs while the window is open
	while (tetris_window.isOpen())
	{
		// ********** user actions ********** //

		sf::Event event;
		while (tetris_window.pollEvent(event))
		{
			// if the user clicks on "close" ...
			if (event.type == sf::Event::Closed)
			{
				tetris_window.close();
			}

			// if the user pressed a key on the keyboard ...
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					tetromino.rotate();
				}
				else if (event.key.code == sf::Keyboard::Left)
				{
					tetromino.move_left();
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					tetromino.move_right();
				}
			}
		}


		// ********** tetromino movement ********** //
		
		sf::Time elapsed_time = clock.getElapsedTime();  
		if (elapsed_time.asSeconds() >= 0.3f) /* ... >= delay */ 
		{
			tetromino.move_down();

			clock.restart();  
		}


		// ********** display ********** //

		// the background color of the game board is white
		tetris_window.clear(sf::Color::White);

		// I set each square of the tetromino to its position and draw it
		Tetromino::Type type{ Tetromino::Type::T };
		tetromino.set_and_draw(tetris_window, type);

		// drawing the game window
		tetris_window.display();
	}


	return 0;
}