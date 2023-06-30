#include "Tetromino.h"

Tetromino::Tetromino()
{
	m_type[Type::I] = { 1, 3, 5, 7 };
	m_type[Type::S] = { 2, 4, 5, 7 };
	m_type[Type::Z] = { 3, 5, 4, 6 };
	m_type[Type::T] = { 3, 5, 4, 7 };
	m_type[Type::L] = { 2, 3, 5, 7 };
	m_type[Type::J] = { 3, 5, 7, 6 };
	m_type[Type::O] = { 2, 3, 4, 5 };
}

void Tetromino::move_left()
{
	// checking if the square of the tetromino goes beyond the boundaries of the game board
	for (uint16_t square_num = 0; square_num < Tetromino::MAX_SQUARE_COUNT; ++square_num)
	{
		if (m_square_coordinates[square_num].get_axisX() <= 0) 
		{
			return;
		}
	}

	// each square of the shape moves one pixel to the left
	for (uint16_t square_num = 0; square_num < Tetromino::MAX_SQUARE_COUNT; ++square_num)
	{
		m_square_coordinates[square_num].move_left();
	}
}

void Tetromino::move_right()
{
	// checking if the square of the tetromino goes beyond the boundaries of the game board
	for (uint16_t square_num = 0; square_num < Tetromino::MAX_SQUARE_COUNT; ++square_num)
	{
		if (m_square_coordinates[square_num].get_axisX() >= Game_Board::m_width)
		{
			return;
		}
	}

	// each square of the tetramino moves one pixel to the right
	for (uint16_t square_num = 0; square_num < Tetromino::MAX_SQUARE_COUNT; ++square_num)
	{
		m_square_coordinates[square_num].move_right();
	}
}

void Tetromino::rotate()
{
	// checking if the square of the tetromino goes beyond the boundaries of the game board
	for (uint16_t square_num = 0; square_num < Tetromino::MAX_SQUARE_COUNT; ++square_num)
	{
		if (	m_square_coordinates[square_num].get_axisY() >= Game_Board::m_height
			 ||	m_square_coordinates[square_num].get_axisX() >= Game_Board::m_width
			 || m_square_coordinates[square_num].get_axisX() <= 0) 
		{
			return;
		}
	}

	// I specify the center of rotation - coordinates of the SECOND square of the tetramino
	int center_axisX = m_square_coordinates[1].get_axisX();
	int center_axisY = m_square_coordinates[1].get_axisY();

	// I calculate the displacement of each square of the tetramino using a formula
	for (int square_num = 0; square_num < Tetromino::MAX_SQUARE_COUNT; ++square_num)
	{
		// new_axisX = center_axisX + (old_axisX - center_axisX) * cos(90°) - (old_axisY - center_axisY) * sin(90°)
		// new_axisY = center_axisY + (old_axisY - center_axisY) * cos(90°) - (old_axisX - center_axisX) * sin(90°)
		// 
		// cos(90°) = 0 && sin(90°) = 1
		// ==> 
		// new_axisX = center_axisX - (old_axisY - center_axisY)
		// new_axisY = center_axisY - (old_axisX - center_axisX)

		int temp_axisX = m_square_coordinates[square_num].get_axisY() - center_axisY; // old_axisY - center_axisY
		int temp_axisY = m_square_coordinates[square_num].get_axisX() - center_axisX; // old_axisX - center_axisX

		m_square_coordinates[square_num].set_axisX(center_axisX - temp_axisX);
		m_square_coordinates[square_num].set_axisY(center_axisY + temp_axisY);
	}
}

bool Tetromino::move_down()
{
	// checking if the square of the tetromino goes beyond the boundaries of the game board
	for (uint16_t square_num = 0; square_num < Tetromino::MAX_SQUARE_COUNT; ++square_num)
	{
		if (m_square_coordinates[square_num].get_axisY() >= Game_Board::m_height)
		{
			return false;
		}
	}

	// each square of the tetramino moves one pixel down
	for (uint16_t square_num = 0; square_num < Tetromino::MAX_SQUARE_COUNT; ++square_num)
	{
		m_square_coordinates[square_num].move_down();
	}

	return true;
}

void Tetromino::set_and_draw(sf::RenderTarget& window, Type type)
{
	// I find out the RELATIVE coordinates of a square relative to a certain tetromino
	if (m_is_first_appearance == true)
	{
		for (int16_t square_num = 0; square_num < Tetromino::MAX_SQUARE_COUNT; ++square_num)
		{
			m_square_coordinates[square_num].set_axisX(m_type[type][square_num] % 2);
			m_square_coordinates[square_num].set_axisY(m_type[type][square_num] / 2);
		}

		m_is_first_appearance = false;
	}


	float real_size{ m_square.get_square_size() + m_square.get_outline_size() };

	// I set each square to its position and draw it
	for (uint16_t square_num = 0; square_num < Tetromino::MAX_SQUARE_COUNT; ++square_num)
	{
		m_square.set_position(m_square_coordinates[square_num].get_axisX() * real_size
			, m_square_coordinates[square_num].get_axisY() * real_size);

		m_square.draw(window);
	}
}

const std::array<uint16_t, Tetromino::MAX_SQUARE_COUNT>& Tetromino::operator[](const int index) const
{
	return m_type[index];
}