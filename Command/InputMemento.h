#pragma once

class InputMemento
{
private:
	bool isJump;
	bool isFireGun;
	bool isLauncher;
	bool isSwapWeapon;

public:
	InputMemento(bool isJump, bool isFireGun, bool isLauncher, bool isSwapWeapon)
		: isJump{ isJump }, isFireGun{ isFireGun }, isLauncher{ isLauncher }, isSwapWeapon{ isSwapWeapon } {}

	friend class Actor;
};