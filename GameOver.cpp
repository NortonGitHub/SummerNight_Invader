#include "GameOver.h"
#include "Title.h"


GameOver::GameOver()
{
	sceneChangeFlag = false;
	GameOver_BGM = LoadSoundMem("data\\sound\\BGM\\GameOver1.22.wav");
	gameovergraph = LoadGraph("data\\graphics\\summercg_1\\gameover.png");
	PlaySoundMem(GameOver_BGM, DX_PLAYTYPE_BACK);
}


GameOver::~GameOver()
{
	DeleteGraph(gameovergraph);
	DeleteSoundMem(GameOver_BGM);
}

void GameOver::draw(){
//	DrawString(0, 0, "Push Set Key(Z)", GetColor(0xFF, 0xFF, 0xFE));
	DrawGraph(0, 0, gameovergraph, true);
}

Scene_Base* GameOver::update(){

	if (CheckHitKey(KEY_INPUT_Z) == 1){
		sceneChangeFlag = true;
	}

	if (CheckHitKey(KEY_INPUT_Z) != 1){
		if (sceneChangeFlag){
			return new Title();
		}
	}

	frame++;

	if (frame > 1000){
		frame = 0;
	}
	return this;

	

}
