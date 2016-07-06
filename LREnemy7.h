#pragma once
#include <random>
#include <math.h>
#include <iostream>
#include "DxLib.h"
#include "EnemyBase.h"
#define PI 3.141592654f

class LREnemy7 : public EnemyBase
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
	double moveX1;
	bool _bullet;
	int _HP;
	int _wave;
	bool flashFlag;	//�摜�_�Ńt���O
	int fForFlash;

	int explosion;	//"��������"�Ƃ����t���O
	int ExpHandle[ExplosionHandle];	//�����O���p�n���h��
	int E_Num;		//�����O������p
public:
	void update();
	void draw();

	//LREnemy7(int firstposX, int firstposY, int time);
	LREnemy7();
	LREnemy7(int hiswave);
	~LREnemy7();

	int returnWavenum();
	bool returnBulletFlag();
	double returnX();
	double returnY();
	int getEnemyHP();				//�G�̂�HP��Ԃ�
	void setEnemyHP(int _HP);		//�G�̂�HP�𓾂�
	void setFlashFlag(bool _flash);	//�_�Ńt���O�𓾂�
	bool getHasFlashed();			//�_�ł��I�����t���O��Ԃ�
	void setExplosionFlag(int _exp);	//�����t���O��Ԃ�
	int getExplosionFlag();		//�����t���O�𓾂�
};

