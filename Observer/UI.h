#pragma once

#include <iostream>

class OPlayer;

class OUI
{
public:
	OUI(OPlayer* player) : Player{ player } {}

	friend std::ostream& operator<<(std::ostream& os, const OUI& obj)
	{
		for (int i = 0; i < OPlayer::MAX_HP; i++)
		{
			if (i < obj.Player->HP)
				os << "бс";
			else
				os << "бр";
		}
		return os << std::endl;
	}

private:
	OPlayer* Player;
};