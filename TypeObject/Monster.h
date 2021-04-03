#pragma once

#include "Breed.h"

#include <iostream>

class Monster
{
public:
	Monster(Breed& breed)
		: Health{ breed.GetHealth() }, TypeBreed{ breed } {}

	void Attack()
	{
		std::cout << TypeBreed.GetAttackString() << std::endl;
	}

private:
	int Health;
	Breed& TypeBreed;
};