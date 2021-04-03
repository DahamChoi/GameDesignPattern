#pragma once

class Grid;

class Unit
{
	friend class Grid;

public:
	explicit Unit(Grid* grid, float x, float y)
		: MyGrid{ grid }, PosX{ x }, PosY{ y } {}

	void Move(float x, float y);

private:
	float PosX, PosY;
	Grid* MyGrid;
};