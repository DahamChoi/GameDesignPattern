#include "GameObject.h"
#include "ConsoleAudio.h"

int main()
{
	GameObject obj;
	obj.Action();
	obj.SetAudioService(new ConsoleAudio());
	obj.Action();
}