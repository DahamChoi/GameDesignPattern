#include <iostream>

#include "Monster.h"

int main()
{
	Monster* m = Monster::create()->
		setDefaultHp(100)->
		setName("Dragon")->
		build();
	
	std::cout << *m << std::endl;
}