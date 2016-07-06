#include "GameClear.h"
#include "MainGame.h"

GameClear::GameClear()
{
	sceneChangeFlag = false;
	clear_image = LoadGraph("data\\graphics\\summercg_1\\ending.png");
	clear_BGM = LoadSoundMem("data\\sound\\BGM\\ed(1).wav");
}

GameClear::GameClear(int stageNum)
{
    //¡‚Ç‚±‚ðƒNƒŠƒA‚µ‚½‚©‚ð•ÛŽ‚µ‚Ä‚¨‚­
    _stageNum = stageNum;
}


GameClear::~GameClear()
{
	DeleteGraph(clear_image);
	DeleteSoundMem(clear_BGM);
}

void GameClear::draw(){
	//DrawString(0,0,"Clear Screen ",GetColor(0xFF,0xFF,0xFE));
	//DrawString(0, 20, "TEST CODE : 1 => To Title Screen", GetColor(0xFF, 0xFF, 0xFE));
	DrawGraph(0, 0, clear_image, true);
}

Scene_Base* GameClear::update(){
	++frame;
	if (CheckHitKey(KEY_INPUT_Z) == 1){
		sceneChangeFlag = true;
	}

	if (CheckHitKey(KEY_INPUT_Z) != 1){
		if (sceneChangeFlag){
			return new Title();
		}
	}
	if (CheckSoundMem(clear_BGM) == 0){
		PlaySoundMem(clear_BGM, DX_PLAYTYPE_BACK);
	}
	return this;
}
