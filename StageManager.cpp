#include "StageManager.h"


StageManager::StageManager()
{
	backImage = LoadGraph("data\\graphics\\back1.png");


	_x = 0;
	_y = 0;
	backX = 0;
	backY = 0;

	frame = 0;

	_playerX = 0.0;
	_playerY = 0.0;
	_shotX = 0.0;
	_shotY = 0.0;
	_weaponNum = 0;
	_weaponSt = 4;
	_sceneChange = 0;
	_wasAttacked = false;

	_stagenum_cs = 1;
}


StageManager::~StageManager()
{
	DeleteGraph(backImage);
}

Scene_Base* StageManager::update()
{

	_playerX = player.getX();
	_playerY = player.getY();
	
	player.update(&_shotX, &_shotY, &_weaponNum, &_weaponSt, &_wasAttacked);	//�v���C���[�̍X�V
	configure.update(_playerX, _playerY, _shotX, _shotY, _weaponNum, &_weaponSt, &_wasAttacked,&_stagenum_cs);
	
	return this;

}

void StageManager::draw(){

	DrawGraph(backX,backY,backImage,true);

	player.draw();

	_forCs_d = player.R_weapon();
	configure.draw();

//	DrawString(100,500,"TEST StageManager",GetColor(200,0,200));

}

int StageManager::getSceneChange(){
	if (player.getPlayerLive() || configure.getDeadLine() == true)	//�Q�[���I�[�o�[
		return 1;
	//�X�e�[�W�N���A�̏����������ꂽ�֐��̕Ԃ��l�����������
	else if (_stagenum_cs >= GAME_CLEAR_LIMIT){
		return 2;
	}
	else
		return 0;
}

int	StageManager::getstage(){	//�{�v���W�F�N�g�ł͎g�p���Ȃ�_?
	return _stagenum_cs;
}

int StageManager::getWaveNumNow(){
	return configure.getWaveNumNow();
}

//StageNum::StageNum()
//{
//	_stage = 0;
//}
//
//StageNum::~StageNum()
//{
//
//}
//
//void StageNum::management(int &stage)
//{
//
//	stage = _stage;
//} 
//
//void StageNum::addition()
//{
//	_stage++;
//}