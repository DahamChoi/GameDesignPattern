#pragma once

#include "Comedian.h"
#include <vector>
#include <iostream>

class Stage
{
public:
	~Stage()
	{
		for (auto actor : ActorList)
			delete actor;
	}

	void Add(Comedian* actor)
	{
		ActorList.push_back(actor);
	}

	void Update()
	{
		for (auto actor : ActorList)
		{
			actor->Update();
		}

		for (auto actor : ActorList)
		{
			actor->Swap();
			std::cout << *actor << std::endl;
		}
	}

private:
	std::vector<Comedian*> ActorList;
};