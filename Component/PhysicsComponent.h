#pragma once

#include "Component.h"

class PhysicsComponent : public Component
{
public:
	PhysicsComponent(GameObject* object)
		: Component{ object } {}
};