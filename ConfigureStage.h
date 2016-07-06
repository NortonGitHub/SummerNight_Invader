#pragma once

//�e�X�e�[�W�̓G�Ȃǂ̏����Ǘ�
#include "EnemyBase.h"
#include "WeaponBase.h"
#include "BossBase.h"

#include "DxLib.h"
#include <vector>

#include "LoadStagedata.h"
#include "LoadDatafile.h"

#include "Player.h"

#include "LREnemy1.h"
#include "LREnemy2.h"
#include "LREnemy3.h"
#include "LREnemy4.h"
#include "LREnemy5.h"
#include "LREnemy6.h"
#include "LREnemy7.h"
#include "LREnemy8.h"
#include "IrreEnemy1.h"
#include "IrreEnemy2.h"
#include "IrreEnemy3.h"
#include "IrreEnemy4.h"
#include "IrreEnemy5.h"
#include "SimpleEnemy1.h"

#include "Boss01.h"
#include "BossBullet.h"

class ConfigureStage /*: protected BossBase */
{
private:
	DataLoader* loader = new LoadDatafile();
	std::vector<EnemyBase*> enemys;
	
	int waveT;			//�R���X�g���N�^���Ŏg�p
	int weaponTypeNum;	//0...Singly,1...Quick,2...Jet
	int waveNum;		//���݂̃E�F�[�u�͂�����
	std::vector<int> waveTotal;// [5];		//�Y���E�F�[�u�̓G���o�ꐔ
	int defeatedCount;	//1�E�F�[�u�ɂ�����G���j��

	int explosionSound;	//�������̃T�E���h

	int frame;
	int untilSceneChange;	//�{�X���j����V�[���`�F���W�܂ł̃t���[����
	bool sceneChangeFlag;	//�{�X���j����V�[���`�F���W�܂ł̃t���[���v�����J�n����t���O
	int ToBossSceneFrame;	//�G���X�e�[�W�I������{�X�X�e�[�W�ֈڍs����܂ł̃t���[����
	bool ToBossSceneFlag;	//�{�X�X�e�[�W�ֈڍs���邽�߂̃t���O
	bool ToBossSceneFlag2;	//�G���X�e�[�W�I������{�X�X�e�[�W�ֈڍs����܂ł̃t���[���v�����J�n����t���O


	double _eX;
	double _eY;
	int _eHP;

	double _bX;
	double _bY;
	int _bHP;

	bool deadLineFlag;	//�f�b�h���C�����z�����Ƃ����t���O

	//SinglyWeapon singly;
	//QuickWeapon quick;
	//JetWeapon jet;
	Collision c;

//	EnemiesBulletManager eBM;

	//�e��vector
	std::vector<EnemiesBullet*> e_Bullet;
	std::vector<BossBase*> bosses;
	std::vector<BossBullet*> b_Bullet;
	std::vector<BossBase*> followers;
	
public:
	ConfigureStage();
	ConfigureStage(int stagenum_cs);
	~ConfigureStage();

	void update(double _pX, double _pY, double _sX, double _sY, int _weaponNum, int *_weaponSt, bool *_wasAttacked, int *stagenum_cs);
	void updateForEnemys(double _pX, double _pY, double _sX, double _sY, int _weaponNum, int *_weaponSt, bool *_wasAttacked);	//�ʏ�G��update
	void updateForBosses(double _pX, double _pY, double _sX, double _sY, int _weaponNum, int *_weaponSt, bool *_wasAttacked, int *stagenum_cs);	//�{�X�X�e�[�W��update
	void updateForFollowers(double _pX, double _pY, double _sX, double _sY, int _weaponNum, int *_weaponSt, bool *_wasAttacked);	//�{�X�X�e�[�W�ɏo�Ă���G���G��update

	void draw();
	void drawForEnemys();
	void drawForBosses();
	void drawForFollowers();

	int getWaveNumNow();

	bool getDeadLine();
};

