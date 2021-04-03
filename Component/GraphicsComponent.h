#pragma once

#include "Component.h"

class GraphicsComponent : public Component
{
public:
	GraphicsComponent(GameObject* object)
		: Component{ object } {}
};