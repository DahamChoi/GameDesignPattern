#pragma once

#include <queue>
#include <iostream>

class Audio
{
private:
	static Audio* Instance;

public:
	static Audio* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Audio();

		return Instance;
	}

public:
	void PlaySound(int soundId, int volume)
	{
		SoundQueue.push(PlayMessage{ soundId, volume });
	}

	void Update()
	{
		PlayMessage max{ 0, 0 };
		while (!SoundQueue.empty())
		{
			PlayMessage p = SoundQueue.front();
			if (p.Volume > max.Volume)
			{
				max.Volume = p.Volume;
				max.SoundId = p.SoundId;
			}
			SoundQueue.pop();
		}

		StartSound(max.SoundId, max.Volume);
	}

private:
	class PlayMessage
	{
	public:
		int SoundId;
		int Volume;
	};

	std::queue<PlayMessage> SoundQueue;

	void StartSound(int soundId, int volume)
	{
		std::cout << "SOUND : " << soundId << " - " << volume << std::endl;
	}
};

Audio* Audio::Instance = nullptr;