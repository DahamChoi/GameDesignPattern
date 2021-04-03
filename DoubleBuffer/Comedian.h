#pragma once

#include <string>
#include <ostream>

class Comedian
{
public:
	explicit Comedian(const std::string& name)
		: Name{ name } {}

	void Face(Comedian* actor)
	{
		Facing = actor;
	}

	void Swap()
	{
		CurrentSlapped = NextSlapped;
		NextSlapped = false;
	}

	void Update()
	{
		if (CurrentSlapped)
			Facing->Slap();
	}

	void Reset()
	{
		NextSlapped = false;
	}

	void Slap()
	{
		NextSlapped = true;
	}

	friend std::ostream& operator<<(std::ostream& os, const Comedian& obj)
	{
		os << obj.Name << "Slapped State Is " << obj.CurrentSlapped << std::endl;
		return os;
	}

private:
	std::string Name;
	bool CurrentSlapped{ false };
	bool NextSlapped{ false };

	Comedian* Facing{ nullptr };
};