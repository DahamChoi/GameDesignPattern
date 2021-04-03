#pragma once

#include "AudioComponent.h"
#include "ParticleComponent.h"

class SuperPower
{
public:
	SuperPower() : Audio{ new AudioComponent() }, Particle{ new ParticleComponent() } {}
	~SuperPower()
	{
		delete Audio;
		delete Particle;
	}

	virtual void activate() = 0;

protected:
	AudioComponent* Audio;
	ParticleComponent* Particle;
	float PosX{ 0.f }, PosY{ 0.f };

	void Move(float x, float y)
	{
		PosX = x;
		PosY = y;
	}

	float GetX() const
	{
		return PosX;
	}

	float GetY() const
	{
		return PosY;
	}
};