#include "DxLib.h"
#include "MainGame.h"
#include "Title.h"


Title::Title()
{
	frame = 0;
	titleImage[0] = LoadGraph("data\\graphics\\title_1.png");
	titleImage[1] = LoadGraph("data\\graphics\\title_2_1.png");
	titleImage[2] = LoadGraph("data\\graphics\\title_2_2.png");
	titleImage[3] = LoadGraph("data\\graphics\\title_3_1.png");
	titleImage[4] = LoadGraph("data\\graphics\\title_3_2.png");
	titleImage[5] = LoadGraph("data\\graphics\\title_4.png");
	_selectHandle = LoadGraph("data/graphics/select_1.png");
	_keyCheck = 0;

	_T_changing = 0.0;

	titleBGM = LoadSoundMem("data\\sound\\BGM\\Urayama.wav");
	selectBGM = LoadSoundMem("data\\sound\\SE\\ok.wav");

	PlaySoundMem(titleBGM, DX_PLAYTYPE_LOOP);
	
}


Title::~Title()
{
	DeleteGraph(titleImage[0]);
	DeleteGraph(titleImage[1]);
	DeleteGraph(titleImage[2]);
	DeleteGraph(titleImage[3]);
	DeleteGraph(titleImage[4]);
	DeleteGraph(titleImage[5]);
	DeleteGraph(_selectHandle);

	DeleteSoundMem(titleBGM);
	DeleteSoundMem(selectBGM);
}

void Title::draw(){
	DrawGraph(0, 0, titleImage[0], false);

//	PlaySoundMem(titleBGM, DX_PLAYTYPE_LOOP);
	
	for (int i = 1; i < 6; i++){
		DrawGraph(0, 0, titleImage[i], true);
	}
//	DrawString(0, 0, "TITLE Push Set Key(Z)", GetColor(255, 255, 255));

	switch (_keyCheck % 2){
	case 0:
		DrawGraph(40, 415, _selectHandle, true);
		break;
	case 1:
		DrawGraph(40, 487, _selectHandle, true);
		break;
	}
}

Scene_Base* Title::update(){
	frame++;


	//•ÏX“_
	if (CheckHitKey(KEY_INPUT_UP) == 1 && GetNowCount() - _T_changing > 400){
		_keyCheck++;
		_T_changing = GetNowCount();
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1 && GetNowCount() - _T_changing > 400){
		_keyCheck++;
		_T_changing = GetNowCount();
	}

	if (CheckHitKey(KEY_INPUT_Z) == 1){
		switch (_keyCheck % 2){
		case 0:
			return new MainGame();
			break;
		case 1:
			DxLib_End();
			exit(0);
			break;
		}
	}

	

	

	return this;

}
