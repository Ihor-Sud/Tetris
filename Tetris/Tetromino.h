#pragma once

#include <array>
#include "Coordinates.h"
#include "Square.h" 


class Tetromino
{
public:
	Tetromino();
	~Tetromino() = default;

	void move_left();
	void move_right();
	void rotate();
	void move_down();

public:
	// each tetromino type is visually similar to one of the letters:
	enum Type : const uint16_t
	{
		I, S, Z, T, L, J, O,   COUNT = 7
	};

	// tetromino --> geometric figure, consisting of FOUR interconnected squares
	static const int MAX_SQUARE_COUNT{ 4 };

public:
	const std::array<uint16_t, Tetromino::MAX_SQUARE_COUNT>& operator[](const int index) const;

	// I set each square to its position and draw it
	void set_and_draw(sf::RenderTarget& window, Type type); 
	
private:
	// this variable store all types of tetromino
	std::array<std::array<uint16_t, Tetromino::MAX_SQUARE_COUNT>, Type::COUNT> m_type;

	// this variable simulates the work of one single square of the tetromino
	Square m_square{ 16.0f, 2.0f };

	// this variable is needed to work with the coordinates of each individual square of the tetromino
	std::array<Coordinates, Tetromino::MAX_SQUARE_COUNT> m_square_coordinates;

	// this variable is needed in order to understand whether the tetromino appeared for the first time
	bool m_is_first_appearance{ true }; 
};

