#pragma once

class Transform
{
public:
	explicit Transform(float value)
		: Value{ value } {}

	Transform combine(Transform& other)
	{
		return Transform{ other.Value * Value };
	}

private:
	float Value;
};