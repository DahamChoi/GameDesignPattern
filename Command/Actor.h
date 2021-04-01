#pragma once

#include "InputMemento.h"

#include <vector>
#include <memory>

class Actor
{
protected:
	bool isJump{ false };
	bool isFireGun{ false };
	bool isLauncher{ false };
	bool isSwapWeapon{ false };

private:
	int current{ 0 };
	std::vector<std::shared_ptr<InputMemento>> changes;

public:
	Actor()
	{
		changes.push_back(std::make_shared<InputMemento>(
			isJump, isFireGun, isLauncher, isSwapWeapon));
	}

	virtual void Jump() 
	{
		isJump = true;
		changes.push_back(std::make_shared<InputMemento>(
			isJump, isFireGun, isLauncher, isSwapWeapon));
		++current;
	}

	virtual void FireGun()
	{
		isFireGun = true;
		changes.push_back(std::make_shared<InputMemento>(
			isJump, isFireGun, isLauncher, isSwapWeapon));
		++current;
	}

	virtual void Launcher()
	{
		isLauncher = true;
		changes.push_back(std::make_shared<InputMemento>(
			isJump, isFireGun, isLauncher, isSwapWeapon));
		++current;
	}

	virtual void SwapWeapon()
	{
		isSwapWeapon = true;
		changes.push_back(std::make_shared<InputMemento>(
			isJump, isFireGun, isLauncher, isSwapWeapon));
		++current;
	}

	void undo()
	{
		if (current > 0)
		{
			--current;
			auto m = changes[current];
			isJump = m->isJump;
			isFireGun = m->isFireGun;
			isLauncher = m->isLauncher;
			isSwapWeapon = m->isSwapWeapon;
		}
	}

	void redo()
	{
		if (current + 1 < changes.size())
		{
			++current;
			auto m = changes[current];
			isJump = m->isJump;
			isFireGun = m->isFireGun;
			isLauncher = m->isLauncher;
			isSwapWeapon = m->isSwapWeapon;
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const Actor& obj)
	{
		os << "IS JUMP : " << obj.isJump << std::endl;
		os << "IS FIREGUN : " << obj.isFireGun << std::endl;
		os << "IS LAUNCHER : " << obj.isLauncher << std::endl;
		os << "IS SWAP WEAPON : " << obj.isSwapWeapon << std::endl;
		return os;
	}
};