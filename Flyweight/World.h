#pragma once

#include "Terrain.h"

#include <vector>
#include <iostream>

class World
{
public:
	static const int WIDTH{ 10 };
	static const int HEIGHT{ 10 };

	explicit World() : Tiles{ HEIGHT, std::vector<Terrain*>(WIDTH, nullptr) } {}

	void generateTerrain()
	{
		for (int y = 0; y < Tiles.size(); y++)
		{
			for (int x = 0; x < Tiles[y].size(); x++)
			{
				if (rand() % 10 == 0)
					Tiles[y][x] = &HillTerrain;
				else
					Tiles[y][x] = &GrassTerrain;
			}
		}

		int x = rand() % WIDTH;
		for (int y = 0; y < Tiles.size(); y++)
		{
			Tiles[y][x] = &RiverTerrain;
		}
	}

	void showTerrain()
	{
		for (int y = 0; y < Tiles.size(); y++)
		{
			for (int x = 0; x < Tiles[y].size(); x++)
			{
				std::cout << *Tiles[y][x];
			}
			std::cout << std::endl;
		}
	}

private:
	Terrain GrassTerrain{ 0, false, "GrassTexture.png" };
	Terrain HillTerrain{ 3, false, "HillTexture.png" };
	Terrain RiverTerrain{ 6, true, "Water.png" };

	std::vector<std::vector<Terrain*>> Tiles;
};