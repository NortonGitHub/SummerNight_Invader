#pragma once
#include <random>
#include "DxLib.h"
#include "EnemyBase.h"
#include <math.h>
#include <iostream>
#define PI 3.141592654f

class IrreEnemy1 : public EnemyBase
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

	bool _bullet;
	int _HP;
	int _wave;

	bool flashFlag;	//�摜�_�Ńt���O
	int fForFlash;

	int explosion;	//"��������"�Ƃ����t���O
	int ExpHandle[ExplosionHandle];	//�����O���p�n���h��
	int E_Num;		//�����O������p

public:
	IrreEnemy1();
	IrreEnemy1(int hiswave);
	~IrreEnemy1();
	void update();
	void draw();
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

