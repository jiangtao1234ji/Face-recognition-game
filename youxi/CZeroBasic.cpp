#include"CZerolib.h"

unsigned GameWindowWidth = 1500;//窗口宽度
unsigned GameWindowHeight = 700;//窗口高度
SDL_Window* GameWindow = NULL;
SDL_Renderer* GameRenderer = NULL;
SDL_Event Zero_Event;
bool Zero_GameQuit = false;

//Basic
std::vector<Zero_Collision> CollisionVector1;
std::vector<Zero_Collision> CollisionVector2;
std::vector<Zero_JN> Zero_JNVectorLeft;
std::vector<Zero_JN> Zero_JNVectorRight;
Zero_Texture Buff11;
Zero_Texture Buff12;
Zero_Texture Buff21;
Zero_Texture Buff22;
//Load
Zero_Texture GameMap;
//Character
Zero_Character Character1;
Zero_Character Character2;
//Test
Zero_Texture Test;

//JN
Zero_JN JN1;
Zero_JN JN2;
Zero_JN JN3;
Zero_JN JN4;
Zero_JN JN5;
Zero_JN JN6;
Zero_JN JN7;


//初始化SDL2.0和窗口
void Zero_InitializationWindow() {
	SDL_Init(SDL_INIT_EVERYTHING);
	GameWindow = SDL_CreateWindow("Fighter",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		GameWindowWidth, GameWindowHeight,
		SDL_WINDOW_SHOWN| SDL_WINDOW_RESIZABLE);
	GameRenderer = SDL_CreateRenderer(GameWindow, -1,
		SDL_RENDERER_ACCELERATED 
		//|	SDL_RENDERER_PRESENTVSYNC
	);
}
//创建一块纹理
Zero_Texture Zero_CreateTexture(const char* PicturePath) {
	SDL_Surface *TemporarySurface = NULL;
	Zero_Texture TemporaryTexture;
	TemporarySurface = IMG_Load(PicturePath);
	TemporaryTexture.Texture = SDL_CreateTextureFromSurface(GameRenderer, TemporarySurface);
	TemporaryTexture.Position.h = TemporarySurface->h;
	TemporaryTexture.Position.w = TemporarySurface->w;
	TemporaryTexture.Position.x = 0;
	TemporaryTexture.Position.y = 0;
	SDL_FreeSurface(TemporarySurface);
	return TemporaryTexture;
}


int FaceStatus1 = 1;
int FaceStatus2 = 1;