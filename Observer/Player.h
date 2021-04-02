#pragma once

#include <functional>

class OPlayer
{
public:
	OPlayer() {}

	void Hit(int damage)
	{
		HP += damage;
		DELEGATER();
	}

	void AddDelegateFunction(std::function<void()> Func)
	{
		DELEGATER = Func;
	}

	static const int MAX_HP{ 10 };
	int HP{ MAX_HP };

private:
	std::function<void()> DELEGATER;
};