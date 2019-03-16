#pragma once
//#pragma warning(disable:4996)

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_thread.h>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

//#include<ctime>
//#include<Windows.h>
//#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")//去除CMD窗口





extern unsigned GameWindowWidth;//窗口宽度
extern unsigned GameWindowHeight;//窗口高度

extern SDL_Window* GameWindow;
extern SDL_Renderer* GameRenderer;
extern SDL_Event Zero_Event;
extern bool Zero_GameQuit;

//Texture类 包含纹理和位置
struct Zero_Texture {
	SDL_Texture* Texture;
	SDL_Rect Position;
};
//动画类
struct Zero_Animations {
	int MaxNumber;
	int PresentNumber;
	int Spend;
	SDL_Rect Position;
	std::vector<Zero_Texture> Frame;
};


//碰撞类
struct Zero_Collision {
	int ID;
	int MaxNumber;
	int PresentNumber;
	int Spend;
	SDL_Rect Position;
};
extern std::vector<Zero_Collision> CollisionVector1;
extern std::vector<Zero_Collision> CollisionVector2;


//人物类
struct Zero_Character {
	int HP=100;
	int MP=100;
	int Power=0;
	int Status = 0;
	int Speed = 0;
	SDL_Rect Position;
//	SDL_Rect PositionB;
	Zero_Animations WaitLeft;
	Zero_Animations WaitRight;
	Zero_Animations MoveLeft;
	Zero_Animations MoveRight;
	Zero_Animations AttactLeft;
	Zero_Animations AttactRight;
	Zero_Animations HitRecoverLeft;
	Zero_Animations HitRecoverRight;
	std::vector<Zero_Animations> Action;

	SDL_TimerID TimerChangeCharacter = NULL;
	SDL_TimerID TimerWaitLeft = NULL;
	SDL_TimerID TimerWaitRight = NULL;
	SDL_TimerID TimerMoveLeft = NULL;
	SDL_TimerID TimerMoveRight = NULL;
	SDL_TimerID TimerAttactLeft = NULL;
	SDL_TimerID TimerAttactRight = NULL;
	SDL_TimerID TimerHitRecoverLeft = NULL;
	SDL_TimerID TimerHitRecoverRight = NULL;
};
extern Zero_Character Character1;
extern Zero_Character Character2;

//技能类
struct Zero_JN {
	int MaxNumber;
	int PresentNumber;
	int Speed;
	int Number;
	SDL_Rect Position;
	Zero_Animations Left;
	Zero_Animations Right;
};
extern Zero_JN JN1;
extern Zero_JN JN2;;
extern Zero_JN JN3;
extern Zero_JN JN4;
extern Zero_JN JN5;
extern Zero_JN JN6;
extern Zero_JN JN7;


extern std::vector<Zero_JN> Zero_JNVectorLeft;
extern std::vector<Zero_JN> Zero_JNVectorRight;





//Basic
void Zero_InitializationWindow();
Zero_Texture Zero_CreateTexture(const char* PicturePath);
extern Zero_Texture Buff11;
extern Zero_Texture Buff12;
extern Zero_Texture Buff21;
extern Zero_Texture Buff22;

//Face
int FaceThread(void *);
/*
extern cv::VideoCapture cap;
extern frontal_face_detector detector;
extern shape_predictor pose_model;
extern cv::Ptr<SVM> svm;
*/
//Event
void Zero_GameEvent();
bool Zero_IsCollision(SDL_Rect rec_less, SDL_Rect rec_more);

//Load
extern Zero_Texture GameMap;
void Zero_GameLoad();
void Zero_LoadMap();
void Zero_LoadCharacter1();
void Zero_LoadCharacter2();
void Zero_LoadJN();
void Zero_LoadBuff();

//Draw
void Zero_GameDraw();
void Zero_DrawMap();
void Zero_DrawCharacter1();
void Zero_DrawCharacter2();
void Zero_DrawJN();
void Zero_DrawBuff();


//Times
extern SDL_TimerID ChangeCharacter;
extern SDL_TimerID ChangeJN;
extern SDL_TimerID Jump1;
extern SDL_TimerID Face;

Uint32 CallBack1(Uint32 interval, void *param);
Uint32 MoveLeft1(Uint32 interval, void *param);
Uint32 MoveRight1(Uint32 interval, void *param);
Uint32 MoveLeft2(Uint32 interval, void *param);
Uint32 MoveRight2(Uint32 interval, void *param);
Uint32 CallJN(Uint32 interval, void *param);
Uint32 CallJump1(Uint32 interval, void *param);
Uint32 CallFace(Uint32 interval, void *param);

//Test
extern Zero_Texture Test;
extern int FaceStatus1;
extern int FaceStatus2;