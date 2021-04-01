#pragma once

#include "Actor.h"

class Command
{
public:
	virtual void Excute(Actor* actor) = 0;
};

class JumpCommand : public Command
{
public:
	void Excute(Actor* actor) override
	{
		actor->Jump();
	}
};

class FireGunCommand : public Command
{
public:
	void Excute(Actor* actor) override
	{
		actor->FireGun();
	}
};

class LauncherCommand : public Command
{
public:
	void Excute(Actor* actor) override
	{
		actor->Launcher();
	}
};

class SwapWeaponCommand : public Command
{
public:
	void Excute(Actor* actor) override
	{
		actor->SwapWeapon();
	}
};