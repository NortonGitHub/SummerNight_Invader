#pragma once
#include <random>
#include <math.h>
#include <iostream>
#include "EnemyBase.h"
class LREnemy6 : public EnemyBase
{
private:
	int shotNum;
	double _x;
	double _y;
	double xs;
	double ys;
	int _time;
	int h;
	double t;
	int f;
	int i;
	int HandleN[4]; // �摜�i�[�p�n���h��
	bool change;
	double moveX1;
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
	LREnemy6();
	LREnemy6(/*int firstposX, int firstposY, int time*/int hiswave);
	~LREnemy6();
	void update();
	void draw();
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

