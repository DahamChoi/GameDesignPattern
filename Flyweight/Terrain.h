#pragma once

#include <string>
#include <ostream>

class Terrain
{
public:
	Terrain(int movementCost, bool isWater, const std::string& textureName)
		: MovementCost{ movementCost }, IsWater{ isWater }, TextureName{ textureName } {}

	// 텍스쳐를 로드해 출력하는 것이라고 가정
	friend std::ostream& operator<<(std::ostream& os, const Terrain& obj)
	{
		if (obj.TextureName == "GrassTexture.png")
		{
			os << "○";
		}
		else if (obj.TextureName == "HillTexture.png")
		{
			os << "※";
		}
		else if (obj.TextureName == "Water.png")
		{
			os << "☆";
		}
		else
		{
			os << "X";
		}

		return os;
	}

private:
	int MovementCost;
	bool IsWater;
	std::string TextureName;
};