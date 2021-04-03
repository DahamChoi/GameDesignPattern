#pragma once

#include "Component.h"
#include "GraphicsComponent.h"

#include <vector>

class GameObject
{
public:
	virtual void Update()
	{
		for (auto component : ComponentList)
			component->Update();
	}

	void Send(int message)
	{
		for (auto component : ComponentList)
			component->Receive(message);
	}

protected:
	int PosX{ 0.f }, PosY{ 0.f };
	std::vector<Component*> ComponentList;
};