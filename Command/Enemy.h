#pragma once

#include <iostream>

#include "Actor.h"

class Enemy : public Actor
{
private:
	int typeId;

public:
	Enemy(const int typeId) : typeId{ typeId } {}

	void Jump() override
	{
		Actor::Jump();
		std::cout << "Enemy : " << typeId << " JUMP!" << std::endl;
	}

	void FireGun()
	{
		Actor::FireGun();
		std::cout << "Enemy : " << typeId << " FIREGUN!" << std::endl;
	}

	void Launcher()
	{
		Actor::Launcher();
		std::cout << "Enemy : " << typeId << " LAUNCHER!" << std::endl;
	}

	void SwapWeapon()
	{
		Actor::SwapWeapon();
		std::cout << "Enemy : " << typeId << " SWAP WEAPON!" << std::endl;
	}
};