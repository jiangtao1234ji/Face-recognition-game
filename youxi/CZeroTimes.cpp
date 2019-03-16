#include"CZerolib.h"


SDL_TimerID ChangeCharacter=NULL;
SDL_TimerID ChangeJN=NULL;
SDL_TimerID Jump1 = NULL;
SDL_TimerID Face = NULL;

Uint32 CallBack1(Uint32 interval,void *param) {
	/*
	Character1.Action.at(Character1.Status).PresentNumber = 
		(Character1.Action.at(Character1.Status).PresentNumber + 1)
		% Character1.Action.at(Character1.Status).MaxNumber;
	std::cout << Character1.Action.at(Character1.Status).PresentNumber << std::endl;
	*/
	
	//Character1
	if(Character1.Status == 0) {
		Character1.WaitLeft.PresentNumber = (Character1.WaitLeft.PresentNumber + 1) % Character1.WaitLeft.MaxNumber;
	}
	else if (Character1.Status == 1) {
		Character1.WaitRight.PresentNumber = (Character1.WaitRight.PresentNumber + 1) % Character1.WaitRight.MaxNumber;  
	}

	else if (Character1.Status == 4) {
		Character1.AttactLeft.PresentNumber = Character1.AttactLeft.PresentNumber + 1;
	}
	else if (Character1.Status == 5) {
		Character1.AttactRight.PresentNumber = Character1.AttactRight.PresentNumber + 1;
	}
	else if (Character1.Status == 6) {
		Character1.HitRecoverLeft.PresentNumber = (Character1.HitRecoverLeft.PresentNumber + 1) % Character1.HitRecoverLeft.MaxNumber;
	}
	else if (Character1.Status == 7) {
		Character1.HitRecoverRight.PresentNumber = (Character1.HitRecoverRight.PresentNumber + 1) % Character1.HitRecoverRight.MaxNumber;
	}
	//Character2
	if (Character2.Status == 0) {
		Character2.WaitLeft.PresentNumber = (Character2.WaitLeft.PresentNumber + 1) % Character2.WaitLeft.MaxNumber;
	}
	else if (Character2.Status == 1) {
		Character2.WaitRight.PresentNumber = (Character2.WaitRight.PresentNumber + 1) % Character2.WaitRight.MaxNumber;
	}

	else if (Character2.Status == 4) {
		Character2.AttactLeft.PresentNumber = Character2.AttactLeft.PresentNumber + 1;
	}
	else if (Character2.Status == 5) {
		Character2.AttactRight.PresentNumber = Character2.AttactRight.PresentNumber + 1;
	}
	else if (Character2.Status == 6) {
		Character2.HitRecoverLeft.PresentNumber = Character2.HitRecoverLeft.PresentNumber + 1;
	}
	else if (Character2.Status == 7) {
		Character2.HitRecoverRight.PresentNumber = Character2.HitRecoverRight.PresentNumber + 1;
	}
	return(interval);
}

Uint32 MoveLeft1(Uint32 interval, void *param) {
	Character1.Status = 2;
	Character1.MoveLeft.PresentNumber = (Character1.MoveLeft.PresentNumber + 1) % Character1.MoveLeft.MaxNumber;
	Character1.Position.x -= Character1.Speed;
	return interval;
}
Uint32 MoveRight1(Uint32 interval, void *param) {
	Character1.Status = 3;
	Character1.MoveRight.PresentNumber = (Character1.MoveRight.PresentNumber + 1) % Character1.MoveRight.MaxNumber;
	Character1.Position.x += Character1.Speed;
	return interval;
}

Uint32 MoveLeft2(Uint32 interval, void *param) {
	Character2.Status = 2;
	Character2.MoveLeft.PresentNumber = (Character2.MoveLeft.PresentNumber + 1) % Character2.MoveLeft.MaxNumber;
	Character2.Position.x -= Character2.Speed;
	return interval;
}
Uint32 MoveRight2(Uint32 interval, void *param) {
	Character2.Status = 3;
	Character2.MoveRight.PresentNumber = (Character2.MoveRight.PresentNumber + 1) % Character2.MoveRight.MaxNumber;
	Character2.Position.x += Character2.Speed;
	return interval;
}

Uint32 CallJN(Uint32 interval, void *param) {
	for (int i = 0; i < Zero_JNVectorLeft.size(); ++i) {
		Zero_JNVectorLeft.at(i).PresentNumber++;
		Zero_JNVectorLeft.at(i).Position.x += Zero_JNVectorLeft.at(i).Speed;
	}
	for (int i = 0; i < Zero_JNVectorRight.size(); ++i) {
		Zero_JNVectorRight.at(i).PresentNumber++;
		Zero_JNVectorRight.at(i).Position.x += Zero_JNVectorRight.at(i).Speed;
	}


	for (int i = 0; i < CollisionVector1.size(); ++i) {
		if (Character1.Status % 2 == 0) {
			if (Zero_IsCollision(CollisionVector1.at(i).Position, Character2.Position)) {
				Character2.Status = 7;
				CollisionVector1.erase(CollisionVector1.begin() + i);
				i--;
			}
		}
		else {
			if (Zero_IsCollision(CollisionVector1.at(i).Position, Character2.Position)) {
				Character2.Status = 6;
				CollisionVector1.erase(CollisionVector1.begin() + i);
				i--;
			}
		}
		

	}
	return interval;
}


Uint32 CallJump1(Uint32 interval, void *param) {
	static int times = 0;
	if (times < 20 && times >= 0) {
		Character1.Position.y -= 10;
		times++;
	}

	else {
		Character1.Position.y += 10;
		times++;
	}

	if (times == 40) {
			SDL_RemoveTimer(Jump1);
			Jump1 = NULL;
			times = 0;
	}
	return interval;
}
//Uint32 CallFace(Uint32 interval, void *param) {
	
//}