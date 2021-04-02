#pragma once

#include <string>
#include <vector>
#include <ostream>

class Monster
{
private:
	class MonsterFactory
	{
	public:
		explicit MonsterFactory(Monster* monster) : monster{ monster } {}

		Monster* build()
		{
			return monster;
		}

		MonsterFactory* setDefaultHp(int defaultHp)
		{
			monster->DefaultHp = defaultHp;
			return this;
		}

		MonsterFactory* setMaxHp(int maxHp)
		{
			monster->MaxHp = maxHp;
			return this;
		}

		MonsterFactory* setName(const std::string& name)
		{
			monster->Name = name;
			return this;
		}

		MonsterFactory* setWeak(const std::vector<std::string>& weakList)
		{
			monster->WeakList = weakList;
			return this;
		}

		MonsterFactory* setMagic(const std::vector<std::string>& magicList)
		{
			monster->MagicList = magicList;
			return this;
		}

	private:
		Monster* monster;
	};

private:
	Monster(int defaultHp, int maxHp, const std::string& name,
		const std::vector<std::string>& weakList, const std::vector<std::string>& magicList)
		: DefaultHp{ defaultHp }, MaxHp{ maxHp }, Name{ name }, WeakList{ weakList }, MagicList{ magicList } {}

	int DefaultHp;
	int MaxHp;
	std::string Name;
	std::vector<std::string> WeakList;
	std::vector<std::string> MagicList;

public:
	static MonsterFactory* create()
	{
		static Monster proto{ 20, 30, "Goblin", {"Cold","Posion"}, {"FireBall","ThunderBolt"} };
		return new MonsterFactory{ new Monster(proto.DefaultHp, proto.MaxHp, proto.Name, proto.WeakList, proto.MagicList) };
	}

	friend std::ostream& operator<<(std::ostream& os, const Monster& obj)
	{
		os << "------------------------------------------" << std::endl;
		os << "NAME : " << obj.Name << std::endl;
		os << "DefaultHp : " << obj.DefaultHp << std::endl;
		os << "MaxHp : " << obj.MaxHp << std::endl;

		for(size_t i = 0; i < obj.WeakList.size(); i++)
			os << "WeakList : " << obj.WeakList[i] << std::endl;
		
		for(size_t i = 0; i < obj.MagicList.size(); i++)
			os << "MagicList : " << obj.MagicList[i] << std::endl;
		
		os << "------------------------------------------" << std::endl;
		
		return os;
	}
};