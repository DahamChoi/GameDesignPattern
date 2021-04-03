#pragma once

#include "Particle.h"

#include <vector>
#include <list>

class ParticlePool
{
public:
	void Create(float x, float y, float xVel, float yVel, int lifeTime)
	{
		ParticleList[CurrentParitlceListPos].Init(x, y, xVel, yVel, lifeTime);
		EnableParticleList.push_back(&ParticleList[CurrentParitlceListPos]);
		CurrentParitlceListPos = CurrentParitlceListPos + 1 >= 100 ? 0 : CurrentParitlceListPos + 1;
	}

	void Animation()
	{
		auto it = EnableParticleList.begin();
		while (it != EnableParticleList.end())
		{
			(*it)->Animation();
			if (!(*it)->IsUse())
				EnableParticleList.erase(it++);
			else
				it++;
		}
	}

private:
	std::vector<Particle> ParticleList{ 100 };
	int CurrentParitlceListPos{ 0 };
	std::list<Particle*> EnableParticleList;
};