#include"CZerolib.h"

void Zero_GameDraw() {
	SDL_RenderClear(GameRenderer);
	Zero_DrawMap();
	Zero_DrawBuff();
	Zero_DrawCharacter1();
	Zero_DrawCharacter2();
	Zero_DrawJN();
	SDL_RenderPresent(GameRenderer);
}

void Zero_DrawMap() {
	SDL_RenderCopy(GameRenderer, GameMap.Texture, NULL,NULL);
}

void Zero_DrawCharacter1() {
//	std::cout << Character1.Status << std::endl;
	if (Character1.Status == 0) {
		SDL_RenderCopy(GameRenderer, Character1.WaitLeft.Frame.at(Character1.WaitLeft.PresentNumber).Texture, NULL, &Character1.Position);
	}
	else if (Character1.Status == 1) {
		SDL_RenderCopy(GameRenderer, Character1.WaitRight.Frame.at(Character1.WaitRight.PresentNumber).Texture, NULL, &Character1.Position);
	}
	else if (Character1.Status == 2) {
		SDL_RenderCopy(GameRenderer, Character1.MoveLeft.Frame.at(Character1.MoveLeft.PresentNumber).Texture, NULL, &Character1.Position);
	}
	else if (Character1.Status == 3) {
		SDL_RenderCopy(GameRenderer, Character1.MoveRight.Frame.at(Character1.MoveRight.PresentNumber).Texture, NULL, &Character1.Position);
	}
	else if (Character1.Status == 4) {
		SDL_RenderCopy(GameRenderer, Character1.AttactLeft.Frame.at(Character1.AttactLeft.PresentNumber).Texture, NULL, &Character1.Position);
		if (Character1.AttactLeft.PresentNumber == 4) {
			Character1.AttactLeft.PresentNumber = 0;
			Character1.Status = 0;
		}
	}
	else if (Character1.Status == 5) {
		SDL_RenderCopy(GameRenderer, Character1.AttactRight.Frame.at(Character1.AttactRight.PresentNumber).Texture, NULL, &Character1.Position);
		if (Character1.AttactRight.PresentNumber == 4) {
			Character1.AttactRight.PresentNumber = 0;
			Character1.Status = 1;
		}
	}
	else if (Character1.Status == 6) {
		SDL_RenderCopy(GameRenderer, Character1.HitRecoverLeft.Frame.at(Character1.HitRecoverLeft.PresentNumber).Texture, NULL, &Character1.Position);
	}
	else if (Character1.Status == 7) {
		SDL_RenderCopy(GameRenderer, Character1.HitRecoverRight.Frame.at(Character1.HitRecoverRight.PresentNumber).Texture, NULL, &Character1.Position);
	}
}
void Zero_DrawCharacter2() {
	//	std::cout << Character2.Status << std::endl;
	if (Character2.Status == 0) {
		SDL_RenderCopy(GameRenderer, Character2.WaitLeft.Frame.at(Character2.WaitLeft.PresentNumber).Texture, NULL, &Character2.Position);
	}
	else if (Character2.Status == 1) {
		SDL_RenderCopy(GameRenderer, Character2.WaitRight.Frame.at(Character2.WaitRight.PresentNumber).Texture, NULL, &Character2.Position);
	}
	else if (Character2.Status == 2) {
		SDL_RenderCopy(GameRenderer, Character2.MoveLeft.Frame.at(Character2.MoveLeft.PresentNumber).Texture, NULL, &Character2.Position);
	}
	else if (Character2.Status == 3) {
		SDL_RenderCopy(GameRenderer, Character2.MoveRight.Frame.at(Character2.MoveRight.PresentNumber).Texture, NULL, &Character2.Position);
	}
	else if (Character2.Status == 4) {
		SDL_RenderCopy(GameRenderer, Character2.AttactLeft.Frame.at(Character2.AttactLeft.PresentNumber).Texture, NULL, &Character2.Position);
		if (Character2.AttactLeft.PresentNumber == 4) {
			Character2.AttactLeft.PresentNumber = 0;
			Character2.Status = 0;
		}
	}
	else if (Character2.Status == 5) {
		SDL_RenderCopy(GameRenderer, Character2.AttactRight.Frame.at(Character2.AttactRight.PresentNumber).Texture, NULL, &Character2.Position);
		if (Character2.AttactRight.PresentNumber == 4) {
			Character2.AttactRight.PresentNumber = 0;
			Character2.Status = 1;
		}
	}
	else if (Character2.Status == 6) {
		SDL_RenderCopy(GameRenderer, Character2.HitRecoverLeft.Frame.at(Character2.HitRecoverLeft.PresentNumber).Texture, NULL, &Character2.Position);
		if (Character2.HitRecoverLeft.PresentNumber == 3) {
			Character2.HitRecoverLeft.PresentNumber = 0;
			Character2.Status = 0;
		}
	}
	else if (Character2.Status == 7) {
		SDL_RenderCopy(GameRenderer, Character2.HitRecoverRight.Frame.at(Character2.HitRecoverRight.PresentNumber).Texture, NULL, &Character2.Position);
		if (Character2.HitRecoverRight.PresentNumber == 3) {
			Character2.HitRecoverRight.PresentNumber = 0;
			Character2.Status = 1;
		}
	}
}

void Zero_DrawJN() {
	for (int i = 0; i < Zero_JNVectorLeft.size(); ++i) {
		SDL_RenderCopy(GameRenderer, Zero_JNVectorLeft.at(i).Left.Frame.at(Zero_JNVectorLeft.at(i).PresentNumber%Zero_JNVectorLeft.at(i).Number).Texture, NULL, &Zero_JNVectorLeft.at(i).Position);
		if (Zero_JNVectorLeft.at(i).PresentNumber == Zero_JNVectorLeft.at(i).MaxNumber - 1) {
			Zero_JNVectorLeft.erase(Zero_JNVectorLeft.begin()+i);
			i--;
		}
	}
	for (int i = 0; i < Zero_JNVectorRight.size(); ++i) {
		SDL_RenderCopy(GameRenderer, Zero_JNVectorRight.at(i).Right.Frame.at(Zero_JNVectorRight.at(i).PresentNumber%Zero_JNVectorRight.at(i).Number).Texture, NULL, &Zero_JNVectorRight.at(i).Position);
		if (Zero_JNVectorRight.at(i).PresentNumber == Zero_JNVectorRight.at(i).MaxNumber - 1) {
			Zero_JNVectorRight.erase(Zero_JNVectorRight.begin() + i);
			i--;
		}
	}
}

void Zero_DrawBuff() {
	if (Character1.Status % 2 == 1) {
		Buff11.Position.x = Character1.Position.x + 120;
		Buff11.Position.y = Character1.Position.y + 232;
		SDL_RenderCopy(GameRenderer, Buff11.Texture, NULL, &Buff11.Position);
	}
	else {
		Buff11.Position.x = Character1.Position.x + 212;
		Buff11.Position.y = Character1.Position.y + 232;
		SDL_RenderCopy(GameRenderer, Buff11.Texture, NULL, &Buff11.Position);
	}
}