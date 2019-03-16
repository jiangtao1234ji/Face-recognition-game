#include"CZerolib.h"

void Zero_GameLoad() {
	Zero_LoadMap();
	Zero_LoadBuff();
	Zero_LoadCharacter1();
	Zero_LoadCharacter2();
	Zero_LoadJN();
}

void Zero_LoadMap() {
	GameMap = Zero_CreateTexture(".\\resource\\map\\marry.jpg");
	GameMap.Position.x = 0;
	GameMap.Position.y = 0;
}

void Zero_LoadCharacter1() {
	
	Character1.HP = 100;
	Character1.MP = 100;
	Character1.Power = 0;
	Character1.Speed = 30;
	Character1.Status = 0;
	Character1.Position.x = 1000;
	Character1.Position.y = 250;
	Character1.Position.w = 1.2*419;
	Character1.Position.h = 1.2*245;
	
	
	Character1.WaitLeft.MaxNumber = 4;
	Character1.WaitLeft.PresentNumber = 0;
	Character1.WaitLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\1\\wait_1.png"));
	Character1.WaitLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\1\\wait_2.png"));
	Character1.WaitLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\1\\wait_3.png"));
	Character1.WaitLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\1\\wait_4.png"));

	Character1.WaitRight.MaxNumber = 4;
	Character1.WaitRight.PresentNumber = 0;
	for (int i = 0; i < 4; i++) {
		std::string Z;
		Z = ".\\resource\\character\\1\\fwait_" + std::to_string(i + 1) + ".png";
		Character1.WaitRight.Frame.push_back(Zero_CreateTexture(Z.data()));
	}


	Character1.MoveLeft.MaxNumber = 4;
	Character1.MoveLeft.PresentNumber = 0;
	Character1.MoveLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\1\\walk_1.png"));
	Character1.MoveLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\1\\walk_2.png"));
	Character1.MoveLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\1\\walk_3.png"));
	Character1.MoveLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\1\\walk_4.png"));

	Character1.MoveRight.MaxNumber = 4;
	Character1.MoveRight.PresentNumber = 0;
	for (int i = 0; i < 4; i++) {
		std::string Z;
		Z = ".\\resource\\character\\1\\fwalk_" + std::to_string(i + 1) + ".png";
		Character1.MoveRight.Frame.push_back(Zero_CreateTexture(Z.data()));
	}

	Character1.AttactLeft.MaxNumber = 5;
	Character1.AttactLeft.PresentNumber = 0;
	Character1.AttactLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\1\\attack_1.png"));
	Character1.AttactLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\1\\attack_2.png"));
	Character1.AttactLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\1\\attack_3.png"));
	Character1.AttactLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\1\\attack_4.png"));
	Character1.AttactLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\1\\attack_5.png"));

	Character1.AttactRight.MaxNumber = 5;
	Character1.AttactRight.PresentNumber = 0;
	for (int i = 0; i < 5; i++) {
		std::string Z;
		Z = ".\\resource\\character\\1\\fattack_" + std::to_string(i + 1) + ".png";
		Character1.AttactRight.Frame.push_back(Zero_CreateTexture(Z.data()));
	}

	Character1.HitRecoverLeft.MaxNumber = 4;
	Character1.HitRecoverLeft.PresentNumber = 0;
	for (int i = 0; i < 4; i++) {
		std::string Z;
		Z = ".\\resource\\character\\1\\resist_" + std::to_string(i + 1) + ".png";
		Character1.HitRecoverLeft.Frame.push_back(Zero_CreateTexture(Z.data()));
	}

	Character1.HitRecoverRight.MaxNumber = 4;
	Character1.HitRecoverRight.PresentNumber = 0;
	for (int i = 0; i < 4; i++) {
		std::string Z;
		Z = ".\\resource\\character\\1\\fresist_" + std::to_string(i + 1) + ".png";
		Character1.HitRecoverRight.Frame.push_back(Zero_CreateTexture(Z.data()));
	}
	
	//push_back
	/*
	Character1.Action.push_back(Character1.WaitLeft);
	Character1.Action.push_back(Character1.WaitRight);
	Character1.Action.push_back(Character1.MoveLeft);
	Character1.Action.push_back(Character1.MoveRight);
	Character1.Action.push_back(Character1.AttactLeft);
	Character1.Action.push_back(Character1.AttactRight);
	Character1.Action.push_back(Character1.HitRecoverLeft);
	Character1.Action.push_back(Character1.HitRecoverRight);
	*/
	std::cout << "Character1载入完成" << std::endl;
	std::cout << Character1.Action.size() << std::endl;
}
void Zero_LoadCharacter2() {
	Character2.HP = 100;
	Character2.MP = 100;
	Character2.Power = 0;
	Character2.Speed = 30;
	Character2.Status = 1;
	Character2.Position.x = 0;
	Character2.Position.y = 250;
	Character2.Position.w = 1.2 * 419;
	Character2.Position.h = 1.2 * 245;


	Character2.WaitLeft.MaxNumber = 4;
	Character2.WaitLeft.PresentNumber = 0;
	Character2.WaitLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\2\\wait_1.png"));
	Character2.WaitLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\2\\wait_2.png"));
	Character2.WaitLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\2\\wait_3.png"));
	Character2.WaitLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\2\\wait_4.png"));

	Character2.WaitRight.MaxNumber = 4;
	Character2.WaitRight.PresentNumber = 0;
	for (int i = 0; i < 4; i++) {
		std::string Z;
		Z = ".\\resource\\character\\2\\fwait_" + std::to_string(i + 1) + ".png";
		Character2.WaitRight.Frame.push_back(Zero_CreateTexture(Z.data()));
	}


	Character2.MoveLeft.MaxNumber = 4;
	Character2.MoveLeft.PresentNumber = 0;
	Character2.MoveLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\2\\walk_1.png"));
	Character2.MoveLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\2\\walk_2.png"));
	Character2.MoveLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\2\\walk_3.png"));
	Character2.MoveLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\2\\walk_4.png"));

	Character2.MoveRight.MaxNumber = 4;
	Character2.MoveRight.PresentNumber = 0;
	for (int i = 0; i < 4; i++) {
		std::string Z;
		Z = ".\\resource\\character\\2\\fwalk_" + std::to_string(i + 1) + ".png";
		Character2.MoveRight.Frame.push_back(Zero_CreateTexture(Z.data()));
	}

	Character2.AttactLeft.MaxNumber = 5;
	Character2.AttactLeft.PresentNumber = 0;
	Character2.AttactLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\2\\attack_1.png"));
	Character2.AttactLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\2\\attack_2.png"));
	Character2.AttactLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\2\\attack_3.png"));
	Character2.AttactLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\2\\attack_4.png"));
	Character2.AttactLeft.Frame.push_back(Zero_CreateTexture(".\\resource\\character\\2\\attack_5.png"));

	Character2.AttactRight.MaxNumber = 5;
	Character2.AttactRight.PresentNumber = 0;
	for (int i = 0; i < 5; i++) {
		std::string Z;
		Z = ".\\resource\\character\\2\\fattack_" + std::to_string(i + 1) + ".png";
		Character2.AttactRight.Frame.push_back(Zero_CreateTexture(Z.data()));
	}

	Character2.HitRecoverLeft.MaxNumber = 4;
	Character2.HitRecoverLeft.PresentNumber = 0;
	for (int i = 0; i < 4; i++) {
		std::string Z;
		Z = ".\\resource\\character\\2\\resist_" + std::to_string(i + 1) + ".png";
		Character2.HitRecoverLeft.Frame.push_back(Zero_CreateTexture(Z.data()));
	}

	Character2.HitRecoverRight.MaxNumber = 4;
	Character2.HitRecoverRight.PresentNumber = 0;
	for (int i = 0; i < 4; i++) {
		std::string Z;
		Z = ".\\resource\\character\\2\\fresist_" + std::to_string(i + 1) + ".png";
		Character2.HitRecoverRight.Frame.push_back(Zero_CreateTexture(Z.data()));
	}

	//push_back
	/*
	Character2.Action.push_back(Character2.WaitLeft);
	Character2.Action.push_back(Character2.WaitRight);
	Character2.Action.push_back(Character2.MoveLeft);
	Character2.Action.push_back(Character2.MoveRight);
	Character2.Action.push_back(Character2.AttactLeft);
	Character2.Action.push_back(Character2.AttactRight);
	Character2.Action.push_back(Character2.HitRecoverLeft);
	Character2.Action.push_back(Character2.HitRecoverRight);
	*/
	std::cout << "Character2载入完成" << std::endl;
	std::cout << Character2.Action.size() << std::endl;

}

void Zero_LoadJN() {
	//绿旋风
	JN1.MaxNumber = 20;
	JN1.PresentNumber = 0;
	JN1.Number = 3;
	JN1.Position.w = 1.2 * 163;
	JN1.Position.h = 1.2 * 186;
	JN1.Left.Frame.push_back(Zero_CreateTexture(".\\resource\\jn\\1\\0.png"));
	JN1.Left.Frame.push_back(Zero_CreateTexture(".\\resource\\jn\\1\\1.png"));
	JN1.Left.Frame.push_back(Zero_CreateTexture(".\\resource\\jn\\1\\2.png"));
	JN1.Right.Frame.push_back(Zero_CreateTexture(".\\resource\\jn\\1\\0.png"));
	JN1.Right.Frame.push_back(Zero_CreateTexture(".\\resource\\jn\\1\\1.png"));
	JN1.Right.Frame.push_back(Zero_CreateTexture(".\\resource\\jn\\1\\2.png"));

	//竹子
	JN3.MaxNumber = 12;
	JN3.PresentNumber = 0;
	JN3.Number = 13;
	JN3.Speed = 0;
	JN3.Position.w = 1.2*803;
	JN3.Position.h = 1.2*389;
	for (int i = 0; i <= 12; i++) {
		std::string Z;
		Z = ".\\resource\\jn\\3\\" + std::to_string(i) + ".png";
		JN3.Left.Frame.push_back(Zero_CreateTexture(Z.data()));
		JN3.Right.Frame.push_back(Zero_CreateTexture(Z.data()));
	}

	//黄闪现
	JN7.MaxNumber = 6;
	JN7.PresentNumber = 0;
	JN7.Number = 7;
	JN7.Speed = 0;
	JN7.Position.w = 1.2 * 288;
	JN7.Position.h = 1.2 * 182;
	for (int i = 0; i <= 6; i++) {
		std::string Z;
		Z = ".\\resource\\jn\\7\\" + std::to_string(i) + ".png";
		JN7.Left.Frame.push_back(Zero_CreateTexture(Z.data()));
	}
	for (int i = 0; i <= 6; i++) {
		std::string Z;
		Z = ".\\resource\\jn\\7\\f" + std::to_string(i) + ".png";
		JN7.Right.Frame.push_back(Zero_CreateTexture(Z.data()));
	}
	//青龙
	JN4.MaxNumber = 9;
	JN4.PresentNumber = 0;
	JN4.Number = 10;
	JN4.Speed = 0;
	JN4.Position.w = 1.2 * 175;
	JN4.Position.h = 1.2 * 175;
	for (int i = 0; i <= 9; i++) {
		std::string Z;
		Z = ".\\resource\\jn\\4\\ffly_" + std::to_string(i + 1) + ".png";
		JN4.Left.Frame.push_back(Zero_CreateTexture(Z.data()));
		//std::cout << "1" << std::endl;
	}
	for (int i = 0; i <= 9; i++) {
		std::string Z;
		Z = ".\\resource\\jn\\4\\fly_" + std::to_string(i + 1) + ".png";
		JN4.Right.Frame.push_back(Zero_CreateTexture(Z.data()));
		//std::cout << "2" << std::endl;
	}

	//大招
	JN6.MaxNumber = 39;
	JN6.PresentNumber = 0;
	JN6.Number = 40;
	JN6.Speed = 0;
	JN6.Position.w = 1.2 * 947;
	JN6.Position.h = 1.2 * 593;
	for (int i = 0; i <= 39; i++) {
		std::string Z;
		Z = ".\\resource\\jn\\6\\" + std::to_string(i) + ".png";
		JN6.Left.Frame.push_back(Zero_CreateTexture(Z.data()));
		JN6.Right.Frame.push_back(Zero_CreateTexture(Z.data()));
		//std::cout << "1" << std::endl;
	}
}

void Zero_LoadBuff(){
	Buff11 = Zero_CreateTexture(".\\resource\\buff\\1.png");
	Buff11.Position.h /= 2;
	Buff12 = Zero_CreateTexture(".\\resource\\buff\\2.png");
}