#include "Monster.h"

int main()
{
	Breed Troll(nullptr, 25, "Troll Attack You!");
	Breed ArcherTroll(&Troll, 0, "Troll Shoot a Bow!");
	Breed MageTroll(&Troll, 0, "Troll Magic Attack!");

	Monster m1(Troll);
	Monster m2(ArcherTroll);
	Monster m3(MageTroll);

	m1.Attack();
	m2.Attack();
	m3.Attack();
}