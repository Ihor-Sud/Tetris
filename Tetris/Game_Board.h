#pragma once
#include <array>

class Game_Board
{
private:
	static const int m_heigth{ 20 }; // the height of the game board
	static const int m_width{ 10 }; // the width of the game board

	std::array<std::array<int, m_width>, m_heigth> m_game_board { 0 };
};

