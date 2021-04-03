#pragma once

#include "Unit.h"
#include <list>

class Grid
{
public:
	explicit Grid()
	{

	}

	void Add(Unit* unit)
	{
		int cellX = (int)(unit->PosX / Grid::CELL_SIZE);
		int cellY = (int)(unit->PosY / Grid::NUM_CELLS);
		Cell[cellY][cellX].push_back(unit);
	}

	void Move(Unit* unit, float x, float y)
	{
		int cellX = (int)(unit->PosX / Grid::CELL_SIZE);
		int cellY = (int)(unit->PosY / Grid::NUM_CELLS);

		int newCellX = (int)(x / Grid::CELL_SIZE);
		int newCellY = (int)(y / Grid::NUM_CELLS);

		unit->PosX = x;
		unit->PosY = y;

		if (cellX == newCellX && cellY == newCellY)	return;

		Cell[cellX][cellY].erase(
			find(Cell[cellX][cellY].begin(), Cell[cellX][cellY].end(), unit)
		);
		Cell[newCellX][newCellY].push_back(unit);
	}

	void HandleMelee()
	{
		for (int i = 0; i < NUM_CELLS; i++)
		{
			for (int j = 0; j < CELL_SIZE; j++)
			{
				HandleCell(j, i);
			}
		}
	}

	void HandleCell(int x, int y)
	{
		HandleUnit(Cell[y][x], Cell[y][x]);

		if (x > 0) HandleUnit(Cell[y][x], Cell[y][x - 1]);
		if (y > 0) HandleUnit(Cell[y][x], Cell[y - 1][x]);
		if (x > 0 && y > 0) HandleUnit(Cell[y][x], Cell[y - 1][x - 1]);
		if (x > 0 && y < NUM_CELLS - 1) HandleUnit(Cell[y][x], Cell[y + 1][x - 1]);
	}

	void HandleUnit(std::list<Unit*> unit, std::list<Unit*> other)
	{
		for (auto it : unit)
		{
			for (auto it2 : other)
			{
				if (it == it2) continue;

				if (Distance(it, it2))
				{
					Fight(it, it2);
				}
			}
		}
	}

	bool Distance(Unit* unit, Unit* other)
	{
		return true;
	}


	void Fight(Unit* unit, Unit* other)
	{
		
	}

	static const int NUM_CELLS = 10;
	static const int CELL_SIZE = 20;

private:
	std::list<Unit*> Cell[NUM_CELLS][CELL_SIZE];
};