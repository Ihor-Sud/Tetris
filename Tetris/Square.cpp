#include "Square.h"

Square::Square(const float square_size, const float outline_size)
	: m_outline_size{ outline_size }
	, m_square_size{ square_size  }
	, m_square{ sf::Vector2<float>::Vector2(square_size, square_size) }
{
	m_square.setFillColor(sf::Color::Blue);
	m_square.setOutlineThickness(outline_size);
	m_square.setOutlineColor(sf::Color::Black);
}

void Square::set_position(const float x, const float y)
{
	m_square.setPosition(x, y);
}

void Square::draw(sf::RenderTarget& window) const
{
	window.draw(m_square);
}

float Square::get_square_size() const
{
	return m_square_size;
}
 
float Square::get_outline_size() const
{
	return m_outline_size;
}
