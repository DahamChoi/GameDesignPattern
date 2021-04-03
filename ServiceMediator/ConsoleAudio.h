#pragma once

#include "Audio.h"

#include <iostream>
#include <vector>

class ConsoleAudio : public Audio
{
public:
	void PlaySound(int soundId) override
	{
		std::cout << "PLAY SOUND! - " << soundId << std::endl;
		PlayingSoundList.push_back(soundId);
	}

	void StopSound(int soundId) override
	{
		std::cout << "STOP SOUND! - " << soundId << std::endl;
		PlayingSoundList.erase(
			std::remove(PlayingSoundList.begin(), PlayingSoundList.end(), soundId));
	}

	void StopAllSounds() override
	{
		PlayingSoundList.clear();
	}

private:
	std::vector<int> PlayingSoundList;
};