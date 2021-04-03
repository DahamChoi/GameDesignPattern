#include "Audio.h"

int main()
{
	Audio::GetInstance()->PlaySound(0, 2);
	Audio::GetInstance()->PlaySound(1, 5);
	Audio::GetInstance()->PlaySound(2, 4);
	Audio::GetInstance()->PlaySound(3, 9);
	Audio::GetInstance()->PlaySound(4, 10);

	Audio::GetInstance()->Update();
}