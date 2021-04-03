#pragma once

#include "State.h"

#include <vector>
#include <functional>
#include <map>
#include <iostream>

class StateMachine
{
public:
	class Idle : public State 
	{
		void OnEntry() override
		{
			std::cout << "IDLE STATE ENTRY" << std::endl;
		}

		void OnExit() override
		{
			std::cout << "IDLE STATE EXIT" << std::endl;
		}
	};
	
	class Run : public State 
	{
		void OnEntry() override
		{
			std::cout << "RUN STATE ENTRY" << std::endl;
		}

		void OnExit() override
		{
			std::cout << "RUN STATE EXIT" << std::endl;
		}
	};
	
	class Jump : public State 
	{
		void OnEntry() override
		{
			std::cout << "JUMP STATE ENTRY" << std::endl;
		}

		void OnExit() override
		{
			std::cout << "JUMP STATE EXIT" << std::endl;
		}
	};
	
	class Slide : public State 
	{
		void OnEntry() override
		{
			std::cout << "SLIDE STATE ENTRY" << std::endl;
		}

		void OnExit() override
		{
			std::cout << "SLIDE STATE EXIT" << std::endl;
		}
	};

	enum class STATE_ENUM{ IDLE, RUN, JUMP, SLIDE };

	explicit StateMachine()
	{
		StateMap[0].push_back(
			std::make_pair(STATE_ENUM::RUN, [&]() { 
				return Speed >= 10.f;
				})
		);

		StateMap[0].push_back(
			std::make_pair(STATE_ENUM::JUMP, [&]() {
				return IsJumpButtonDown;
				})
		);

		StateMap[1].push_back(
			std::make_pair(STATE_ENUM::IDLE, [&]() {
				return Speed <= 1.f;
				})
		);

		StateMap[1].push_back(
			std::make_pair(STATE_ENUM::JUMP, [&]() {
				return IsJumpButtonDown;
				})
		);

		StateMap[1].push_back(
			std::make_pair(STATE_ENUM::SLIDE, [&]() {
				return IsSlideButtonDown;
				})
		);

		StateMap[2].push_back(
			std::make_pair(STATE_ENUM::IDLE, [&]() {
				return !IsJumpButtonDown;
				})
		);

		StateMap[3].push_back(
			std::make_pair(STATE_ENUM::IDLE, [&]() {
				return !IsSlideButtonDown;
				})
		);
	}

	~StateMachine()
	{
		for (int i = 0; i < StateList.size(); i++)
			delete StateList[i];
	}

	// Observer 혹은 UpdateMethod로 처리
	void PlayerAction(float speed, bool isJumpButtonDown, bool isSlideButtonDown)
	{
		Speed = speed;
		IsJumpButtonDown = isJumpButtonDown;
		IsSlideButtonDown = isSlideButtonDown;
	}

	void Update()
	{
		for (int i = 0; i < StateMap[StateIndex].size(); i++)
		{
			if (StateMap[StateIndex][i].second()){
				StateList[StateIndex]->OnExit();
				StateIndex = (int)StateMap[StateIndex][i].first;
				StateList[StateIndex]->OnEntry();
				break;
			}
		}
	}

private:
	int StateIndex{ 0 };
	std::vector<std::vector<std::pair<STATE_ENUM, std::function<bool()>>>> StateMap{ 4 };
	std::vector<State*> StateList{ new Idle(), new Run(), new Jump(), new Slide() };

	float Speed{ 0.f };
	bool IsJumpButtonDown{ false };
	bool IsSlideButtonDown{ false };
};