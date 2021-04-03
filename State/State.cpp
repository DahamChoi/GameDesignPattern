#include "StateMachine.h"

int main()
{
	StateMachine stateMachine;

	stateMachine.Update();
	stateMachine.PlayerAction(10.f, false, false);
	stateMachine.Update();
	stateMachine.PlayerAction(10.f, true, false);
	stateMachine.Update();
	stateMachine.PlayerAction(10.f, true, true);
	stateMachine.Update();
}