#pragma once

class Particle
{
public:
	void Init(float x, float y, float xVel, float yVel, int lifeTime)
	{
		X = x;
		Y = y;
		XVel = xVel;
		YVel = yVel;
		FrameLeft = lifeTime;
	}

	void Animation()
	{
		--FrameLeft;
		X += XVel;
		Y += YVel;
	}

	bool IsUse() const
	{
		return (FrameLeft > 0);
	}

private:
	int FrameLeft;
	double X, Y;
	double XVel, YVel;
};