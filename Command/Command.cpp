#include <iostream>

#include "InputHandler.h"
#include "Player.h"
#include "Enemy.h"

int main()
{
	InputHandler ih;
	Player* player = new Player{"최다함"};
	Enemy* enemy = new Enemy(10);

	std::cout << *player << std::endl;
	ih.HandleInput(InputHandler::BUTTON::BUTTON_A, player);
	std::cout << *player << std::endl;
	player->undo();
	std::cout << *player << std::endl;

	std::cout << "ENEMY!" << std::endl;
	std::cout << *enemy << std::endl;
	ih.HandleInput(InputHandler::BUTTON::BUTTON_X, enemy);
	std::cout << *enemy << std::endl;
	enemy->undo();
	std::cout << *enemy << std::endl;
	enemy->redo();
	std::cout << *enemy << std::endl;
}