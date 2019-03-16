#include"CZerolib.h"

void Zero_GameEvent() {
	if (SDL_PollEvent(&Zero_Event)) {
		if (Zero_Event.type == SDL_QUIT) {
			Zero_GameQuit = true;
		}

		if (Zero_Event.type == SDL_KEYDOWN) {
		//	if (Zero_Event.type == SDLK_F1)
		//		FaceStatus1 = 0;
		//	else if (Zero_Event.type == SDLK_F1) 

			//A
			if (Zero_Event.key.keysym.sym == SDLK_a) {
				if (Character1.TimerMoveLeft == NULL) {
					Character1.Status = 2;
					Character1.MoveLeft.PresentNumber = 0;
					Character1.TimerMoveLeft = SDL_AddTimer(200, MoveLeft1, NULL);
				}
			}
			//D
			else if (Zero_Event.key.keysym.sym == SDLK_d) {
				if (Character1.TimerMoveRight == NULL) {
					Character1.Status = 3;
					Character1.MoveRight.PresentNumber = 0;
					Character1.TimerMoveRight = SDL_AddTimer(200, MoveRight1, NULL);
				 }
			}

			//W
			else if (Zero_Event.key.keysym.sym == SDLK_w) {
				if (Jump1 == NULL) {
					Jump1 = SDL_AddTimer(30, CallJump1, NULL);
				}
			}

			//J
			else if (Zero_Event.key.keysym.sym == SDLK_j) {
				if (Character1.Status == 0 || Character1.Status == 2) {
					Zero_Collision a;
					a.ID = 1;
					a.MaxNumber = Character1.AttactLeft.MaxNumber;
					a.PresentNumber = 0;
					a.Position.x = Character1.Position.x;
					a.Position.y = Character1.Position.y;
					a.Position.w = Character1.Position.w/2;
					a.Position.h = Character1.Position.h;
					CollisionVector1.push_back(a);
					Character1.Status = 4;
				}
				else if (Character1.Status == 1 || Character1.Status == 3) {
					Zero_Collision a;
					a.ID = 1;
					a.MaxNumber = Character1.AttactRight.MaxNumber;
					a.PresentNumber = 0;
					a.Position.x = Character1.Position.x+ Character1.Position.w / 2;
					a.Position.y = Character1.Position.y;
					a.Position.w = Character1.Position.w / 2;
					a.Position.h = Character1.Position.h;
					CollisionVector1.push_back(a);
					Character1.Status = 5;
				}
				
			}

			//K
			else if (Zero_Event.key.keysym.sym == SDLK_k) {
				if (Character1.Status % 2 == 1) {
					JN1.Position.x = Character1.Position.x + 300;
					JN1.Position.y = Character1.Position.y + abs(Character1.Position.h - JN1.Position.h)-20;
					JN1.Speed = 30;
					Zero_JNVectorRight.push_back(JN1);
				}
				else {
					JN1.Position.x = Character1.Position.x +30;
					JN1.Position.y = Character1.Position.y + abs(Character1.Position.h - JN1.Position.h)-20;
					JN1.Speed = -30;
					Zero_JNVectorLeft.push_back(JN1);
				}
			}

			//I
			else if (Zero_Event.key.keysym.sym == SDLK_i) {
				if (Character1.Status % 2 == 1) {
					JN3.Position.x = Character1.Position.x + 400;
					JN3.Position.y = Character1.Position.y - 200;
					Zero_JNVectorRight.push_back(JN3);
				}
				else {
					JN3.Position.x = Character1.Position.x - 800;
					JN3.Position.y = Character1.Position.y - 200;
					Zero_JNVectorLeft.push_back(JN3);
				}
			}

			//L …¡œ÷
			else if (Zero_Event.key.keysym.sym == SDLK_l) {
				if (Character1.Status % 2 == 1) {
					Character1.Position.x += 300;
					JN7.Position.x = Character1.Position.x -190;
					JN7.Position.y = Character1.Position.y + 70;
					Zero_JNVectorRight.push_back(JN7);
				}
				else {
					Character1.Position.x -= 300;
					JN7.Position.x = Character1.Position.x + 350;
					JN7.Position.y = Character1.Position.y + 80;
					Zero_JNVectorLeft.push_back(JN7);
				}
			}

			//–°º¸≈Ã◊Û
			else if (Zero_Event.key.keysym.sym == SDLK_LEFT) {
				if (Character2.TimerMoveLeft == NULL) {
					Character2.Status = 2;
					Character2.MoveLeft.PresentNumber = 0;
					Character2.TimerMoveLeft = SDL_AddTimer(200, MoveLeft2, NULL);
				}
			}

			//–°º¸≈Ã”“
			else if (Zero_Event.key.keysym.sym == SDLK_RIGHT) {
				if (Character2.TimerMoveRight == NULL) {
					Character2.Status = 3;
					Character2.MoveRight.PresentNumber = 0;
					Character2.TimerMoveRight = SDL_AddTimer(200, MoveRight2, NULL);
				}
			}

			//1∆’Õ®π•ª˜
			else if (Zero_Event.key.keysym.sym == SDLK_KP_1) {
				if (Character2.Status == 0 || Character2.Status == 2)
					Character2.Status = 4;
				else if (Character2.Status == 1 || Character2.Status == 3)
					Character2.Status = 5;
			}

			//2«‡¡˙
			else if (Zero_Event.key.keysym.sym == SDLK_KP_2) {
				if (Character2.Status % 2 == 1) {
					JN4.Position.x = Character2.Position.x + 300;
					JN4.Position.y = Character2.Position.y + abs(Character2.Position.h - JN4.Position.h) - 20;
					JN4.Speed = 30;
					Zero_JNVectorRight.push_back(JN4);
					//std::cout << "1" << std::endl;
				}
				else {
					JN4.Position.x = Character2.Position.x + 30;
					JN4.Position.y = Character2.Position.y + abs(Character2.Position.h - JN4.Position.h) - 20;
					JN4.Speed = -30;
					Zero_JNVectorLeft.push_back(JN4);
					//std::cout << "2" << std::endl;
				}
			}

			//5¥Û’–
			else if (Zero_Event.key.keysym.sym == SDLK_KP_5) {
				if (Character1.Status % 2 == 1) {
					JN6.Position.x = Character2.Position.x + 400;
					JN6.Position.y = Character2.Position.y - 350;
					Zero_JNVectorRight.push_back(JN6);
				}
				else {
					JN6.Position.x = Character2.Position.x - 800;
					JN6.Position.y = Character2.Position.y - 350;
					Zero_JNVectorLeft.push_back(JN6);
				}
			}

		}

		if (Zero_Event.type == SDL_KEYUP) {
			//A
			if (Zero_Event.key.keysym.sym == SDLK_a) {
				if (Character1.TimerMoveLeft != NULL) {
					Character1.Status = 0;
					Character1.WaitLeft.PresentNumber = 0;
					SDL_RemoveTimer(Character1.TimerMoveLeft);
					Character1.TimerMoveLeft = NULL;
				}
			}

			//D
			if (Zero_Event.key.keysym.sym == SDLK_d) {
				if (Character1.TimerMoveRight != NULL) {
					Character1.Status = 1;
					Character1.WaitRight.PresentNumber = 0;
					SDL_RemoveTimer(Character1.TimerMoveRight);
					Character1.TimerMoveRight = NULL;
				}

			}

			if (Zero_Event.key.keysym.sym == SDLK_LEFT) {
				if (Character2.TimerMoveLeft != NULL) {
					Character2.Status = 0;
					Character2.WaitLeft.PresentNumber = 0;
					SDL_RemoveTimer(Character2.TimerMoveLeft);
					Character2.TimerMoveLeft = NULL;
				}
			}

			if (Zero_Event.key.keysym.sym == SDLK_RIGHT) {
				if (Character2.TimerMoveRight != NULL) {
					Character2.Status = 1;
					Character2.WaitRight.PresentNumber = 0;
					SDL_RemoveTimer(Character2.TimerMoveRight);
					Character2.TimerMoveRight = NULL;
				}
			}
		}

	}
}


bool Zero_IsCollision(SDL_Rect rec_less, SDL_Rect rec_more) {
	if (rec_less.y <= rec_more.y + rec_more.h && rec_less.y >= rec_more.y) {
		if (rec_less.x <= rec_more.x + rec_more.w && rec_less.x >= rec_more.x) return true;
		if (rec_less.x + rec_less.w <= rec_more.x + rec_more.w && rec_less.x + rec_less.w >= rec_more.x) return true;
	}
	else if (rec_less.y + rec_less.h <= rec_more.y + rec_more.h && rec_less.y + rec_less.h >= rec_more.y) {
		if (rec_less.x <= rec_more.x + rec_more.w && rec_less.x >= rec_more.x) return true;
		if (rec_less.x + rec_less.w <= rec_more.x + rec_more.w && rec_less.x + rec_less.w >= rec_more.x) return true;
	}
	return false;
}