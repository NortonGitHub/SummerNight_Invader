#include "MainGame.h"
#include "GameClear.h"
#include "GameOver.h"
#include "KeyManager.h"


//引数が与えられた場合、その番号からスタート
MainGame::MainGame(int stageNum){
    _stageNum = stageNum;
	ConfigureStage((int)_stageNum);
}

//引数無しの場合は1面から
MainGame::MainGame()
{
	_sceneChange = 0;
	_stageNum = 1;
	ConfigureStage();
	BGM = LoadSoundMem("data\\sound\\BGM\\stage_1.wav");
	BossBGM = LoadSoundMem("data\\sound\\BGM\\BossBattle1.wav");

	PlaySoundMem(BGM, DX_PLAYTYPE_LOOP);
}

MainGame::~MainGame(){
	DeleteSoundMem(BGM);
	DeleteSoundMem(BossBGM);
}


void MainGame::draw(){
	//テストメッセージ
	if (_pauseFlag){
		pause.PauseDraw();
	}
	else{
		DrawString(0, 0, "MAIN GAME ", GetColor(0xFF, 0xFF, 0xFF));
		DrawString(0, 20, "TEST CODE : A + 0 => CLEAR, B + 9 => OVER ", GetColor(0xFF, 0xFF, 0xFF));
		//	DrawFormatString(0, 40, GetColor(0xFF, 0xFF, 0xFF), "STAGE %d", a);

		DrawFormatString(0, 40, GetColor(0xFF, 0xFF, 0xFF), "stageNum: %d", _stageNum);

		stage.draw();
	}

}

Scene_Base* MainGame::update(){
	frame++;


	KeyM->UpdateKeyState();

	if (KeyM->GetInputKeyFrame(KEY_INPUT_ESCAPE) == 1){
		_pauseFlag = !_pauseFlag;
	}
	if (_pauseFlag){
		pause.PauseDraw();
		pause.selectUpdate();
		switch (pause.Select()){
		case 0:
			break;
		case 1:

			return new MainGame();
			_pauseFlag = !_pauseFlag;

			break;
			//リスタート
		case 2:
			return new Title();
			_pauseFlag = !_pauseFlag;

			break;

			//タイトル画面

		case 3:
			_pauseFlag = !_pauseFlag;
			break;
			//ゲームに戻る
		}
	}
	else {

		if (stage.getWaveNumNow() == 4 && CheckSoundMem(BossBGM) == 0){	//ボスステージになった時、BGMを変える
			StopSoundMem(BGM);
			PlaySoundMem(BossBGM,DX_PLAYTYPE_LOOP);
		}
		

		stage.update();//StageManagerへと飛ぶ。

		_sceneChange = stage.getSceneChange();

		if (stage.getSceneChange() == 2 || (CheckHitKey(KEY_INPUT_0) == 1 && CheckHitKey(KEY_INPUT_A) == 1)){
			return new GameClear();    //今どこをクリアしたかの情報を与える
		}
		if (stage.getSceneChange() == 1 || (CheckHitKey(KEY_INPUT_9) == 1 && CheckHitKey(KEY_INPUT_B) == 1)){
			return new GameOver();
		}

	}
	return this;
}
