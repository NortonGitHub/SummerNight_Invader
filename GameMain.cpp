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
		fps.update();						//fps(frames per second) �X�V
		/*if (_pauseFlag){
			pause.PauseDraw();
			pause.selectUpdate();
			switch (pause.Select()){
			case 0:
			break;
			case 1:
			break;
			//���X�^�[�g
			case 2:
			nextScene = new Title();
			_pauseFlag = !_pauseFlag;
			if (!checkScene())
			break;

			break;

			//�^�C�g�����

			case 3:
			_pauseFlag = !_pauseFlag;
			break;
			//�Q�[���ɖ߂�
			}
			}*/

		nextScene = nowScene->update();		//���V�[����update�̖߂�l�Ō��߂�

		if (!checkScene())					//�V�[�����`�F�b�N���Anull�Ȃ�break����
			break;

		SetDrawScreen(screen);				//�`���𗠂�
		ClearDrawScreen();

		nowScene->draw();					//���݂̃V�[����`��

		SetDrawScreen(DX_SCREEN_BACK);		//�`����\��
		DrawExtendGraph(0, 0, 450, 600, screen, false);


		ScreenFlip();
		ClearDrawScreen();

		fps.wait();
	}
	/*if (CheckHitKey(KEY_INPUT_ESCAPE)){
	break;
	}*/
}

//���̃V�[�����`�F�b�N����֐�(fps,�L�[����S�čX�V���������ł̊m�F)
bool GameMain::checkScene(){

	//�O�V�[���ƕʃV�[���ɂȂ����ꍇ(title ==> MainGame)
	if (!isSameScene()){
		//���܂ł̃V�[�����폜���A�V�������̂ɂ���
		delete nowScene;		//�|�C���^�Ȃ̂ŏ������Ă�������
		nowScene = nextScene;
	}

	//����null�łȂ���Α��s�G���[������
	if (nextScene != nullptr)
		return true;

	return false;
}

//���V�[���Ǝ��V�[�����������ǂ�����Ԃ��֐�
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