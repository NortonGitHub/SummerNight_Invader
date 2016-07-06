#pragma once
#include <math.h>
#include <random>
#include "DxLib.h"
#include <iostream>
#include "DxLib.h"
#include "EnemyBase.h"
#define PI 3.1415926f
class IrreEnemy2 : public EnemyBase
{
private:
	double _x;
	double _y;
	double xs;
	double ys;
	int _time;
	int h;
	double t;
	int Handle;
	int f;
	int i;
	int HandleN[4]; // �摜�i�[�p�n���h��
	bool exist;

	bool change;
	bool change2;
	bool change3;
	double moveX1;
	double moveY1;
	bool _bullet;
	int _HP;
	int _wave;

	int _cnt;	//�e�X�g�p

	bool flashFlag;	//�摜�_�Ńt���O
	int fForFlash;

	int explosion;	//"��������"�Ƃ����t���O
	int ExpHandle[ExplosionHandle];	//�����O���p�n���h��
	int E_Num;		//�����O������p

public:
	void update();
	void draw();

	IrreEnemy2();
	//IrreEnemy2(int firstposX, int firstposY, int time);
	IrreEnemy2(int hiswave, int cnt);
	~IrreEnemy2();

	int returnWavenum();
	bool returnBulletFlag();
	double returnX();				//X���W��Ԃ�
	double returnY();				//Y���W��Ԃ�
	int getEnemyHP();				//�G�̂�HP��Ԃ�
	void setEnemyHP(int _HP);		//�G�̂�HP�𓾂�
	void setFlashFlag(bool _flash);	//�_�Ńt���O�𓾂�
	bool getHasFlashed();			//�_�ł��I�����t���O��Ԃ�
	void setExplosionFlag(int _exp);	//�����t���O��Ԃ�
	int getExplosionFlag();		//�����t���O�𓾂�
};

