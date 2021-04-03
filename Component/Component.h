#pragma once

#include "GameObject.h"

class Component
{
private:
	GameObject* Object;

public:
	Component(GameObject* object)
		: Object{ object } {}

	void Send(int message) 
	{
		Object->Send(message);
	}

	virtual void Receive(int message) {}

	virtual void Update() = 0;
};