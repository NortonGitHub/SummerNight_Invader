#include "GameMain.h"
#include "Object_base.h"
#include "Player.h"
#include "MainGame.h"
#include "Title.h"
#include "FpsController.h"

#include "KeyManager.h"


GameMain::GameMain()
{
	screen = MakeScreen(450, 600);
	nowScene = new Title();
}


GameMain::~GameMain()
{
}

void GameMain::mainLoop(){


	FpsController &fps = FpsController::getIns();
	fps.setColor(0xFF, 0xFF, 0xFF);

	while (ProcessMessage() == 0 && closedFlag() != true)
	{
		//KeyM->UpdateKeyState();

		/*if (KeyM->GetInputKeyFrame(KEY_INPUT_ESCAPE) == 1){
			_pauseFlag = !_pauseFlag;
			}*/
		fps.update();						//fps(frames per second) 更新
		/*if (_pauseFlag){
			pause.PauseDraw();
			pause.selectUpdate();
			switch (pause.Select()){
			case 0:
			break;
			case 1:
			break;
			//リスタート
			case 2:
			nextScene = new Title();
			_pauseFlag = !_pauseFlag;
			if (!checkScene())
			break;

			break;

			//タイトル画面

			case 3:
			_pauseFlag = !_pauseFlag;
			break;
			//ゲームに戻る
			}
			}*/

		nextScene = nowScene->update();		//次シーンをupdateの戻り値で決める

		if (!checkScene())					//シーンをチェックし、nullならbreakする
			break;

		SetDrawScreen(screen);				//描画先を裏に
		ClearDrawScreen();

		nowScene->draw();					//現在のシーンを描画

		SetDrawScreen(DX_SCREEN_BACK);		//描画先を表に
		DrawExtendGraph(0, 0, 450, 600, screen, false);


		ScreenFlip();
		ClearDrawScreen();

		fps.wait();
	}
	/*if (CheckHitKey(KEY_INPUT_ESCAPE)){
	break;
	}*/
}

//次のシーンをチェックする関数(fps,キー操作全て更新したうえでの確認)
bool GameMain::checkScene(){

	//前シーンと別シーンになった場合(title ==> MainGame)
	if (!isSameScene()){
		//今までのシーンを削除し、新しいものにする
		delete nowScene;		//ポインタなので消去しておくこと
		nowScene = nextScene;
	}

	//次がnullでなければ続行エラー発生自
	if (nextScene != nullptr)
		return true;

	return false;
}

//今シーンと次シーンが同じかどうかを返す関数
bool GameMain::isSameScene(){

	if (nextScene == nowScene)
		return true;

	return false;
}

bool GameMain::closedFlag(){
	if (KeyM->GetInputKeyFrame(KEY_INPUT_DELETE) == 1)
		return true;
	return false;
}