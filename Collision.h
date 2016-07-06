#pragma once
#include "DxLib.h"
#include "WeaponBase.h"

#include "EnemyBase.h"//���̕ӂ͏����ς�����悤�Ȃ̂Ō�ŕύX���܂�
//#include "StageManager.h"
//#include "Player.h"
//#include "ConfigureStage.h"
#include "EnemiesBullet.h"
#include "GameOver.h"

#include <vector>

class Collision{
private:
	enum weaponType{
		Singly,
		Quick,
		Jet
	}weapon;//weapon�ɕϐ��������Ă���̂��H

	bool Hitflag;//�������Ă邩�ǂ����̃t���O
	bool Deadflag;//���񂾂��ǂ���
	bool Killflag;//�����蔻�肪�o�����Ă��邩�ǂ����̃t���O �K�v��?

	std::vector<int> HanabiHandle;//�ԉ΂̃A�j���[�V��������
	std::vector<int> EnemyHandle;//�G�̃A�j���[�V��������
	std::vector<int> FireHandle;//(�ł��グ�r����)�ԉ΁B�����������炢��Ȃ�����
	std::vector<int> BossHandle;//�{�X
	std::vector<int> PlayerHandle;
	int BombHandle[21];//�Z�ڂ̃A�j���[�V�����B�����炭���ʂ̔z��ɂȂ�

//	int _x;
//	int _y;//���@�̒��S�_
	const int _r;//���a
	int _sizeX;
	int _sizeY;//�T�C�Y
	int _moveX;
	int _moveY;//�ړ�����flag
//	double _Enemyx;
//	double _Enemyy;
	int _Enemyr;//���W�A���a
	int _Enemysizex;
	int _Enemysizey;//�摜�T�C�Y
	const int _DeadLine;
	int _Bossr;
	int _Bosssizex;
	int _Bosssizey;
//	int _Shotx;
//	int _Shoty;
	int _Shotr;//�e�A���̒��S�_�Ɣ��a
//	double _EnemyShotx;
//	double _EnemyShoty;
	double _EnemyShotr;
	int _Bomb;//�Z�ڂ��łĂ��

//	int _PlayerHP;
//	int _EnemyHP;
//	int _ShieldHP;
//	int _BossHP;

	bool Animationchange;//�ԉ΂̃A�j���[�V�����؂�ւ�����
	bool Enemyflag;//�G���o�����Ă��邩�ǂ���
	//bool DeadLine;//�f�b�h���C���z�������ǂ����B����Ȃ�����
	bool Playerflag;//�����������������ǂ����̃t���O
	int frame;//�t���[����
	bool isDead;//�摜�_�ŏ����p
	bool isFlash;

	enum Enemycount{
		NORMAL, 
		SHIELD, 
		BOSS 
	}enemy_n;//�G�̎��
	int _k;
	int _i;//�Z�ڃA�j���[�V�����p
	//int _enemy_n;//enum�̕ϐ��i�[

	int _class;//���I�m�ۗp�A��������

	//enum Enemy{
	//	one,
	//	two,
	//	three
	//}enemy;//�G�̎�ނɍ��킹��1�E�F�[�u���Ƃ̓G���i�[�p
	int gettotal;

public:


	//�T�E���h
	int DeadSE;//�G���S����SE
	int DeadBoss;//�{�X���S��
	void ClackSE();//���S����SE���o��
	void ClackBoss();//Boss

	//�{�X����

	//boss...�{�X�{�̍��W,pBullet...�v���C���[�e���W
//	bool DeadBoss(double bossX, double bossY, double pBulletX, double pBulletY);
	// Boss01�̎G���̂����蔻��
	bool DeadFollowerOf01(double followerX, double followerY, double pBulletX, double pBulletY);

	//�G����

	/*void*/bool DeadEnemy(int _Shotx, int _Shoty, double _Enemyx, double _Enemyy,int *_EnemyHP,int _weapon,int _weaponSt);//�G�摜����
	bool DeadBosses(int _Shotx, int _Shoty, double _Enemyx, double _Enemyy, int *_EnemyHP, int _weapon, int _weaponSt); //�{�X�摜��
	//���ʂƂ��͓G�_�ł��������ȁ[�c�c�H �Z�A�������d�g�݂͉�ǒ�
	//void KillEnemy();//1�E�F�[�u�̓G��S�ł������玟�Ɉڍs


	//���@���
	int damageHandle;//�_���[�W�摜
	bool PlayerDamageFromEnemy(double _playerX,double _playerY,double _enemyX,double _enemyY);//�_���[�W�󂯂����̉摜�؂�ւ�
	bool PlayerDamageFromBullet(double _playerX, double _playerY, double _eShotX, double _eShotY);
	void NoDamage();//���񂾒���̖��G���Ԃ�݂���(�H)�A�������̂�PlayerDamage�̒��ɓ���Ă�����

	//�ԉΊ֘A
	int HanabiA;
	int HanabiB;
	int HanabiC;
	void ClackHanabi();//�ԉ΂�����������r����SE
	void ClackHanabi2();//�ԉ΂��J������

	//�Z�ڗp
	void Bomb();//�Z�ڂ����蔻��

	//�f�b�h���C������
	void DeadLine();//�f�b�h���C�������邩�ǂ����̔���Ƃ��̌�̏���

	//���̑�
	Collision();//�R���X�g���N�^
	~Collision();//�f�X�g���N�^
	void CheckHit();
	void Update();
};