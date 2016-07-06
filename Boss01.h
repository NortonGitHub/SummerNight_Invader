#pragma once
#include <vector>
#include <random>
#include "BossBase.h"
#include "FollowerEnemy01.h"
#include "DxLib.h"

class Boss01 : public BossBase
{
private:
#define FrameForFlash 60
#define ExplosionHandle 10
	double x;
	double y;
	int f; //�t���[�����v�Z�p
	int s;
	int count;
	int check;
	int rota; //�{�X�摜��]�p
	bool LR_Flag;//���E����p
	int dx, dy;//1�t���[���ł̈ړ���
	int width, height;//��ʂ̉����Əc��
	int handle[9];//�{�X�摜
	int ohandle[5];//�I�v�V�����摜
	int thandle;//�e�摜
	int hp;

	void setFlashFlag(bool _flash);	//�_�Ńt���O�𓾂�
	bool getHasFlashed();			//�_�ł��I�����t���O��Ԃ�
	void setExplosionFlag(int _exp);	//�����t���O��Ԃ�
	int getExplosionFlag();		//�����t���O�𓾂�

	bool flashFlag;	//�摜�_�Ńt���O
	int fForFlash;

	int explosion;	//"��������"�Ƃ����t���O
	int ExpHandle[ExplosionHandle];	//�����O���p�n���h��
	int E_Num;		//�����O������p

	double _followerX[5];	//�{�X���ӂ̓G��X���W�i�[�p
	double _followerY[5];	//�{�X���ӂ̓G��Y���W�i�[�p

	struct{
		double x;
		double y;
	}explosionCoord[10];
	static int explosionNumber;	//�������鏇�ԁB�����l��0�A�ŏI�l��10�D

public:


	Boss01();
	~Boss01();

	void update();
	void draw();

	void bossItself();
	void updateForExplosion();

	void drawExplosion();
	
	double getX();
	double getY();
	void setHP(int _hp);
	int getHP();

	void setBossCoord(double _x, double _y){};
};
