#pragma once

#include "Actor.h"
#include "Command.h"
#include "InputMemento.h"

class InputHandler
{
public:
	enum class BUTTON
	{
		BUTTON_X,
		BUTTON_Y,
		BUTTON_A,
		BUTTON_B
	};

	Command* xCommand{ new JumpCommand() };
	Command* yCommand{ new FireGunCommand() };
	Command* aCommand{ new LauncherCommand() };
	Command* bCommand{ new SwapWeaponCommand() };
	
	void HandleInput(BUTTON input, Actor* actor)
	{
		if (input == BUTTON::BUTTON_X)
		{
			xCommand->Excute(actor);
		}
		else if (input == BUTTON::BUTTON_Y)
		{
			yCommand->Excute(actor);
		}
		else if (input == BUTTON::BUTTON_A)
		{
			aCommand->Excute(actor);
		}
		else if (input == BUTTON::BUTTON_B)
		{
			bCommand->Excute(actor);
		}
	}
};