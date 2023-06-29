#pragma once

class Coordinates
{
public:
	void move_left();
	void move_right();
	void move_down();

	void set_axisX(const int new_coordinate);
	void set_axisY(const int new_coordinate); 

	int get_axisX() const;
	int get_axisY() const;
	
private:
	int m_axisX{ 0 };
	int m_axisY{ 0 };
};