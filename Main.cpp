
#include "DxLib.h"

#include "GameMain.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdline, int CmdShow){

	ChangeWindowMode(TRUE);
	SetGraphMode(450, 600, 16);

	if (DxLib_Init() == -1){//DXライブラリ初期化処理
		return -1;//エラーが起きたらただちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	GameMain gameMain;

	gameMain.mainLoop();

	DxLib_End();//Dxライブラリの使用の終了処理

	return 0;
}

