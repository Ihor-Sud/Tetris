#pragma once
#include <array>
#include <unordered_map>



struct Tetromino
{
	// tetromino --> geometric figure, consisting of FOUR interconnected squares
	static const int MAX_SQUARE_COUNT{ 4 };

	// each tetromino type is visually similar to one of the letters:
	std::unordered_map<char, std::array<int, 4> > m_type
	{
		{ 'I', { 1, 3, 5, 7 } },
		{ 'S', { 2, 4, 5, 7 } },
		{ 'Z', { 3, 5, 4, 6 } },
		{ 'T', { 3, 5, 4, 7 } },
		{ 'L', { 2, 3, 5, 7 } },
		{ 'J', { 3, 5, 7, 6 } },
		{ 'O', { 2, 3, 4, 5 } }
	};
};

