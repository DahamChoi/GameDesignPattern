#include "Player.h"
#include "UI.h"

int main()
{
	OPlayer Player;
	OUI UI(&Player);

	std::cout << UI;

	Player.AddDelegateFunction([&]() {
		std::cout << UI;
	});

	Player.Hit(-1);
	Player.Hit(-3);
	Player.Hit(-2);
}