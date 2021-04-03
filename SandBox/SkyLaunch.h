#pragma once

#include "SuperPower.h"

class SkyLauncher : public SuperPower
{
public:
	void activate()
	{
		Audio->SetVolume(10.f);
		Audio->PlaySound();
		Particle->SpawnParticle();

		std::cout << "ACTIVE!" << std::endl;
	}
};