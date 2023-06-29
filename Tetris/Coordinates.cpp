#include "Coordinates.h"

void Coordinates::move_left()
{
	m_axisX -= 1;
}

void Coordinates::move_right()
{
	m_axisX += 1;
}

void Coordinates::move_down()
{
	m_axisY += 1;
}

void Coordinates::set_axisX(const int new_coordinate)
{
	m_axisX = new_coordinate;
}

void Coordinates::set_axisY(const int new_coordinate)
{
	m_axisY = new_coordinate;
}

int Coordinates::get_axisX() const
{
	return m_axisX;
}

int Coordinates::get_axisY() const
{
	return m_axisY;
}
