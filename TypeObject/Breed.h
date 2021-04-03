#pragma once

#include <string>

class Breed
{
public:
	Breed(Breed* parent, int health, const std::string& attackString)
		: Parent{ parent }, Health{ health }, AttackString{ attackString } {}

	int GetHealth() const
	{
		if (Health != 0)
			return Health;

		return (Parent == nullptr) ? Health : Parent->GetHealth();
	}

	const std::string& GetAttackString() const
	{
		if (AttackString != "")
			return AttackString;

		return (Parent == nullptr) ? AttackString : Parent->GetAttackString();
	}

private:
	Breed* Parent;
	int Health;
	std::string AttackString;
};