#include "Pause.h"
#include "KeyManager.h"

Pause::Pause(){
	_pauseHandle = LoadGraph("data\\graphics\\pause.png");
	_selectHandle = LoadGraph("data\\graphics\\select_1.png");
	_keyCheck = 0;

	selectBGM = LoadSoundMem("data\\sound\\SE\\ok.wav");
}

void Pause::PauseDraw(){
	DrawGraph(0, 0, _pauseHandle, TRUE);

	switch (_keyCheck){
	case 0:
		DrawGraph(140, 243, _selectHandle, TRUE);
		break;
	case 1:
		DrawGraph(140, 305, _selectHandle, TRUE);
		break;
	case 2:
		DrawGraph(140, 367, _selectHandle, TRUE);
		break;
	}
	//TITLE y=305 BACK y=367 
}

void Pause::selectUpdate(){
	//KeyM->UpdateKeyState();
	if (KeyM->GetInputKeyFrame(KEY_INPUT_UP) % 10 == 1){
		if (_keyCheck != 0){
			_keyCheck--;
		}
		else {
			_keyCheck = 2;
		}
	}
	if (KeyM->GetInputKeyFrame(KEY_INPUT_DOWN) % 10 == 1){
		if (_keyCheck != 2){
			_keyCheck++;
		}
		else{
			_keyCheck = 0;
		}
	}

	

}

int Pause::Select(){
	if (CheckHitKey(KEY_INPUT_Z)){
		PlaySoundMem(selectBGM, DX_PLAYTYPE_NORMAL);
		switch(_keyCheck){
		case 0:
			return 1;
			//リスタート処理
			break;
		case 1:
			return 2;
			//タイトル画面に戻る処理
			break;
		case 2:
			return 3;
			//ゲーム画面に戻る処理
			break;
		}


	}

	return 0;
}

Pause::~Pause(){
	DeleteGraph(_pauseHandle);
	DeleteGraph(_selectHandle);
	DeleteSoundMem(selectBGM);
}