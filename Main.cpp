
#include "DxLib.h"

#include "GameMain.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdline, int CmdShow){

	ChangeWindowMode(TRUE);
	SetGraphMode(450, 600, 16);

	if (DxLib_Init() == -1){//DX���C�u��������������
		return -1;//�G���[���N�����炽�����ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	GameMain gameMain;

	gameMain.mainLoop();

	DxLib_End();//Dx���C�u�����̎g�p�̏I������

	return 0;
}

