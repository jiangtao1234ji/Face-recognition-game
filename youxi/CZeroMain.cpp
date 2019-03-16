#include"CZerolib.h"


int main(int argc, char *argv[]) {

	Zero_InitializationWindow();
	SDL_Thread* FFF;
	//FFF = SDL_CreateThread(FaceThread, "Face",NULL);
	
	Zero_GameLoad();
	ChangeCharacter = SDL_AddTimer(180, CallBack1, NULL);
	ChangeJN = SDL_AddTimer(150, CallJN, NULL);
	while (!Zero_GameQuit) {
		Zero_GameEvent();
		Zero_GameDraw();
		
	}
	return 0;
}