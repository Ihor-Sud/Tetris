#include <SFML/Graphics.hpp>
#include "Game_Board.h"
#include "Coordinates.h"
#include "Tetromino.h"

int main()
{
	// the size of the window and its name
	sf::RenderWindow window(sf::VideoMode(320, 480), "Tetris");
 
	Tetromino tetromino;

	std::array<Coordinates, tetromino.MAX_SQUARE_COUNT> coordinates;

	sf::Clock clock;
	float delay{ 0.5f };

	sf::RectangleShape square(sf::Vector2<float>(17.f, 17.f));
	square.setFillColor(sf::Color::Blue);
	square.setOutlineThickness(1.f);
	square.setOutlineColor(sf::Color::Black);

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

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					tetromino.rotate = true;
				}
				else if (event.key.code == sf::Keyboard::Left)
				{
					tetromino.horizontal_movement = -1;
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					tetromino.horizontal_movement = 1;
				}
			}
		}

		for (int square_num = 0; square_num < tetromino.MAX_SQUARE_COUNT; ++square_num)
		{
			coordinates[square_num].axis_x += tetromino.horizontal_movement;
		}

		tetromino.horizontal_movement = 0; 

		if (tetromino.rotate == true)
		{
			// I specify the center of rotation - coordinates of the second square of the tetramino
			Coordinates center = coordinates[1];

			// I calculate the displacement of each square of the tetramino using a formula
			for (int square_num = 0; square_num < tetromino.MAX_SQUARE_COUNT; ++square_num)
			{
				// new_X = center_X + (old_X - center_X) * cos(90°) - (old_Y - center_Y) * sin(90°)
				// new_Y = center_Y + (old_Y - center_Y) * cos(90°) - (old_X - center_X) * sin(90°)
				// 
				// cos(90°) = 0 && sin(90°) = 1
				// ==> 
				// new_X = center_X - (old_Y - center_Y)
				// new_Y = center_Y - (old_X - center_X)

				int temp_axis_x = coordinates[square_num].axis_y - center.axis_y; // old_Y - center_Y
				int temp_axis_y = coordinates[square_num].axis_x - center.axis_x; // old_X - center_X

				coordinates[square_num].axis_x = center.axis_x - temp_axis_x;
				coordinates[square_num].axis_y = center.axis_y + temp_axis_y; 
			}

			tetromino.rotate = false;
		}

		float time = clock.getElapsedTime().asSeconds();

		if (time > delay)
		{
			// As soon as the delay passes, I move all the squares of the tetramino one step down
			for (int square_num = 0; square_num < tetromino.MAX_SQUARE_COUNT; ++square_num)
			{
				coordinates[square_num].axis_y += 1; 
			}

			clock.restart();
		}

		// first appearance of the tetromino
		if (tetromino.is_first_appearance == true)
		{
			// I find out the displacement of each square of the tetromino
			for (int square_num = 0; square_num < tetromino.MAX_SQUARE_COUNT; ++square_num)
			{
				coordinates[square_num].axis_x = tetromino.m_type['Z'][square_num] % 2;
				coordinates[square_num].axis_y = tetromino.m_type['Z'][square_num] / 2;
			}

			tetromino.is_first_appearance = false;
		}
		
		
		

		// I set the background color - white
		window.clear(sf::Color::White);

		for (int square_num = 0; square_num < 4; ++square_num)
		{
			// I set each square of the tetromino to the appropriate position, taking into account the displacement and dimension
			square.setPosition(static_cast<float>(coordinates[square_num].axis_x * 18), static_cast<float>(coordinates[square_num].axis_y * 18));
			
			window.draw(square);
		}

		window.display();
	}

	return 0;
}

