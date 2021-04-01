#pragma once

#include <iostream>

#include "Actor.h"

class Player : public Actor
{
private:
	std::string name;

public:
	Player(const std::string& name) : name{ name } {}

	void Jump() override
	{
		Actor::Jump();
		std::cout << "PLAYER : " << name << " JUMP!" << std::endl;
	}

	void FireGun()
	{
		Actor::FireGun();
		std::cout << "PLAYER : " << name << " FIREGUN!" << std::endl;
	}

	void Launcher()
	{
		Actor::Launcher();
		std::cout << "PLAYER : " << name << " LAUNCHER!" << std::endl;
	}

	void SwapWeapon()
	{
		Actor::SwapWeapon();
		std::cout << "PLAYER : " << name << " SWAP WEAPON!" << std::endl;
	}
};