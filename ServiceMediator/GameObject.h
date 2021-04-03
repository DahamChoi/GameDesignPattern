#pragma once

#include "Audio.h"
#include "NullAudio.h"

class GameObject
{
public:
	static void SetAudioService(Audio* service)
	{
		delete AudioService;
		AudioService = service;
	}

	void Action()
	{
		AudioService->PlaySound(0);
		AudioService->StopSound(0);
		AudioService->StopAllSounds();
	}

private:
	static Audio* AudioService;
};

Audio* GameObject::AudioService = new NullAudio();