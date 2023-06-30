#pragma once
#include <array>

struct Game_Board
{
	static const int m_height{ 20 };
	static const int m_width{ 10 }; 

	std::array<std::array<bool, Game_Board::m_width>, Game_Board::m_height> game_board{ false };
};