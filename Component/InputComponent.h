#pragma once

#include "Component.h"

class InputComponent : public Component
{
public:
	InputComponent(GameObject* object)
		: Component{ object } {}
};