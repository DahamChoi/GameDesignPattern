#pragma once

#include <iostream>

class AudioComponent
{
public:
	void SetVolume(float value) 
	{
		Volume = value;
	}

	void PlaySound()
	{
		std::cout << "PLAY AUDIO!" << std::endl;
	}

	void StopSound()
	{
		std::cout << "STOP AUDIO!" << std::endl;
	}

private:
	float Volume;
};