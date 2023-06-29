#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Square
{
public:
	Square(const float square_size, const float outline_size);

	void set_position(const float x, const float y);

	void draw(sf::RenderTarget& window) const;
	
	float get_square_size() const;
	float get_outline_size() const;

private:
	float m_square_size;
	float m_outline_size;
	sf::RectangleShape m_square;
};

